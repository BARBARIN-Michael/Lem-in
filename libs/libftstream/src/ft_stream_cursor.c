/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_cursor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 11:29:54 by barbare           #+#    #+#             */
/*   Updated: 2017/01/30 17:14:19 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stream.h>
#include <stdio.h>
#include <libft.h>

/*
** ****************************************************************************
** ft_stream_fill
** INPUT:	Struct stream
** OUTPUT:	Nothing
** Describe: Read again after stream's create for complete element
** ****************************************************************************
*/

t_stream		ft_stream_fill(t_stream stream)
{
	char	buf[BUFFSTREAM];
	int		ret;

	buf[0] = '\0';
	if (stream.cursor > 0)
		stream = ft_stream_cr(stream);
	ret = read(stream.fdin, buf, BUFFSTREAM - stream.size);
	buf[ret] = '\0';
	ft_strcat(stream.buf, buf);
	stream.size = ft_strlen(stream.buf);
	return (stream);
}

/*
** ****************************************************************************
** ft_stream_cr
** INPUT:	Struct stream
** OUTPUT:	Nothing
** Describe: Carriage return old string to start
** ****************************************************************************
*/

t_stream		ft_stream_cr(t_stream stream)
{
	ft_strcpy(stream.buf, &stream.buf[stream.cursor]);
	stream.size = ft_strlen(stream.buf);
	stream.cursor = 0;
	return (stream);
}

/*
** ****************************************************************************
** ft_move_cursor
** INPUT:	Struct stream
** OUTPUT:	Nothing
** Describe: move cursor in file
** ****************************************************************************
*/

t_stream		ft_move_cursor(t_stream stream, int move)
{
	if (FLAGS(stream.flags, F_MOVE))
	{
		stream.cursor += move;
		stream.oldmove = move;
	}
	return (stream);
}

/*
** ****************************************************************************
** ft_reverse_cursor
** INPUT:	Struct stream
** OUTPUT:	Nothing
** Describe: move cursor in file
** ****************************************************************************
*/

t_stream		ft_reverse_cursor(t_stream stream)
{
	if (FLAGS(stream.flags, F_MOVE))
	{
		stream.cursor -= stream.oldmove;
		stream.oldmove = -stream.oldmove;
	}
	return (stream);
}


