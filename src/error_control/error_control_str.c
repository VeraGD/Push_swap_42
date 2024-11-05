/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_control_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:11:09 by veragarc          #+#    #+#             */
/*   Updated: 2024/10/31 15:22:51 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	check_caracter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == ' ') || (str[i] >= '0' && str[i] <= '9'))
			i++;
		else if ((str[i] == '-') || (str[i] == '+'))
			i++;
		else
			return (1);
	}
	return (0);
}

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

int	check_double(int *str, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	*numbers_string(char *str)
{
	int		*num;
	char	**str_num;
	int		i;

	i = 0;
	str_num = ft_split(str, ' ');
	if (check_signs(str_num) == 1 || check_caracter(str) == 1)
	{
		free_split(str_num);
		return (NULL);
	}
	if (ft_strlen_double(str_num) <= 10)
	{
		num = (int *)malloc((ft_strlen_double(str_num)) * sizeof(int));
		if (!num)
		{
			free_split(str_num);
			return (NULL);
		}
		while (str_num[i])
		{
			num[i] = ft_atoi(str_num[i]);
			if (num[i] == 0 && str_num[i][0] != '0')
			{
				free(num);
				free_split(str_num);
				return (NULL);
			}
			i++;
		}
		if (check_double(num, ft_strlen_double(str_num)) == 1)
		{
			free(num);
			free_split(str_num);
			return (NULL);
		}
		free_split(str_num);
		return (num);
	}
	free_split(str_num);
	return (NULL);
}
