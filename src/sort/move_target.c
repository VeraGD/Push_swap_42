#include "../../push_swap.h"

t_stack *aux_move_a(char **move_a, char **move_b, int j, int i, t_stack *t)
{
    if (move_a != NULL)
    {
        ft_printf("entra a\n");
        while (move_a[j] != NULL)
        {
            if (move_a[j][0] == 'r' && move_a[j][1] == 'r')
                rev_rot("rra", t);
            else if (move_a[j][0] == 'r')
                rot("ra", t);
            j++;
        }
    }
    if (move_b != NULL)
    {
        while (move_b[i] != NULL)
            {
                if (move_b[i][0] == 'r' && move_b[i][1] == 'r')
                    rev_rot("rrb", t);
                else if (move_b[i][0] == 'r')
                    rot("rb", t);
                i++;
            }
    }
    return (t);
}

static int     aux_rrr(t_stack *t, int j)
{
    rev_rot("rrr", t);
    j++;
    return (j);
}

static int     aux_rr(t_stack *t, int j)
{
    rot("rr", t);
    j++;
    return (j);
}

t_stack    *made_move(t_stack *t, char **move_b, char **move_a)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (move_a != NULL && move_b != NULL)
    {
        while (move_b[i] != NULL)
        {
            if (move_b[i][0] == 'r' && move_b[i][1] == 'r')
            {
                if (move_a[j][0] == 'r' && move_a[j][1] == 'r')
                    j = aux_rrr(t, j);
                else
                    rev_rot("rrb", t);
            }
            else if (move_b[i][0] == 'r')
            {
                if (move_a[j][0] == 'r' && move_a[j][1] == 'a')
                    j = aux_rr(t, j);
                else
                    rot("rb", t);
            }
            i++;
        }
    }
    return (aux_move_a(move_a,move_b, j, i, t));
}

t_stack    *move_top_and_push(t_stack *t, int index)
{
    char **moves;
    char **move_b;
    char **move_a;

    moves = generate_moves(t->topb, "b"); // muev los del b
    //ft_printf("ss %s\n", moves[t->target[index]]);
    if (moves[t->target[index]] != NULL)
        move_b = ft_split(moves[t->target[index]], ' ');
    else
        move_b = NULL;
    moves = generate_moves(t->topa, "a");
    //ft_printf("ss %s\n", moves[index]);
    if (moves[index] != NULL)
        move_a = ft_split(moves[index], ' ');
    else
        move_a = NULL;
    t = made_move(t, move_b, move_a);
    pb(t);
    return (t);
}
