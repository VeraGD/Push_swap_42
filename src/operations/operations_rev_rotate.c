/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rev_rotate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:12:59 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/14 16:00:59 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	*rev_rot_operation(int *num, int top)
{
	int	temp;
	int	i;

	if (top > 0)
	{
		temp = num[0];
		i = 0;
		while (i < top)
		{
			num[i] = num[i + 1];
			i++;
		}
		num[top] = temp;
	}
	return (num);
}

void	rev_rot(char *str, t_stack *t)
{
	int	*numo;

	if (str[0] == 'r' && str[1] == 'r' && str[2] == 'a')
	{
		numo = rev_rot_operation(t->stack_a, t->topa);
		t->stack_a = numo;
		ft_printf("rra\n");
	}
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'b')
	{
		numo = rev_rot_operation(t->stack_b, t->topb);
		t->stack_b = numo;
		ft_printf("rrb\n");
	}
	else if (str[0] == 'r' && str[1] == 'r' && str[2] == 'r')
	{
		numo = rev_rot_operation(t->stack_a, t->topa);
		t->stack_a = numo;
		numo = rev_rot_operation(t->stack_b, t->topb);
		t->stack_b = numo;
		ft_printf("rrr\n");
	}
}
