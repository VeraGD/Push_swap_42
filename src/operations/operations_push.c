/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:24:56 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/14 16:00:12 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_stack *t)
{
	int	temp;

	temp = t->stack_b[t->topb];
	t->topa++;
	t->stack_a[t->topa] = temp;
	t->stack_b[t->topb] = 0;
	t->topb--;
	ft_printf("pa\n");
}

void	pb(t_stack *t)
{
	int	temp;

	if (t->topa >= 0)
	{
		temp = t->stack_a[t->topa];
		t->topb++;
		t->stack_b[t->topb] = temp;
		t->stack_a[t->topa] = 0;
		t->topa--;
		ft_printf("pb\n");
	}
}
