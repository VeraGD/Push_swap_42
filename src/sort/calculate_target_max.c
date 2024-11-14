#include "../../push_swap.h"

static int get_min(t_stack *t)
{
    int *numb;
    int top;
    int i;
    int min_index;

    numb = t->stack_a;
    top = t->topa;
    i = 0;
    min_index = 0;
    while (i <= top)
    {
        if (numb[i] < numb[min_index])
            min_index = i;
        i++;
    }
    return min_index;
}


static int    calculate_target_maxima(int a, t_stack *t)
{
    int     i;
    long     max;
    int     index;

    i = t->topa;
    max = 2147483648;
    index = get_min(t);
    while (i >= 0)
    {
        if (max == 2147483648 && a < t->stack_a[i])
        {
            max = t->stack_a[i];
            index = i;
        }
        else if (a < t->stack_a[i])
        {
            if (t->stack_a[i] < max)
            {
                max = t->stack_a[i];
                index = i;
            }
        }
        i--;
    }
    return (index);
}

static t_stack    *calculate_cheap_min(int i, t_stack *t)
{
    int     *op_a;
    int     sizea;
    int num;

    sizea = t->topa + 1;
    if (sizea %  2 == 0)
        op_a = array_calculate_pair_cheap(t->topa);
    else
        op_a = array_calculate_odd_cheap(t->topa);
    num = op_a[i];
    t->cheap[0] = num + 1;
    return (t);
}

t_stack *target_max(t_stack *t)
{
    int i;

    i = t->topb;
    t->target[0] = calculate_target_maxima(t->stack_b[i], t);
    t = calculate_cheap_min(t->target[0], t);
    /* ft_printf("con el que calculo target %d\n", t->stack_b[i]);
    ft_printf("num target %d\n", t->target[0]);
    ft_printf("num op %d\n", t->cheap[0]); */
    return (t);
}