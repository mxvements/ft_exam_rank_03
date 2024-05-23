#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strcpy(char *dst, char *src)
{
	int	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(char *src)
{
	int	len = ft_strlen(src);
	char	*dst = (char *)malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	if (!src)
		return (NULL);
	dst[len] = '\0';
	ft_strcpy(dst, src);
	return (dst);
}

char	*ft_strchr(char *s, char c)
{
	int	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	s1_len = ft_strlen(s1);
	int	s2_len = ft_strlen(s2);
	char	*rslt = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!rslt)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	rslt[s1_len + s2_len] = '\0';
	ft_strcpy(rslt, s1);
	ft_strcpy((rslt + s1_len), s2);
	free(s1);
	return (rslt);
}

char	*get_next_line(int fd)
{
	static char buf[BUFFER_SIZE + 1];
	char *line;
	int	idx_eoline;
	int	read_count;
	char	*nl_ptr;

	line = ft_strdup(buf);
	while (!(nl_ptr = ft_strchr(line, '\n')) && (read_count = read(fd, buf, BUFFER_SIZE)))
	{
		buf[read_count] = '\0';
	       line = ft_strjoin(line, buf); //free line inside	
			
	}
	if (ft_strlen(line) == 0)
		return (free(line), NULL);
	if (nl_ptr != NULL)
	{
		idx_eoline = nl_ptr - line + 1;
		ft_strcpy(buf, nl_ptr + 1);
	}
	else
	{
		idx_eoline = ft_strlen(line);
		buf[0] = '\0';
	}
	line[idx_eoline] = '\0';
	return (line);
}

/*
int	main(int argc, char **argv)
{
	int	fd;
	char 	*line;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		line = get_next_line(fd);
		while (line)
		{
			printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}

	}
	return (0);
}*/
