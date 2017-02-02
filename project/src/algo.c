/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 14:22:37 by barbare           #+#    #+#             */
/*   Updated: 2017/02/02 17:50:36 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "lem_in.h"
#include "libft.h"

void			free_exit(void **elem)
{
	t_room	*room;
	void	**end;
	int		i;

	end = elem;
	i = 0;
	while (end[i])
	{
		room = (t_room *)end[i];
		free(room->way);
		free(room->name);
		free(end[i++]);
	}
	free(elem);
}

void			**get_all_element(t_room *room)
{
	void		**arrayptr;
	t_room		*tmp;
	int			i;

	i = 0;
	tmp = room;
	while (tmp)
	{
		++i;
		tmp = tmp->next;
	}
	arrayptr = malloc(sizeof(void *) * i + 1);
	arrayptr[i] = NULL;
	tmp = room;
	i = 0;
	while (tmp)
	{
		arrayptr[i] = tmp;
		tmp = tmp->next;
		++i;
	}
	return (arrayptr);
}

void			process_algo(t_room *room)
{
	void	**elems;
	t_room	*tmp;
	t_room	*end;

	tmp = room;
	elems = get_all_element(room);
	while (tmp)
	{
		if (tmp->type == START)
		{
			tmp->next = NULL;
			if ((tmp = dijkstra2(tmp)) == NULL)
				ERROR("Way does not exist");
			end = normalize_way(room, tmp);
			tmp = inverse_way(room, end);
			anthill(tmp, end);
			break ;
		}
		tmp = tmp->next;
	}
	free_exit(elems);
}
