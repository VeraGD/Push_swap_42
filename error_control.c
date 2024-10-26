#include "push_swap.h"

int     ft_strlen_double(char **split)
{
    int i;

    i = 0;
    while (split[i])
        i++;
    return (i);
}

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

int     check_caracter(char *str)
{
    int i;

    i = 0;
    while(str[i])
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

int     check_signs(char **str)
{
    int i;
    int j;
    int cont;

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

int     check_double(int *str)
{
    int i;
    int j;

    i = 0;
    j = 1;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (str[i] == str[j])
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}


int    *numeros_string(char *str)
{
    int *num;
    char **str_num;
    int i;

    i = 0;
    if (check_caracter(str) == 1)
        return (NULL);
    str_num = ft_split(str, ' ');
    if (check_signs(str_num) == 1)
        return (NULL);
    if (ft_strlen_double(str_num) <= 10)
    {
        num = (int *)malloc((ft_strlen_double(str_num)) * sizeof(int));
        while (str_num[i])
        {
            num[i] = ft_atoi(str_num[i]);
            i++;
        }
        if (check_double(num) == 1)
            return (NULL);
        free_split(str_num);
        return (num);
    }
    free_split(str_num);
    return (NULL);
}

// char    **check_spaces(char **argv)
// {
//     int i;
//     int j;
//     char **num;

//     i = 0;
//     j = 0;
//     num = (char **)malloc((10 + 1) * sizeof(char *));
//     while (argv[i])
//     {
//         if (ft_strchr(argv[i], ' ') != NULL || ft_strchr(argv[i], '\t') != NULL)
//         {
//             // funcion numeros_string o algo asi 
//         }
//         else
//             num[j] = 
//     }
// }

int     main(int argc, char **argv)
{
    int    *num;

    num = 0;
   if (argc == 2)
   {
        num = numeros_string(argv[1]);
   }
//    else if (argc > 2)
//    {
//     // veo si hay espacios en alguno
//         // si no hay, todo numeros sueltos
//         // si hay, tratar varios aspectos a la vez
//    }
    if (num != NULL)
    {
        int i = 0;
        //while (i < ft_strlen_double(ft_split(argv[i], ' ')))
        while (i < 8)
        {
            ft_printf("%d\n", num[i]);
            i++;
        }
        free(num);
    }
    else
        ft_printf("Error\n");
}