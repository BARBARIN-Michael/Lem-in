/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:54:18 by barbare           #+#    #+#             */
/*   Updated: 2017/02/02 13:14:59 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_room(t_room *room)
{
	while (room)
	{
		room = room->next;
	}
}

int			get_ant(int	nb)
{
	static int		ant = 0;

	if (nb > 0)
		ant = nb;
	return (ant);
}

t_room		*parser(t_stream stream)
{
	t_room		*room;
	t_room		*tmp;
	char		buf[PATH_MAX];

	stream = ft_stream_get_protocol(stream, buf, PATH_MAX, "\n");
	room = ft_memalloc(sizeof(t_room));
	if (ft_isdigit(buf[0]) && ft_atoi(buf) > 0)
		get_ant(ft_atoi(buf));
	else
		ERROR("nb ant");
	tmp = room;
	stream = parser_room(stream, room, &tmp);
	print_room(room);
	parser_way(stream, room);
	return (room);
}

t_stream		parser_room(t_stream stream, t_room *first, t_room **last)
{
	char			buf[PATH_MAX];
	unsigned int	cmd;
	unsigned int	type;

	type = INTER;
	cmd = 0x00;
	while (42)
	{
		stream = ft_stream_get_protocol(stream, buf, PATH_MAX, "\n");
		if (buf[0] == '#' && buf[1] == '#')
			cmd |= (type = get_command(buf));
		else if (buf[0] != '\0' && !is_com(buf) && is_room(buf))
		{
			**last = create_room(first, buf, type);
			*last = (*last)->next;
			type = INTER;
		}
		else if (is_com(buf))
			continue ;
		else if (is_way(buf) && cmd == 0x11)
			break ;
		else
			ERROR("BAD ROOM PARSING");
	}
	return (ft_reverse_cursor(stream));
}

void		parser_way(t_stream stream, t_room *room)
{
	char		buf[PATH_MAX];
	char		**args;

	while (42)
	{
		stream = ft_stream_get_protocol(stream, buf, PATH_MAX, "\n");
		if (buf[0] != '\0' && is_way(buf))
		{
			args = ft_strsplit2(buf, '-');
			ft_set_pipeline(room, args[0], args[1]);
			free(args);
		}
		else if (buf[0] != '\0' && !is_com(buf))
		{
			ERROR("BAD WAY PARSING");
		}
		if (buf[0] == '\0' || buf[0] == '\n')
			return ;
	}
}
