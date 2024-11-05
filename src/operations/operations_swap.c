/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:51:23 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/31 16:52:48 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	*swap_operation(int *num, int top)
{
	int	temp;

	temp = num[top];
	num[top] = num[top - 1];
	num[top - 1] = temp;
	return (num);
}

void	swap(char *str, t_stack *t)
{
	int	*numo;

	if (str[0] == 's' && str[1] == 'a')
	{
		numo = swap_operation(t->stack_a, t->topa);
		t->stack_a = numo;
		ft_printf("sa\n");
	}
	else if (str[0] == 's' && str[1] == 'b')
	{
		numo = swap_operation(t->stack_b, t->topb);
		t->stack_b = numo;
		ft_printf("sb\n");
	}
	else if (str[0] == 's' && str[1] == 's')
	{
		numo = swap_operation(t->stack_a, t->topa);
		t->stack_a = numo;
		numo = swap_operation(t->stack_b, t->topb);
		t->stack_b = numo;
		ft_printf("ss\n");
	}
}
