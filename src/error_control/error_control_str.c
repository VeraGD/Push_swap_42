/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:11:09 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/14 16:17:40 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	check_signs(char **str)
{
	int	i;
	int	j;
	int	cont;

	i = 0;
	while (str[i])
	{
		cont = 0;
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
				cont++;
			j++;
		}
		if (cont > 1)
			return (1);
		i++;
	}
	return (0);
}

static int	check_errors(char **str_num, char *str)
{
	if (check_signs(str_num) == 1 || check_caracter(str) == 1)
		return (1);
	return (0);
}

static int	*convert_to_numbers(char **str_num)
{
	int	*num;
	int	i;

	i = 0;
	num = (int *)malloc(ft_strlen_double(str_num) * sizeof(int));
	if (!num)
		return (NULL);
	while (str_num[i])
	{
		num[i] = ft_atoi(str_num[i]);
		if (num[i] == 0 && str_num[i][0] != '0')
		{
			free(num);
			return (NULL);
		}
		i++;
	}
	return (num);
}

int	*numbers_string(char *str)
{
	char	**str_num;
	int		*num;

	str_num = ft_split(str, ' ');
	if (check_errors(str_num, str))
	{
		free_split(str_num);
		return (NULL);
	}
	num = convert_to_numbers(str_num);
	if (!num || check_double(num, ft_strlen_double(str_num)) == 1)
	{
		free(num);
		free_split(str_num);
		return (NULL);
	}
	free_split(str_num);
	return (num);
}
