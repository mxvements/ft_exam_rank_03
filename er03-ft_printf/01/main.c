int ft_printf(char *format, ...);

//cc -Wall -Wextra -Werror main.c ft_printf.c -o ft_printf
int main(int argc, char **argv)
{
    int        len = 0;
    char    *s = "ft_printf test: ";
    if (argc == 2)
    {
        ft_printf("%s\n", s);
        len = ft_printf(argv[1]);
        ft_printf("\n\tstr len: %d\n", len);
        ft_printf("\tstr ptr: %x\n", argv[1]);
    }
    return (0);
}