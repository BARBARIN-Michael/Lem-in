/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/23 10:16:51 by mbarbari          #+#    #+#             */
/*   Updated: 2017/01/18 10:52:27 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char		*ft_strjoin_free(char *src, char *join, int flags)
{
	char		*str;

	if (!join)
		return (NULL);
	str = malloc(ft_strlen(src) + ft_strlen(join) + 1);
	str[0] = '\0';
	if (src)
		ft_strcpy(str, src);
	ft_strcat(str, join);
	if (src && FLAGS(flags, F_FREESRC))
		free(src);
	if (FLAGS(flags, F_FREEJOIN))
		free(join);
	return (str);
}

char		*ft_strnjoin_free(char *src, char *join, int n, int flags)
{
	char		*str;

	if (!join)
		return (NULL);
	str = malloc(ft_strlen(src) + n + 1);
	str[0] = '\0';
	if (src)
		ft_strcpy(str, src);
	ft_strncat(str, join, n);
	if (src && FLAGS(flags, F_FREESRC))
		free(src);
	if (FLAGS(flags, F_FREEJOIN))
		free(join);
	return (str);
}
