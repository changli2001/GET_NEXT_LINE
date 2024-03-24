/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochangli <ochangli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 07:05:27 by ochangli          #+#    #+#             */
/*   Updated: 2024/03/24 17:44:33 by ochangli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char *add_to_v_line(char **v_line, char **s_line)
{
    
    *v_line = build_v_line(*s_line, *v_line);
    if(!*v_line)
        return(NULL);
        
    if (check_n_line(*v_line))
    {
        if (*s_line[str_lenght(*s_line)])
        {
            *s_line = build_s_line(*s_line);
             if(!*s_line)
                return(free(*v_line), *v_line = NULL, NULL);
        }
    return(*v_line);
    }

return(free(*s_line),*s_line = NULL, *v_line);        
}
char *read_to_buffer(int fd, char **v_line, char **s_line)
{
    char    *buffer;
    ssize_t readed;
   
    buffer = malloc(BUFFER_SIZE + 1);
    if(!buffer)
        return (NULL);
    readed = read(fd, buffer, BUFFER_SIZE);
    while (readed > 0)
    {
         *v_line = build_v_line(buffer, *v_line);
        buffer[readed] = '\0';
        if (check_n_line(buffer))
        {
            if (!*v_line)
                return(free(buffer), buffer = NULL, NULL);
            if (buffer[readed])
            {
                *s_line = build_s_line(buffer);
                if(!*s_line)
                    return(free(buffer), free(*v_line), *v_line = NULL, buffer = NULL, NULL);
            }
        
        return(free(buffer), buffer = NULL, *v_line);
        }
    readed = read(fd, buffer, BUFFER_SIZE);
    }
    if(readed < 0)
        return(free(buffer), free(*v_line), buffer = NULL, *v_line = NULL, NULL);   
     
    return(free(buffer), buffer = NULL, *v_line);
}
char *get_next_line(fd)
{
    static char *s_line;
    char        *v_line;

    v_line = NULL;
    if(fd < 0 || fd > OPEN_MAX || BUFFER_SIZE >= INT_MAX || BUFFER_SIZE <= 0)
    {
        if(s_line)
            return(free(s_line), s_line = NULL, NULL);
    }
    if (s_line)
    {
        v_line = add_to_v_line(&v_line, &s_line);
        if(!v_line)
            return(NULL);
    }
    if(v_line)
        return(v_line);
    
    v_line = read_to_buffer(fd, &v_line, &s_line);
    if(!v_line)
        return(NULL);
    return (v_line);
}


