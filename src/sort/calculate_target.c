/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_target.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:33:39 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/15 10:39:54 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	get_max(t_stack *t)
{
	int	*numb;
	int	top;
	int	i;
	int	max;

	numb = t->stack_b;
	top = t->topb;
	i = 0;
	max = 0;
	while (i <= top)
	{
		if (numb[i] > numb[max])
			max = i;
		i++;
	}
	return (max);
}

int	calculate_target_minima(int a, t_stack *t)
{
	int		i;
	long	min;
	int		index;

	i = t->topb;
	min = INT_MAX;
	index = get_max(t);
	while (i >= 0)
	{
		if (min == INT_MAX && a > t->stack_b[i])
		{
			min = t->stack_b[i];
			index = i;
		}
		else if (a > t->stack_b[i])
		{
			if (t->stack_b[i] > min)
			{
				min = t->stack_b[i];
				index = i;
			}
		}
		i--;
	}
	return (index);
}

t_stack	*target_min(t_stack *t)
{
	int	i;
	int	j;

	i = t->topa;
	j = 0;
	while (i >= 0)
	{
		t->target[j] = calculate_target_minima(t->stack_a[j], t);
		t = calculate_target_min_all(t);
		i--;
		j++;
	}
	return (t);
}
