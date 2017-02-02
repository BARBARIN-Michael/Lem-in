/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:40:05 by barbare           #+#    #+#             */
/*   Updated: 2017/02/02 13:16:41 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stream.h"
#include "lem_in.h"

t_stream	init_stream(void)
{
	t_stream stream;

	stream = ft_stream_new(STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
	return (stream);
}

int			main(void)
{
	t_stream		stream;
	t_room			*room;

	stream = init_stream();
	room = parser(stream);
	process_algo(room);
	return (0);
}
