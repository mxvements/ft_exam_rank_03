#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return write(1, &c, 1);
}

void	ft_putstr(char *s, int *size)
{
	int	i = 0;
	if (!s)
	{
		*size += write(1, "(null)", 6);
		return ;
	}
	while (s[i])
	{
		*size += write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_base(long long nbr, int base_len, int *size)
{
	char c;
	char *base = "0123456789abcdef";

	if (nbr < 0)
	{
		nbr *= -1;
		*size += write(1, "-", 1);
	}
	if (nbr >= base_len)
		ft_putnbr_base((nbr / base_len), base_len, size);
	c = base[nbr % base_len];
	*size += write(1, &c, 1);
}

int	ft_converter(va_list ptr, const char *s)
{
	int	i = 0;
	int	size = 0;

	if (s[i] == 'd')
		ft_putnbr_base(va_arg(ptr, int), 10, &size);
	if (s[i] == 'x')
		ft_putnbr_base(va_arg(ptr, unsigned int), 16, &size);
	if (s[i] == 's')
		ft_putstr(va_arg(ptr, char *), &size);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int	i = 0;
	int	size = 0;
	va_list	ptr;

	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			break ;
		if (format[i] == '%')
		{
			i++;
			size += ft_converter(ptr, &format[i]);
		}
		else
			size += ft_putchar(format[i]);
		i++;
	}
	va_end(ptr);
	return (size);
}
/*
int	main(int argc, char **argv)
{
	char	*s = "ft_printf_test:";
	int	len;
	(void)argc;
	
	ft_printf("%s\n", NULL);
	printf("%s\n", (char *)NULL);

	ft_printf("%s\n", s);
	len = ft_printf("%s", argv[1]);
	ft_printf("\nlen: %d", len);
	ft_printf("\nptr: %x", argv[1]);


	return (0);
}*/
