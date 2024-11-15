/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cheap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:29:58 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/15 10:39:16 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	array_calculate_cheap(int topb, int index)
{
	int	half;
	int	index_half;
	int	num;

	if (topb == 0)
		index_half = 0;
	else
	{
		half = (topb + 1) / 2;
		index_half = half - 1;
	}
	if (index <= index_half)
		num = index + 1;
	else
		num = topb - index;
	return (num);
}

static int	calculate_cheap_min(int i, t_stack *t)
{
	int	op_a;
	int	op_b;
	int	num;

	op_a = array_calculate_cheap(t->topa, i);
	op_b = array_calculate_cheap(t->topb, (int)t->target[i]);
	num = op_a + op_b + 1;
	return (num);
}

t_stack	*calculate_target_min_all(t_stack *t)
{
	int	i;
	int	topb;

	topb = t->topb;
	i = 0;
	while (i < t->topa)
	{
		t->cheap[i] = calculate_cheap_min(i, t);
		i++;
	}
	return (t);
}
