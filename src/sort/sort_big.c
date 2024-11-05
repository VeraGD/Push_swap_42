#include "../../push_swap.h"

static void    push_two_first(t_stack *t)
{
    pb(t);
    pb(t);
}

static int     get_min(t_stack *t)
{
    int     i;
    int     *num;
    int     min;

    num = t->cheap;
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

t_stack *turk_algorithm(t_stack *t)
{
    push_two_first(t);
    t->topb = 2;
    t->topa = 4;
    t->stack_b[0] = 33;
    t->stack_b[1] = 12;
    t->stack_b[2] = 1;
    // a
    t->stack_a[0] = 13;
    t->stack_a[1] = 55;
    t->stack_a[2] = 14;
    t->stack_a[3] = 4;
    t->stack_a[4] = 66;
    t->stack_a[5] = 6;
    t = target_min(t);
    ft_printf("target %d\n", t->target[0]);
    ft_printf("target %d\n", t->target[1]);
    ft_printf("target %d\n", t->target[2]);
    ft_printf("target %d\n", t->target[3]);
    ft_printf("target %d\n", t->target[4]);
    //t = calculate_target_min_all(t);
    ft_printf("op %d\n", t->cheap[0]);
    ft_printf("op %d\n", t->cheap[1]);
    ft_printf("op %d\n", t->cheap[2]);
    ft_printf("op %d\n", t->cheap[3]);
    ft_printf("op %d\n", t->cheap[4]);
    while (t->topa > 2)
    {
        int m = get_min(t);
        t = move_top_and_push(t, m);
        // ft_printf("top %d\n", t->topa);
    }
    t = sort_three(t);
    // ft_printf("index menor %d\n", 3); 
    // ft_printf("target index menor %d\n", t->target[3]);// mando orden
    return (t);
}