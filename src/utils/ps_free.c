/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:25:40 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/31 18:25:52 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_struct(t_stack *struct_ps)
{
	if (struct_ps)
	{
		if (struct_ps->stack_a != NULL)
			free(struct_ps->stack_a);
		if (struct_ps->stack_b != NULL)
			free(struct_ps->stack_b);
		if (struct_ps->target != NULL)
			free(struct_ps->target);
		if (struct_ps->cheap != NULL)
			free(struct_ps->cheap);
		free(struct_ps);
	}
}

void	free_moves(char **moves, int top)
{
	int	i = 0;

	while (i < top)
	{
		free(moves[i]);
		i++;
	}
	free(moves);
}
