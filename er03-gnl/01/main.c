#include "get_next_line.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    char    *line;
    int     fd;
    (void)argc;

    fd = open(argv[1], O_RDONLY);
    line = get_next_line(fd);
    while(line)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
    }
    return (0);
}