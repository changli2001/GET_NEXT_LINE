#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // For open() and O_RDONLY
#include <string.h>
void f()
{
    system("leaks a.out");
}
char	*return_line(char *str)
{
	int		len;
	int		i;
	char	*str1;

	len = 0;
	i = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if(str[len] == '\n')
		len++;
	str1 = malloc((len + 1) * sizeof(char));
	if (!str1)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		str1[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		str1[i++] = '\n';
	str1[i] = '\0';
	return (str1);
}

char	*ft_strjoin(char **s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;
	int		len;
	i = 0;
	j = 0;
	str = NULL;
	if (*s1 != NULL || s2 != NULL)
	{
		len = strlen(*s1) + strlen(s2) + 1;
		str = (char *)malloc(len * sizeof(char));

		if (!str)
			return (NULL);
		while ((*s1)[i])
		{
			str[i] = (*s1)[i];
			i++;
		}
		while (s2[j])
			str[i++] = s2[j++];
		str[i] = '\0';
		free(*s1);
	}
	return (str);
}
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}
char	*ft_strdup(const char *src)
{
	char	*new;
	int		i;
	int		len;

	len = 0;
	while (src[len])
		len++;
	(new = malloc(sizeof(char) * (len + 1)));
	if (!new)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';

	return ( new);
}

void	rest(char **str)
{
	char	*temp;
	char	*rest;
	//int i = 0;

	temp = ft_strchr(*str, '\n');
	if (temp)
	{
		puts("*");
		rest = NULL;
		temp++;
		rest = ft_strdup(temp);
		free(*str);
		*str = NULL;
		*str = rest;
	}
	//exit(1);
	else
	{
		puts("-");
		free(*str);
		*str = NULL;
	}
	//exit(1);
}
char	*read_l(char **str)
{
	char	*line;

	line = NULL;
	if (**str != '\0')
	{
	//	puts("*");
		line = return_line(*str);
		rest(str);
	}
	//printf("[%p]", line);
	return (line);
}

char *get(void)
{
    atexit(f);
    char *tmp;
    char *buff = malloc(10);
    strcpy(buff, "hel\nllo");
    char *str2 = ft_strjoin(&str2, buff);
    buff = read_l(&str2); 
    return(buff);
}
int main()
{
    printf("%s", get());
}

