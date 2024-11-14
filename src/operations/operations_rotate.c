/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:49:35 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/31 16:51:11 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

/* static int	*rot_operation(int *num, int top)
{
	int	i;
	int	*numo;

	i = 1;
	numo = (int *)malloc((top + 1) * sizeof(int));
	numo[0] = num[top];
	while (i < top + 1)
	{
		numo[i] = num[i - 1];
		i++;
	}
	return (numo);
} */

/* static int *rot_operation(int *num, int top)
{
    int temp;
    int i;

    if (top > 0)
	{
		temp = num[0];
		i = 1;
		while (i < top)
		{
			num[i] = num[i - 1];
			i++;
		}
		num[top] = temp;
	}
	return (num);
} */

static int *rot_operation(int *num, int top)
{
    int temp;
    int i;

    if (top > 0)
    {
        temp = num[top];
        i = top;
        while (i > 0)
        {
            num[i] = num[i - 1];
            i--;
        }
        num[0] = temp;
    }
    return (num);
}

void	rot(char *str, t_stack *t)
{
	int	*numo;

	if (str[0] == 'r' && str[1] == 'a')
	{
		numo = rot_operation(t->stack_a, t->topa);
		t->stack_a = numo;
		ft_printf("ra\n");
	}
	else if (str[0] == 'r' && str[1] == 'b')
	{
		numo = rot_operation(t->stack_b, t->topb);
		t->stack_b = numo;
		ft_printf("rb\n");
	}
	else if (str[0] == 'r' && str[1] == 'r')
	{
		numo = rot_operation(t->stack_a, t->topa);
		t->stack_a = numo;
		numo = rot_operation(t->stack_b, t->topb);
		t->stack_b = numo;
		ft_printf("rr\n");
	}
}
