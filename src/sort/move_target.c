/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_target.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:07:29 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/15 11:17:28 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_stack	*aux_move_a(char **move_a, int j, t_stack *t)
{
	if (move_a != NULL)
	{
		while (move_a[j] != NULL)
		{
			if (move_a[j][0] == 'r' && move_a[j][1] == 'r')
				rev_rot("rra", t);
			else if (move_a[j][0] == 'r')
				rot("ra", t);
			j++;
		}
	}
	return (t);
}

static t_stack	*aux_move_b(char **move_b, int i, t_stack *t)
{
	if (move_b != NULL)
	{
		while (move_b[i] != NULL)
		{
			if (move_b[i][0] == 'r' && move_b[i][1] == 'r')
				rev_rot("rrb", t);
			else if (move_b[i][0] == 'r')
				rot("rb", t);
			i++;
		}
	}
	return (t);
}

static t_stack	*aux_b(char **move_b, int i, t_stack *t)
{
	if (move_b[i][0] == 'r' && move_b[i][1] == 'r')
		rev_rot("rrb", t);
	else if (move_b[i][0] == 'r')
		rot("rb", t);
	return (t);
}

t_stack	*made_move(t_stack *t, char **move_b, char **move_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (move_a && move_b)
	{
		while (move_b[i])
		{
			if (move_a[j])
			{
				if (move_b[i][0] == 'r' && move_b[i][1] == 'r')
					handle_rrr(t, move_a, &i, &j);
				else if (move_b[i][0] == 'r')
					handle_r(t, move_a, &i, &j);
			}
			else
			{
				t = aux_b(move_b, i, t);
				i++;
			}
		}
	}
	t = aux_move_a(move_a, j, t);
	return (aux_move_b(move_b, i, t));
}

t_stack	*move_top_and_push(t_stack *t, int index)
{
	char	**moves;
	char	**move_b;
	char	**move_a;

	moves = generate_moves(t->topb, "b");
	if (moves[t->target[index]] != NULL)
		move_b = ft_split(moves[t->target[index]], ' ');
	else
		move_b = NULL;
	free_split(moves);
	moves = generate_moves(t->topa, "a");
	if (moves[index] != NULL)
		move_a = ft_split(moves[index], ' ');
	else
		move_a = NULL;
	free_split(moves);
	t = made_move(t, move_b, move_a);
	pb(t);
	free_split(move_b);
	free_split(move_a);
	return (t);
}
