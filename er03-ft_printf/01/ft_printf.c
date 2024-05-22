#include <unistd.h>
#include <stdarg.h>


int    ft_putchar(char c)
{
    return (write(1, &c, 1));
}

void     ft_putstr(char *str, int *size)
{
    int i = -1;

    while(str[++i])
        *size += write(1, &str[i], 1);
}

void ft_putnbr_base(long long nbr, int base_len, int *size)
{
    char    *base = "0123456789abcdef";
    char    c;

    if (nbr < 0)
    {
        nbr *= -1;
        *size = write(1, "-", 1);
    }
    if (nbr >= base_len)
        ft_putnbr_base(nbr/base_len, base_len, size);
    c = base[nbr % base_len];
    *size += write(1, &c, 1);
}

int ft_convertion(char *format, va_list ptr)
{
    int i = 0;
    int size = 0;

    if (format[i] == 'd')
        ft_putnbr_base(va_arg(ptr, int), 10, &size);
    if (format[i] == 's')
        ft_putstr(va_arg(ptr, char*), &size);
    if (format[i] == 'x')
        ft_putnbr_base(va_arg(ptr, unsigned int), 16, &size);
    return (size);
}

int ft_printf(char *format, ...)
{
    int i = 0;
    int size = 0;
    va_list ptr;
    
    va_start(ptr, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1] == '\0')
            break;
        if (format[i] == '%')
        {
            i++;
            size += ft_convertion(&format[i], ptr);

        }
        else
            size += ft_putchar(format[i]);
        i++;
    }
    return (size);
}