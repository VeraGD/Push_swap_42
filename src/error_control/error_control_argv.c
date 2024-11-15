/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control_more.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:04:45 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/31 15:10:35 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	check_signs_str_one(char *str)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			cont++;
		i++;
	}
	if (cont > 1)
		return (1);
	return (0);
}

static int	one_number_str(char *str)
{
	int	num;

	if (check_signs_str_one(str) == 1 || check_caracter(str) == 1)
		return (0);
	num = ft_atoi(str);
	return (num);
}

int	*check_more_argv(int argc, char **argv)
{
	int	i;
	int	*num;

	i = 1;
	num = (int *)malloc((argc - 1) * sizeof(int));
	if (!num)
		return (NULL);
	while (argv[i])
	{
		num[i - 1] = one_number_str(argv[i]);
		if (num[i - 1] == 0 && argv[i][0] != '0')
		{
			free(num);
			return (NULL);
		}
		i++;
	}
	if (check_double(num, argc - 1) == 1)
	{
		free(num);
		return (NULL);
	}
	return (num);
}
