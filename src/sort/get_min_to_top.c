/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_to_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:44:08 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/15 10:47:50 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	get_min_final(t_stack *t)
{
	int	i;
	int	*num;
	int	min;

	num = t->stack_a;
	i = t->topa;
	min = i - 1;
	while (i >= 0)
	{
		if (num[i] < num[min])
			min = i;
		i--;
	}
	return (min);
}

t_stack	*get_top(int min, t_stack *t)
{
	int	half;
	int	i;

	half = (t->topa + 1) / 2;
	i = min;
	if (i < half)
	{
		while (i >= 0)
		{
			rev_rot("rra", t);
			i--;
		}
	}
	else
	{
		if (i != t->topa)
		{
			while (i < t->topa)
			{
				rot("ra", t);
				i++;
			}
		}
	}
	return (t);
}
