/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htouil <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:02:45 by htouil            #+#    #+#             */
/*   Updated: 2023/02/27 22:02:51 by htouil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;
    if (!str)
        return 0;

    i = 0;
    while (str[i] != '\0')
        i++;
    return (i);
}

char    *ft_strjoin(char *str1, char *str2)
{
    int     i;
    int     j;
    char    *joined;

    joined = malloc((ft_strlen(str1) + ft_strlen(str2) + 1) * sizeof(char));
    if (!joined)
        return (NULL);
    i = 0;
    j = 0;
    while (i < ft_strlen(str1))
    {
        joined[i] = str1[i];
        i++;
    }
    while (j < ft_strlen(str2))
    {
        joined[i] = str2[j];
        i++;
        j++;
    }
    joined[i] = '\0';
    return (joined);
}

int ft_strchr(char *searched)
{
    int i;

    if (!searched)
        return (0);
    i = 0;
    while(searched[i] != '\0')
    {
        if (searched[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}
