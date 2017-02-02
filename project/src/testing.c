/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barbare <barbare@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 14:09:03 by barbare           #+#    #+#             */
/*   Updated: 2017/02/01 14:22:25 by barbare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			is_room(char *args)
{
	int		i;
	int		nbspaces;
	int		nbargs;

	i = -1;
	nbargs = 0;
	nbspaces = 0;
	if (ft_isalnum(args[0]) && args[0] != 'L')
		nbargs++;
	else
		return (FALSE);
	while (args[++i])
		if (args[i] == ' ' && ft_isalnum(args[i + 1]))
		{
			nbspaces++;
			nbargs++;
		}
	return ((nbspaces == 2 && nbargs == 3) ? TRUE : FALSE);
}

int			is_way(char *args)
{
	int		i;
	int		nbspaces;
	int		nbargs;

	i = -1;
	nbargs = 0;
	nbspaces = 0;
	if (ft_isalnum(args[0]))
		nbargs++;
	else
		return (FALSE);
	while (args[++i])
		if (args[i] == '-' && ft_isalnum(args[i + 1]))
		{
			nbspaces++;
			nbargs++;
		}
	return ((nbspaces == 1 && nbargs == 2) ? TRUE : FALSE);
}

int			is_com(char *argv)
{
	return ((argv[0] == '#' && argv[1] != '#'));
}

int			get_command(char *argv)
{
	if (ft_strcmp(argv, "##start") == 0)
		return (START);
	else if (ft_strcmp(argv, "##end") == 0)
		return (END);
	return (INTER);
}
