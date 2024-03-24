#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
#include <stdio.h>
int		str_lenght(const char *str);
char	*build_v_line(char *b_s_line, char *v_line);
void	ft_concatinate(char *str1, char *str2, int len);
int		check_n_line(const char *str);
char	*build_s_line(char *str);
char	*get_next_line(int fd);
char *building(char **s_line, char **v_line);
#endif

#ifndef BUFFER_SIZE
    #define BUFFER_SIZE 1
#endif

