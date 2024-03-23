/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochangli <ochangli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 07:05:27 by ochangli          #+#    #+#             */
/*   Updated: 2024/03/23 17:35:51 by ochangli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *s_line;
    char *v_line;
    char *buffer;
    size_t readed;
    
    v_line = NULL;

   if(fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX || fd >= OPEN_MAX || read(fd, 0, 0) < 0)
        {
            return(free(s_line), s_line = NULL);
        }
        
   if(s_line)
    {
        v_line = build_V_line(s_line , v_line);
        if(!v_line)
            return(free(s_line), s_line = NULL, NULL);
        
        if(check_n_line(v_line))
        {
            if ((s_line[str_lenght(s_line)]))
            {
                s_line = build_S_line(s_line);
                
                if(!s_line)
                    return(free(v_line), v_line = NULL, NULL);
            return(v_line);
            }
        return(free(s_line), s_line = NULL, v_line); 
        }
    free (s_line);
    s_line = NULL;
    }
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
	  return(free(v_line), v_line = NULL, NULL);
    while ((readed = (read(fd , buffer , BUFFER_SIZE))) > 0)
    {
        buffer[readed] = '\0';
        v_line = build_V_line(buffer , v_line);
        if (!v_line)
            return(free(buffer), free(v_line), buffer = NULL, v_line = NULL, NULL);
        if (check_n_line(v_line))
        {
            if (buffer[str_lenght(buffer)])
            {
                s_line = build_S_line(buffer);
                if(!s_line)
                    return(free(v_line),v_line = NULL, NULL);
                return (v_line);
            }
        return(free(buffer), buffer = NULL, v_line);
        }
    }
    if(readed < 0)
        return(free(v_line), \
            free(buffer),buffer = NULL, v_line = NULL, NULL);
    free(buffer);
    return(v_line);
}
