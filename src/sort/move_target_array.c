#include "../../push_swap.h"

static char	*fill_moves(int num_moves, const char *move)
{
	char	*result;
	int		i;
	int		len;

	len = (num_moves * strlen(move)) + (num_moves - 1) + 1;
	result = malloc(len * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	i = 0;
	while (i < num_moves)
	{
		ft_strcat(result, move);
		if (i < num_moves - 1)
			ft_strcat(result, " ");
		i++;
	}
	return (result);
}

static char	*get_move_type(int i, int top, char *flag)
{
  if (flag[0] == 'a')
  {
    if (i < top / 2)
		  return ("rra");
		else
	    return ("ra");
  }
  else if (flag[0] == 'b')
  {
    if (i < top / 2)
		  return ("rrb");
		else
	    return ("rb");
  }
  else
	return (NULL);
}

static int	get_move_count(int i, int top)
{
	if (i < top / 2)
		return (i + 1);
	return (top - i);
}

char	**generate_moves(int top, char *flag)
{
	char	**moves;
	int		i;

	moves = malloc((top + 1) * sizeof(char *));
	if (!moves)
		return (NULL);
	i = 0;
	while (i < top)
	{
		moves[i] = fill_moves(get_move_count(i, top), get_move_type(i, top, flag));
		if (!moves[i])
		{
			while (i > 0)
				free(moves[--i]);
			free(moves);
			return (NULL);
		}
		i++;
	}
	moves[top] = NULL;
	return (moves);
}