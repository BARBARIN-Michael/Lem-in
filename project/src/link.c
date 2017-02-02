/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:10:03 by barbare           #+#    #+#             */
/*   Updated: 2017/02/02 17:35:27 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		*ft_getroom(t_room *room, char *name)
{
	t_room	*tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->name && ft_strcmp(tmp->name, name) == 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

void		ft_insert_pipe_room(t_room *room, void *id)
{
	void		**way;
	int			i;
	
	i = 0;
	while (i < room->nbway)
	{
		if (room->way[i] == id)
			return ;
		++i;
	}
	if (id == NULL)
		ERROR("ROOM DOES NOT EXISTS");
	way = ft_memalloc(sizeof(void *) * (room->nbway + 1));
	if (room->nbway > 0)
		ft_memcpy(way, room->way, sizeof(void *) * room->nbway);
	if (room->nbway > 0)
		free(room->way);
	room->way = way;
	room->way[room->nbway++] = id;
}

void		ft_set_pipeline(t_room *room, char *room_a, char *room_b)
{
	t_room		*lst;
	int			nbrooms;

	lst = room;
	nbrooms = 0;
	while (lst && nbrooms < 2)
	{
		if (lst->name && ft_strcmp(lst->name, room_a) == 0)
		{
			ft_insert_pipe_room(lst, ft_getroom(room, room_b));
			nbrooms++;
		}
		if (lst->name && ft_strcmp(lst->name, room_b) == 0)
		{
			ft_insert_pipe_room(lst, ft_getroom(room, room_a));
			nbrooms++;
		}
		lst = lst->next;
	}
}

t_room		create_room(t_room *first, char *line, unsigned int type)
{
	t_room			room;
	char			**args;

	ft_bzero(&room, sizeof(t_room));
	if (ft_strchr(line, '-'))
		ERROR("bad name room !");
	args = ft_strsplit2(line, ' ');
	if (ft_getroom(first, args[0]) != NULL)
		ERROR("Room name already exist");
	room.is_active = TRUE;
	room.name = ft_strdup(args[0]);
	if ((room.type = type) == START)
		room.nb_ant = get_ant(-1);
	else
		room.nb_ant = 0;
	room.x = ft_atoi(args[1]);
	room.y = ft_atoi(args[2]);
	room.nbway = 0;
	room.next = ft_memalloc(sizeof(t_room));
	room.is_already_find = 0;
	free(args);
	return (room);
}
