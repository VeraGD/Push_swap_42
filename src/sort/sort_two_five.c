/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:55:48 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/15 11:06:51 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*sort_three(t_stack *t)
{
	int	*nums;

	nums = t->stack_a;
	if (nums[0] < nums[1] && nums[1] < nums[2])
	{
		swap("sa", t);
		rev_rot("rra", t);
	}
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] < nums[2])
		rev_rot("rra", t);
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] < nums[2])
		rot("ra", t);
	else if (nums[0] < nums[1] && nums[1] > nums[2] && nums[0] > nums[2])
	{
		swap("sa", t);
		rot("ra", t);
	}
	else if (nums[0] > nums[1] && nums[1] < nums[2] && nums[0] > nums[2])
		swap("sa", t);
	return (t);
}

static int	get_min(t_stack *t)
{
	int	min;
	int	index;
	int	*num;
	int	i;

	num = t->stack_a;
	i = 1;
	min = num[0];
	index = 0;
	while (i <= t->topa)
	{
		if (min > num[i])
		{
			min = num[i];
			index = i;
		}
		i++;
	}
	return (index);
}

t_stack	*sort_four(t_stack *t)
{
	int	index;

	index = get_min(t);
	if (index == t->topa - 1)
		swap("sa", t);
	else if (index == t->topa - 2)
	{
		rev_rot("rra", t);
		rev_rot("rra", t);
	}
	else if (index == t->topa - 3)
		rev_rot("rra", t);
	pb(t);
	t = sort_three(t);
	pa(t);
	return (t);
}

static t_stack	*get_up_min_five(t_stack *t, int index)
{
	if (index == t->topa - 1)
		swap("sa", t);
	else if (index == t->topa - 2)
	{
		rev_rot("rra", t);
		rev_rot("rra", t);
		rev_rot("rra", t);
	}
	else if (index == t->topa - 3)
	{
		rev_rot("rra", t);
		rev_rot("rra", t);
	}
	else if (index == t->topa - 4)
		rev_rot("rra", t);
	return (t);
}

t_stack	*sort_five(t_stack *t)
{
	int	index;

	index = get_min(t);
	t = get_up_min_five(t, index);
	pb(t);
	t = sort_four(t);
	pa(t);
	return (t);
}
