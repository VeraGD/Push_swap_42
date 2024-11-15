/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:26:26 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/14 15:56:58 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_strlen_double(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	*ft_reverse(int *num, int len)
{
	int	i;
	int	j;
	int	*res;

	i = 0;
	j = len - 1;
	res = (int *)malloc((len) * sizeof(int));
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = num[j];
		i++;
		j--;
	}
	return (res);
}

int	len_stack(int argc, char **argv)
{
	char	**str;
	int		len;

	if (argc == 2)
	{
		str = ft_split(argv[1], ' ');
		len = ft_strlen_double(str);
		free_split(str);
	}
	else
	{
		len = argc - 1;
	}
	return (len);
}

char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
