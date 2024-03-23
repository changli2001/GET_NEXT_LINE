#include "get_next_line.h"
int main()
{
    char *s;
    int fd;
    int i = 0;
    fd = open("file.txt", O_RDONLY);
    while (i < 100)
    {
        s = get_next_line(fd);
        printf("%s", s);
        free(s);
        i++;
    }
    
}