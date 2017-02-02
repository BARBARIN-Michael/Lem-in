/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 11:55:56 by barbare           #+#    #+#             */
/*   Updated: 2017/02/02 17:30:30 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "ft_stream.h"
# include "libft.h"
# include <stdio.h> //to del

# define ERROR(X) { ft_putendl("ERROR : "X); exit(-1); }
# define PATH_MAX 4096

# define INTER	0x0
# define START	0x01
# define END	0x10

typedef struct s_room		t_room;
typedef struct s_way		t_way;

struct					s_room
{
	int				is_active;
	char			*name;
	unsigned long	namedjb;
	void			**way;
	int				nbway;
	unsigned int	nb_ant;
	unsigned int	type;
	unsigned int	x;
	unsigned int	y;
	t_room			*oldroom;
	int				is_already_find;
	int				move;
	t_room			*next;
};

t_stream		init_stream(void);
t_room			*parser(t_stream stream);
t_stream		parser_room(t_stream stream, t_room *r, t_room **f);
void			parser_way(t_stream stream, t_room *f);

void			*ft_getroom(t_room *room, char *name);
void			ft_insert_pipe_room(t_room *room, void *id);
void			ft_set_pipeline(t_room *room, char *room_a, char *room_b);
t_room			create_room(t_room *room, char *line, unsigned int type);

int				is_room(char *line);
int				is_way(char *line);
int				is_com(char *line);
int				get_command(char *argv);

int				get_ant(int	nb);

void			process_algo(t_room *room);
t_room			*normalize_way(t_room *src, t_room *end);
t_room			*inverse_way(t_room *src, t_room *end);
t_room			*dijkstra2(t_room *src);
void			step(void **anthill, int ants);
void			anthill(t_room *src, t_room *end);

#endif
