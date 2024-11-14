#include "../../push_swap.h"

int     get_min_final(t_stack *t)
{
    int     i;
    int     *num;
    int     min;

    num = t->stack_a;
    i = t->topa;
    min = i - 1;
    while(i >= 0)
    {
        if(num[i] < num[min])
            min = i;
        // else
        //     max = i + 1;
        i--;
    }
    return (min);
}

t_stack     *get_top(int min, t_stack *t)
{
    int mitad;
    int i;

    mitad = (t->topa + 1) / 2;
    i = min;
    if (i < mitad)
    {
        while (i >= 0)
        {
            rev_rot("rra", t);
            i--;
        }
    }
    else
    {
        if (i != t->topa)
        {
            while (i < t->topa)
            {
                rot("ra", t);
                i++;
            }
        }
    }
    return (t);
}
