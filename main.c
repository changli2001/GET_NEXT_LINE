#include "get_next_line.h"
int main()
{
    char *s;
    int fd;
    int i = 0;
    fd = open("file.txt", O_RDONLY);
    while (i < 20)
    {
        s = get_next_line(fd);
        printf("%s", s);
        if(i == 2)
            close (fd);
        free(s);
        i++;
    }
    
}