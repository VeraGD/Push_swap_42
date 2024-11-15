/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:53:03 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/15 10:55:33 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push_two_first(t_stack *t)
{
	pb(t);
	pb(t);
}

static int	get_min(t_stack *t)
{
	int	i;
	int	index;
	int	min;

	if (t == NULL || t->cheap == NULL || t->topa <= 0)
		return (-1);
	index = 0;
	min = INT_MAX;
	i = 0;
	while (i < t->topa)
	{
		if (t->cheap[i] < min)
		{
			min = t->cheap[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static t_stack	*sort_two_b(t_stack *t)
{
	int	*nums;

	nums = t->stack_b;
	if (nums[0] > nums[1])
		swap("sb", t);
	return (t);
}

t_stack	*turk_algorithm(t_stack *t)
{
	int	n;
	int	min;

	push_two_first(t);
	t = sort_two_b(t);
	while (t->topa > 0)
	{
		t = target_min(t);
		n = get_min(t);
		t = move_top_and_push(t, n);
	}
	t = target_min(t);
	t = move_top_and_push(t, 0);
	while (t->topb > 0)
	{
		pa(t);
	}
	pa(t);
	min = get_min_final(t);
	t = get_top(min, t);
	return (t);
}
