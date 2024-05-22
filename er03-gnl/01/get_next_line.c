#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
        i++;
    return (i);
}

void    ft_strcpy(char *dst, char *src)
{
    int i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

char    *ft_strdup(char *str)
{
    size_t  len = ft_strlen(str) + 1;
    char    *dst = (char *)malloc((sizeof(char)) * len);

    if (!dst)
        return (NULL);
    ft_strcpy(dst, str);
    return (dst);
}

char    *ft_strchr(char *str, int c)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == (char)c)
            return (str + i);
        i++;
    }
    return (NULL);
}

char    *ft_strjoin(char *s1, char *s2)
{
    const size_t    s1_len = ft_strlen(s1);
    const size_t    s2_len = ft_strlen(s2);
    char            *rslt = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));

    rslt[s1_len + s2_len + 1] = '\0'; //different from example code
    if (!s1 || !s2)
        return (NULL);
    if (!rslt)
        return (NULL);
    ft_strcpy(rslt, s1);
    ft_strcpy((rslt + s1_len), s2);
    free(s1);
    return (rslt);

}

char    *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1];
    char        *line;
    char        *nl_ptr;
    int         read_count;
    int         idx_eoline;

    line = ft_strdup(buf);

    /*  while
        + there is no '\n' on line
        + we read, and the count is > 0
        we join buf with line
    */
    while (!(nl_ptr = ft_strchr(line, '\n')) && (read_count = read(fd, buf, BUFFER_SIZE)))
    {
        buf[read_count] = '\0';
        line = ft_strjoin(line, buf);
    }
    if (ft_strlen(line) == 0)
        return (free(line), NULL);
    
    /*  if there is newline
        + we look the idx in wich we need to split the line
    */
    if (nl_ptr != NULL)
    {
        idx_eoline = nl_ptr - line + 1;
        ft_strcpy(buf, nl_ptr + 1); //dst: buf, we overwrite on buf
    }
    else
    {
        idx_eoline = ft_strlen(line);
        buf[0] = '\0';
    }
    line[idx_eoline] = '\0';
    return (line);
}
