#include "../../push_swap.h"

static t_stack    *made_move(t_stack *t, char **move_a)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (move_a != NULL)
    {
        while (move_a[i] != NULL)
        {
            if (move_a[i][0] == 'r' && move_a[i][1] == 'r')
                    rev_rot("rra", t);
            else if (move_a[i][0] == 'r' && move_a[i][1] == 'a')
                rot("ra", t);
            i++;
        }
    }
    return (t);
}

t_stack    *move_target_max(t_stack *t, int index)
{
    char **moves;
    char **move_a;

    moves = generate_moves(t->topa, "a"); 
    if (moves[t->target[index]] != NULL)
        move_a = ft_split(moves[t->target[index]], ' ');
    else
        move_a = NULL;
    t = made_move(t, move_a);
    pa(t);
    return (t);
}