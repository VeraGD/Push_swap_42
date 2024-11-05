#include "../../push_swap.h"

t_stack     *inicialization(int *num, int argc, char **argv)
{
    t_stack     *t;
    int     *nums;
    int len;

    // comprobacion memoria
    t = (t_stack *)malloc(sizeof(t_stack));
    nums = ft_reverse(num, len_stack(argc, argv));
    if (!nums || !t)
    {
        free(t);
        return (NULL);
    }
    len = len_stack(argc, argv);
    t->stack_a = nums;
    t->topa = len_stack(argc, argv) - 1;
    t->stack_b = (int *)malloc(len * sizeof(int));
    t->topb = -1;
    t->target = (int *)malloc(len * sizeof(int));
    t->cheap = (int *)malloc(len * sizeof(int));
    if (!t->stack_b || !t->target || !t->cheap) 
    {
        free(t);
        return (NULL);
    }
    return (t);
}

t_stack     *sort_two(t_stack *t)
{
    int *nums;

    nums = t->stack_a;
    if (nums[0] < nums[1])
        swap("sa", t);
    return (t);
}

int     its_sort(t_stack *t)
{
    int     i;
    int     *num;

    i = 0;
    num = t->stack_a;
    while (i < t->topa)
    {
        if (num[i] > num[i + 1])
            i++;
        else
            return (1);
    }
    return (0);
}

t_stack     *choose_sort(t_stack *t)
{
    int len;

    len = t->topa + 1;
    if (its_sort(t) == 1)
    {
        if (len == 2)
            t = sort_two(t);
        else if (len == 3)
            t = sort_three(t);
        else if (len == 4)
            t = sort_four(t);
        else if (len == 5)
            t = sort_five(t);
        else if (len > 5 && len <= 10)
            t = turk_algorithm(t);
    }
    return (t);
}