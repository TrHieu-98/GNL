#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int    main(void)
{
    char *line;
    char *name = "empty.txt";
    int fd = open(name, O_RDONLY);
    line = get_next_line(fd);
    printf("%s\n", line);
    printf("before free\n");
    free(line);
    printf("after free\n");
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
    close(fd);
    fd = open(name, O_RDONLY);
    line = get_next_line(fd);
    printf("%s\n", line);
    free(line);
    return (0);
}