/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <mbarbari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 12:10:29 by mbarbari          #+#    #+#             */
/*   Updated: 2017/01/03 16:43:38 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_insert(char *str, char *val)
{
	char *rslt;

	rslt = str;
	while (val)
		*str++ = *val++;
	return (rslt);
}

char	*ft_ninsert(char *str, int elem, char *val)
{
	char *rslt;

	rslt = str;
	while (elem)
	{
		*str++ = *val++;
		elem--;
	}
	return (rslt);
}

char	**ft_insert_data_tab2d(char **tab, int raw, int type, ...)
{
	char	*str;
	va_list	ap;

	va_start(ap, type);
	while (raw)
	{
		if (type == TYPE_STR)
		{
			str = (char *)va_arg(ap, char *);
			ft_insert(tab[raw], str);
		}
		raw--;
	}
	return (tab);
}
