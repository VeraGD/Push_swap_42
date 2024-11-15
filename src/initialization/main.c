/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:09:21 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/14 16:12:51 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	main(int argc, char **argv)
{
	int		*num;
	t_stack	*t;

	num = 0;
	if (argc == 2)
		num = numbers_string(argv[1]);
	else if (argc > 2)
		num = check_more_argv(argc, argv);
	if (num != NULL)
	{
		t = inicialization(num, argc, argv);
		t = choose_sort(t);
		free_struct(t);
		free(num);
	}
	else if (argc == 1)
		ft_printf("");
	else
		ft_printf("Error\n");
}
