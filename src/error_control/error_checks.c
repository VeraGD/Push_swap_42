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