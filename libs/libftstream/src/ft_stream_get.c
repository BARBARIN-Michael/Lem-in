/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:28:59 by barbare           #+#    #+#             */
/*   Updated: 2017/01/30 19:15:07 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stream.h>
#include <libft.h>
#include <stdio.h>

t_stream		ft_stream_get_protocol(t_stream stream, char *buf, size_t n,
										char *prot)
{
	char	*str;
	size_t	size;

	(void)n;
	buf[0] = '\0';
	stream = ft_stream_fill(stream);
	if ((stream.size - stream.cursor) > 0)
	{
		str = ft_strstr(&stream.buf[stream.cursor], prot);
		if (str)
		{
			size = (str - &stream.buf[stream.cursor]);
			buf = ft_memcpy(buf, &stream.buf[stream.cursor], size);
			buf[size] = '\0';
			stream = ft_move_cursor(stream, size + ft_strlen(prot));
		}
	}
	return (stream);
}

t_stream		ft_stream_get_expr(t_stream stream, char *expr, int flags)
{
	char		*str;

	stream = ft_stream_reset_get(stream);
	stream = ft_stream_fill(stream);
	while ((stream.size - stream.cursor) > 0 &&
			(str = ft_strstr(stream.buf, expr)) == NULL)
	{
		stream.get = ft_strjoin_free(stream.get, &stream.buf[stream.cursor],
							0 | F_FREESRC);
		if (FLAGS(flags, F_MOVE))
			stream.cursor += str - &stream.buf[stream.cursor];
	}
	if ((stream.size - stream.cursor) > 0
			&& (str = ft_strstr(stream.buf, expr)) != NULL)
		stream.get = ft_strnjoin_free(stream.get, &stream.buf[stream.cursor],
				(str - &stream.buf[stream.cursor]), 0 | F_FREESRC);
	else
		stream.get = ft_strjoin_free(stream.get, &stream.buf[stream.cursor],
							0 | F_FREESRC);
	return (stream);
}
