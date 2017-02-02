/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/13 10:58:55 by mbarbari          #+#    #+#             */
/*   Updated: 2015/06/02 13:56:19 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CHECKING_H
# define FT_CHECKING_H

# include <libft.h>
# include <stdio.h>
# include <errno.h>

# define LECT_LINE() printf("DEBUG : %s:%d: ", __FILE__, __LINE__);
# define DEBUG(D, ...) {LECT_LINE(); printf(D "\n", ##__VA_ARGS__);}

# define REXIT exit(-1);

# define LECT_FCT(F, E) printf("Fonction( "BLUE""F""C_NONE" ) : " E "\n");
# define T_W(C, T) printf("%$"C"["T"] "C_NONE, 2)
# define T_ARGS(E, ...) printf("%$"E"\n", 2, ##__VA_ARGS__)
# define F_WRITE(F, U) printf("%$"F" "U, 2);

# define N_ERR(E, ...){T_W(RED, "ERR"); T_ARGS(E, ##__VA_ARGS__);}
# define RN_ERR(E, ...) T_W(RED, "RN_ERR"),T_ARGS(E, ##__VA_ARGS__)
# define E_ERR(E, F) { T_W(RED, "E_ERR") LECT_FCT(F, E) exit(-1); }
# define TE_ERR(C, E, F) { if (C) E_ERR(E, F) }
# define F_ERR(E, F) { T_W(BRED, "F_ERR") LECT_FCT(F, E) exit(-2); }
# define TF_ERR(C, E, F) { if (C) F_ERR(E, F) }

# define N_INFO(I, F) { T_W(GREEN, "INFO") LECT_FCT(F, I) }
# define N_USAGE(I, F) { T_W(BGREEN, "USAGE") F_WRITE(F, I) exit(-1);}

# define CHECK(C, S, ...) if(!(C)) { printf(S "\n", ##__VA_ARGS__); }
# define CHECK_MEM(C) if(!(C)) { printf(RED"Out of memory!\n"); exit(-1); }

#endif
