/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochangli <ochangli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 17:36:46 by ochangli          #+#    #+#             */
/*   Updated: 2024/03/24 17:45:16 by ochangli         ###   ########.fr       */
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
			return (1);
		i++;
	}
	return (0);
}

char	*build_s_line(char *str)
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
	new = malloc(i - k + 1);
	if (!new)
		return (free(str), str = NULL, NULL);
	while (str[k] != '\0')
		new[j++] = str[k++];
	new[j] = '\0';
	return (free(str), str = NULL, new);
}

char	*build_v_line(char	*b_s_line, char	*v_line)
{
	char	*rtn_line;
	size_t	v_line_lenght;
	size_t	b_s_line_lenght;
	
	v_line_lenght = str_lenght(v_line);
	b_s_line_lenght = str_lenght(b_s_line);
	rtn_line = malloc(v_line_lenght + b_s_line_lenght + 1);
	if (!rtn_line)
		return (free(v_line), v_line = NULL, NULL);
	if (v_line)
	{
		
		ft_concatinate(rtn_line, v_line, v_line_lenght);
		free(v_line);
		v_line = NULL;
	}
	
	ft_concatinate(rtn_line + v_line_lenght, b_s_line, b_s_line_lenght);
	//printf("[%s]", rtn_line);
	return (rtn_line);
}
