/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 16:43:41 by barbare           #+#    #+#             */
/*   Updated: 2017/01/30 18:18:14 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_stream.h>

/*
** ****************************************************************************
** ft_stream_new
** INPUT:	File descriptor input read(integer)
**			File descriptor output write(integer)
** 			Struct stream like C++ string
** OUTPUT:	Nothing
** Describe: Create new stream to save a long stream
** ****************************************************************************
*/

t_stream		ft_stream_new(int fdin, int fdout, int fderr)
{
	t_stream		stream;

	stream.fdin = fdin;
	stream.fdout = fdout;
	stream.fderr = fderr;
	stream.size = 0;
	stream.cursor = 0;
	stream.get = NULL;
	stream.flags = 0 | F_MOVE;
	stream.buf[0] = '\0';
	return (stream);
}

/*
** ****************************************************************************
** ft_stream_new
** INPUT:	File descriptor input read(integer)
**			File descriptor output write(integer)
**			File descriptor error write(integer)
** 			Struct stream like C++ string
** OUTPUT:	Nothing
** Describe: Create new stream to save a long stream
** ****************************************************************************
*/

t_stream		ft_stream_set_fdin(t_stream stream, int fdin)
{
	stream.fdin = fdin;
	return (stream);
}

/*
** ****************************************************************************
** ft_stream_new
** INPUT:	File descriptor input read(integer)
**			File descriptor output write(integer)
**			File descriptor error write(integer)
** 			Struct stream like C++ string
** OUTPUT:	Nothing
** Describe: Create new stream to save a long stream
** ****************************************************************************
*/

t_stream		ft_stream_set_fdout(t_stream stream, int fdout)
{
	stream.fdout = fdout;
	return (stream);
}

/*
** ****************************************************************************
** ft_stream_new
** INPUT:	File descriptor input read(integer)
**			File descriptor output write(integer)
**			File descriptor error write(integer)
** 			Struct stream like C++ string
** OUTPUT:	Nothing
** Describe: Create new stream to save a long stream
** ****************************************************************************
*/

t_stream		ft_stream_set_fderr(t_stream stream, int fderr)
{
	stream.fderr = fderr;
	return (stream);
}
