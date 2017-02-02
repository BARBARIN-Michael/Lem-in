/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 17:40:45 by barbare           #+#    #+#             */
/*   Updated: 2017/01/20 12:16:24 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stream.h>
#include <libft.h>

/*
** ****************************************************************************
** ft_stream_read_full
** INPUT:	Struct stream
** OUTPUT:	Struct stream
** Describe: Read complete stream
** ****************************************************************************
*/

t_stream		ft_stream_read_full(t_stream stream, int flags)
{
	int			len;

	stream = ft_stream_fill(stream);
	len = stream.size - stream.cursor;
	if (len > 0)
	{
		stream.cursor += write(stream.fdout, &stream.buf[stream.cursor], len);
		return (ft_stream_read_full(stream, flags));
	}
	else
		return (stream);
}

/*
** ****************************************************************************
** ft_stream_read
** INPUT:	Struct stream
** OUTPUT:	Struct stream
** Describe: Reads the not exploited buffer
** ****************************************************************************
*/

t_stream		ft_stream_read(t_stream stream, int flags)
{
	stream = ft_stream_fill(stream);
	write(stream.fdout, &stream.buf[stream.cursor],
			stream.size - stream.cursor);
	if (FLAGS(flags, F_MOVE))
	{
		stream.cursor = 0;
		stream.size = 0;
	}
	return (stream);
}

/*
** ****************************************************************************
** ft_stream_read_n
** INPUT:	Struct stream
** OUTPUT:	Struct stream
** Describe: Reads the not exploited buffer size n
** ****************************************************************************
*/

t_stream		ft_stream_read_n(t_stream stream, int n, int flags)
{
	stream = ft_stream_fill(stream);
	if (n >= (stream.size - stream.cursor))
		return (ft_stream_read(stream, flags));
	else
	{
		if (FLAGS(flags, F_MOVE))
			stream.cursor = write(stream.fdout, &stream.buf[stream.cursor], n);
		else
			write(stream.fdout, &stream.buf[stream.cursor], n);
	}
	return (stream);
}

/*
** ****************************************************************************
** ft_stream_read_c
** INPUT:	Struct stream , char character
** OUTPUT:	Struct stream
** Describe: Reads the not exploited buffer until c characters
** ****************************************************************************
*/

t_stream		ft_stream_read_c(t_stream stream, int c, int flags)
{
	char		*ptr;

	stream = ft_stream_fill(stream);
	if ((ptr = ft_strchr(stream.buf, c)) == NULL)
		return (ft_stream_read(stream, flags));
	else
	{
		if (FLAGS(flags, F_MOVE))
			stream.cursor += write(stream.fdout, &stream.buf[stream.cursor],
					ptr - stream.buf);
		else
			write(stream.fdout, &stream.buf[stream.cursor],
					ptr - stream.buf);
	}
	return (stream);
}

/*
** ****************************************************************************
** ft_stream_read_expr
** INPUT:	Struct stream , char character
** OUTPUT:	Struct stream
** Describe: Reads the not exploited buffer until expr
** ****************************************************************************
*/

t_stream		ft_stream_read_expr(t_stream stream, char *str, int flags)
{
	char	*ptr;

	stream = ft_stream_fill(stream);
	if ((ptr = ft_strchr(&stream.buf[stream.cursor], '\r')) == NULL)
	{
		stream.cursor += write(stream.fdout, &stream.buf[stream.cursor],
				ft_strlen(&stream.buf[stream.cursor]));
		return (ft_stream_read_expr(stream, str, flags));
	}
	stream.cursor += write(stream.fdout, &stream.buf[stream.cursor],
			ptr - &stream.buf[stream.cursor]);
	return (stream);
}
