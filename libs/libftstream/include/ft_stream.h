/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stream.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 16:34:13 by barbare           #+#    #+#             */
/*   Updated: 2017/01/30 17:13:54 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STREAM_H
# define FT_STREAM_H

# include <stddef.h>
# include <unistd.h>

# define BUFFSTREAM 4096

# define F_NMOVE	0x0
# define F_MOVE		0x1

# define F_START	0x0
# define F_END		0x1

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
typedef struct		s_stream
{
	char			fdin;
	char			fdout;
	char			fderr;
	int				size;
	int				cursor;
	int				oldmove;
	int				flags;
	char			buf[BUFFSTREAM];
	char			*get;
}					t_stream;

/*
** ****************************************************************************
** ft_stream_new.c
** Describe: create, change stream
** ****************************************************************************
*/
t_stream			ft_stream_new(int fdin, int fdout, int fderr);
t_stream			ft_stream_set_fd(t_stream stream, int in, int out, int err);
t_stream			ft_stream_set_fdin(t_stream stream, int fdin);
t_stream			ft_stream_set_fdout(t_stream stream, int fdout);
t_stream			ft_stream_set_fderr(t_stream stream, int fderr);

/*
** ****************************************************************************
** ft_stream_cursor.c
** Describe: move cursor and get data
** ****************************************************************************
*/
t_stream			ft_stream_cr(t_stream stream);
t_stream			ft_stream_fill(t_stream stream);
t_stream			ft_move_cursor(t_stream stream, int move);
t_stream			ft_reverse_cursor(t_stream stream);

/*
** ****************************************************************************
** ft_stream_read.c
** Describe: move cursor and get data
** ****************************************************************************
*/
t_stream			ft_stream_read(t_stream stream, int flags);
t_stream			ft_stream_read_n(t_stream stream, int n, int flags);
t_stream			ft_stream_read_c(t_stream stream, int c, int flags);
t_stream			ft_stream_read_expr(t_stream stream, char *exp, int flags);
t_stream			ft_stream_read_full(t_stream stream, int flags);

/*
** ****************************************************************************
** ft_stream_reset.c
** Describe: reset data stream
** ****************************************************************************
*/
t_stream			ft_stream_reset_get(t_stream stream);
t_stream			ft_stream_reset_buffer(t_stream stream);
t_stream			ft_stream_filter(t_stream stream,
					void (*fct)(int *cursor, char *buf, int mod), int flags);

/*
** ****************************************************************************
** ft_stream_get.c
** Describe: place in get data
** ****************************************************************************
*/
t_stream			ft_stream_get_protocol(t_stream stream, char *buf,
										size_t size, char *prot);
t_stream			ft_stream_get_expr(t_stream stream, char *expr, int fl);

#endif
