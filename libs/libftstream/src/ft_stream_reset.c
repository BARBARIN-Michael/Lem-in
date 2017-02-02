/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:58:15 by barbare           #+#    #+#             */
/*   Updated: 2017/01/18 16:53:37 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stream.h"
#include "libft.h"
#include <stdlib.h>

/*
** ****************************************************************************
** ft_stream_reset_get
** INPUT:	Struct stream
** OUTPUT:	Struct stream
** Describe: reset get stream
** ****************************************************************************
*/

t_stream		ft_stream_reset_get(t_stream stream)
{
	if (stream.get != NULL)
		free(stream.get);
	stream.get = NULL;
	return (stream);
}

t_stream		ft_stream_reset_buffer(t_stream stream)
{
	stream = ft_stream_reset_get(stream);
	stream.cursor = 0;
	stream.size = 0;
	stream.buf[0] = '\0';
	return (stream);
}

t_stream		ft_stream_filter(t_stream stream,
		void (*fct)(int *cursor, char *buf, int mod), int flags)
{
	int		i;

	i = stream.cursor - 1;
	if (FLAGS(flags, F_START))
		while (++i < (stream.size - stream.cursor))
			fct(&stream.cursor, &stream.buf[i], +1);
	i = stream.size + 1;
	if (FLAGS(flags, F_END))
		while (--i < (stream.size - stream.cursor))
			fct(&stream.size, &stream.buf[i], -1);
	return (stream);
}
