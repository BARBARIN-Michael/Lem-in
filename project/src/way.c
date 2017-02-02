/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:25:52 by barbare           #+#    #+#             */
/*   Updated: 2017/02/02 17:45:24 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room			*normalize_way(t_room *src, t_room *end)
{
	t_room	*tmp;
	t_room	*theend;
	int		nbway;

	tmp = src;
	theend = end;
	while (tmp)
	{
		if (tmp->is_already_find == (end->is_already_find - 1))
		{
			nbway = tmp->nbway;
			while (nbway)
				if (tmp->way[--nbway] == end)
				{
					end->oldroom = tmp;
					end = tmp;
					tmp = src;
				}
		}
		tmp = tmp->next;
	}
	end->oldroom = src;
	src->oldroom = NULL;
	theend->next = NULL;
	return (theend);
}

t_room			*inverse_way(t_room *src, t_room *end)
{
	t_room		*tmp;
	t_room		*next;

	end->next = NULL;
	tmp = end->oldroom;
	next = end;
	while (tmp)
	{
		tmp->next = next;
		next = tmp;
		tmp = tmp->oldroom;
	}
	end->next = NULL;
	return (src);
}

t_room			*dijkstra2(t_room *src)
{
	t_room	*pipe;
	t_room	*next;
	int		nb;

	src->is_already_find = 1;
	next = src;
	while (src && src->type != END && (nb = src->nbway))
	{
		while (nb)
		{
			pipe = (t_room *)src->way[--nb];
			if (pipe->is_already_find == 0)
			{
				pipe->is_already_find = src->is_already_find + 1;
				next->next = pipe;
				next = next->next;
			}
		}
		src = src->next;
	}
	next->next = NULL;
	if (!src)
		return (NULL);
	else
		return (src);
}

void			step(void **anthill, int ants)
{
	t_room	*tmp;
	int		i;

	i = -1;
	while (++i < ants)
	{
		tmp = (t_room *)anthill[i];
		if (tmp->type != END && (tmp->next->nb_ant == 0 ||
					tmp->next->type == END) && tmp->next->move == FALSE)
		{
			ft_putstr(C_MAGENTA"L");
			ft_putnbr(i + 1);
			ft_putstr("-");
			ft_putstr(tmp->next->name);
			ft_putstr("\t");
			anthill[i] = tmp->next;
			tmp->next->nb_ant++;
			tmp->nb_ant--;
		}
	}
	ft_putendl("");
}

void			anthill(t_room *src, t_room *end)
{
	void			**anthill;
	t_room			*tmp;
	int				a;
	unsigned int	ant;

	(void)end;
	ant = src->nb_ant;
	anthill = malloc(sizeof(void *) * ant);
	while (ant--)
		anthill[ant] = src;
	ant = src->nb_ant;
	a = 0;
	while (end->nb_ant < ant)
	{
		tmp = src;
		while (tmp)
		{
			tmp->move = FALSE;
			tmp = tmp->next;
		}
		step(anthill, ant);
		a++;
	}
	free(anthill);
}
