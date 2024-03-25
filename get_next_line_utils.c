/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochangli <ochangli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:36:46 by ochangli          #+#    #+#             */
/*   Updated: 2024/03/25 20:31:02 by ochangli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
int	str_lenght(const char *str)
{
	int	i;
	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}
void	ft_concatinate(char *str1, char *str2, int len)
{
	int	j;
	j = 0;
	while (len)
	{
		str1[j] = str2[j];
	j++;
	len--;
	}
	str1[j] = '\0';
}
int	check_n_line(const char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return(1);
	i++;
	}
	return (0);
}

char	*build_S_line(char *str)
{
	int		j;
    int		k;
	int		i;
	char	*new;
	
	i = 0;
	k = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\n' && k == 0)
	k = i + 1;
	i++;
	}
	new = malloc(i - k +1);
	if (!new)
	{
		if(!str){
            free(str);
			str = NULL;
	}
		return(free(str), str = NULL, NULL);
    }

    while (str[k] != '\0')
        new[j++] = str[k++];
    new[j] = '\0';
    free(str);
    str = NULL;
    return(new);
}

char *build_V_line(char *B_S_line , char *V_line)
{
    char *rtn_line;
    size_t V_line_lenght;
    size_t B_S_line_lenght;

    V_line_lenght = str_lenght(V_line);
    B_S_line_lenght = str_lenght(B_S_line);
    rtn_line = malloc(V_line_lenght + B_S_line_lenght + 1);
    if(!rtn_line)
        return (free(V_line), V_line=NULL, NULL);
    if(V_line)
    {
        ft_concatinate(rtn_line , V_line , V_line_lenght);
            free(V_line);
            V_line = NULL;
    }
    ft_concatinate(rtn_line + V_line_lenght, B_S_line, B_S_line_lenght);
    return(rtn_line);
}
