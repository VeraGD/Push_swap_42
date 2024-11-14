#include "../../push_swap.h"

static int     get_max(t_stack *t)
{
    int     *numb;
    int     top;
    int     i;
    int     max;

    numb = t->stack_b;
    top = t->topb;
    i = 0;
    max = 1;
    while(i < top)
    {
        if(numb[i] > numb[max])
            max = i;
        // else
        //     max = i + 1;
        i++;
    }
    return (max);
}

static int    calculate_target_minima(int a, t_stack *t)
{
    int     i;
    long     min;
    int     index;

    i = t->topb;
    min = -2147483649;
    index = get_max(t);
    while (i >= 0)
    {
        if (min == -2147483649 && a > t->stack_b[i])
        {
            min = t->stack_b[i];
            index = i;
        }
        else if (a > t->stack_b[i])
        {
            if (t->stack_b[i] > min)
            {
                min = t->stack_b[i];
                index = i;
            }
        }
        i--;
    } 
    return (index);
}

t_stack *target_min(t_stack *t)
{
    int i;
    int j;

    i = t->topa;
    j = 0;
    while (i >= 0)
    {
        t->target[j] = calculate_target_minima(t->stack_a[j], t);
        t = calculate_target_min_all(t);
        i--;
        j++;
    }
    return (t);
}