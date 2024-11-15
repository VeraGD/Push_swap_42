/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_target_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:49:32 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/15 10:51:41 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	aux_rrr(t_stack *t, int j)
{
	rev_rot("rrr", t);
	j = j + 1;
	return (j);
}

static int	aux_rr(t_stack *t, int j)
{
	rot("rr", t);
	j = j + 1;
	return (j);
}

void	handle_rrr(t_stack *t, char **move_a, int *i, int *j)
{
	if (move_a[*j][0] == 'r' && move_a[*j][1] == 'r')
	{
		*j = aux_rrr(t, *j);
		(*i)++;
	}
	else
	{
		rev_rot("rrb", t);
		(*i)++;
	}
}

void	handle_r(t_stack *t, char **move_a, int *i, int *j)
{
	if (move_a[*j][0] == 'r' && move_a[*j][1] == 'a')
	{
		*j = aux_rr(t, *j);
		(*i)++;
	}
	else
	{
		rot("rb", t);
		(*i)++;
	}
}
