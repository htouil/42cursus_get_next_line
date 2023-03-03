/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 16:57:34 by htouil            #+#    #+#             */
/*   Updated: 2023/02/27 16:57:42 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read(int fd, char *cell)
{
    int     rd;
    char    *buffer;

    buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return (NULL);
    rd = 1;
    while (ft_strchr(cell) == 0 || rd > 0)
    {
        rd = read(fd, buffer, BUFFER_SIZE);
        if (rd == -1)
        {
            free(buffer);
            free(cell);
            cell = NULL;
            break ;
        }
        buffer[rd] = '\0';
        cell = ft_strjoin(cell, buffer);
    }
    //free (buffer);
    return (cell);
}

char    *get_one_line(char *cell)
{
    int     i;
    char    *tmp;

    i = 0;
    while (cell[i] != '\n')
        i++;
    tmp = malloc((i + 2) * sizeof(char));
    if (!tmp)
        return (NULL);
    i = 0;
    while (cell[i] != '\n')
    {
        tmp[i] = cell[i];
        i++;
    }
    tmp[i] = '\n';
    i++;
    tmp[i] = '\0';
    //free(cell);
    return (tmp);
}

char    *get_new_line(char *cell)
{
    int     i;
    int     j;
    char    *new;

    i = 0;
    while (cell[i] != '\n')
        i++;
    i++;
    new = malloc((ft_strlen(cell) - i + 1) * sizeof(char));
    if (!new)
        return(NULL);
    j = 0;
    while (cell[i] != '\0')
    {
        new[j] = cell[i];
        i++;
        j++;
    }
    new[j] = '\0';
    free(cell);
    return(new);
}

char    *get_next_line(int fd)
{
    static char *cell;
    char        *one_line;
    
    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    cell = ft_read(fd, cell);
    if (!cell)
        return (NULL);
    one_line = get_one_line(cell);
    cell = get_new_line(cell);
    return (one_line);
}

int main()
{
    int     fd;
    char    *result;
    fd = open("test.txt", O_RDONLY);
    result = get_next_line(fd);
    printf("%s", result);
    result = get_next_line(fd);
    printf("%s", result);
    // exit(1);
    result = get_next_line(fd);
    printf("%s", result);
    // result = get_next_line(fd);
    // printf("%s", result);
    close(fd);
    return (0);
}
