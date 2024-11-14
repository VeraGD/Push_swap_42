/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:24:56 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/31 16:12:45 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* void	pa(t_stack *t)
{
	int	temp;
	int	*num;
	int	top;
	int	*numb;
	int	topb;

	num = t->stack_a;
	top = t->topa;
	numb = t->stack_b;
	topb = t->topb;
	temp = numb[topb];
	numb[topb] = 0;
	topb = topb - 1;
	top = top + 1;
	num[top] = temp;
	ft_printf("pa\n");
	t->stack_a = num;
	t->topa = top;
	t->stack_b = numb;
	t->topb = topb;
} */

void pa(t_stack *t)
{
    int temp;

	temp = t->stack_b[t->topb];
	t->topa++;
	t->stack_a[t->topa] = temp;
	t->stack_b[t->topb] = 0;
	t->topb--;
	ft_printf("pa\n");
}

/* void	pb(t_stack *t)
{
	int	temp;
	int	*num;
	int	top;
	int	*numb;
	int	topb;

	num = t->stack_a;
	top = t->topa;
	numb = t->stack_b;
	topb = t->topb;
	temp = num[top];
	numb[top] = 0;
	top = top - 1;
	topb = topb + 1;
	numb[topb] = temp;
	ft_printf("pb\n");
	t->stack_a = num;
	t->topa = top;
	t->stack_b = numb;
	t->topb = topb;
} */

void pb(t_stack *t)
{
    int temp;
    
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

/* void	pa(t_stack *a, t_stack *b)
{
	int	temp;
	int	*num;
	int	top;
	int	*numb;
	int	topb;

	num = a->array;
	top = a->top;
	numb = b->array;
	topb = b->top;
	temp = numb[topb];
	numb[topb] = 0;
	topb = topb - 1;
	top = top + 1;
	num[top] = temp;
	ft_printf("pa\n");
	a->array = num;
	a->top = top;
	b->array = numb;
	b->top = topb;
}

void	pb(t_stack *a, t_stack *b)
{
	int	temp;
	int	*num;
	int	top;
	int	*numb;
	int	topb;

	num = a->array;
	top = a->top;
	numb = b->array;
	topb = b->top;
	temp = num[top];
	numb[top] = 0;
	top = top - 1;
	topb = topb + 1;
	numb[topb] = temp;
	ft_printf("pb\n");
	a->array = num;
	a->top = top;
	b->array = numb;
	b->top = topb;
} */
