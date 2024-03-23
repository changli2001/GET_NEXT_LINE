#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
#include <limits.h>

int str_lenght(const char *str);
char *build_V_line(char *line , char *to_build);
void ft_concatinate(char *str1 , char *str2 , int len);
int check_n_line(const char *str);
char *build_S_line(char *str);
char *get_next_line(int fd);

#endif

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 42
#endif

