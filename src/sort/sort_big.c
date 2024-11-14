#include "../../push_swap.h"

static void    push_two_first(t_stack *t)
{
    pb(t);
    pb(t);
}

/* static int     get_min(t_stack *t)
{
    int     i;
    int     *num;
    int     min;

    num = t->cheap;
    i = t->topa;
    if (t->topa == 0)
        return (i);
    min = i - 1;
    if (num != NULL)
    {
        while(i >= 0)
        {
            if(num[i] < num[min])
                min = i;
            // else
            //     max = i + 1;
            i--;
        }
    }
    return (min);
} */

static int get_min(t_stack *t)
{
    int i;
    int *num;
    int min;

    num = t->cheap;
    i = t->topa;

    // Si el arreglo está vacío, retornar -1 (o alguna señal de error)
    if (t->topa < 0 || num == NULL) {
        return -1;
    }

    // Inicializar min con el primer índice (0) si solo hay un valor
    min = 0;

    // Si hay más de un valor, empezamos desde el último índice
    if (i >= 0) {
        min = i;
    }

    while (i >= 0) {
        if (num[i] < num[min]) {
            min = i;  // Actualizamos el índice del valor mínimo
        }
        i--;
    }

    return min;
}

/* static int get_min(t_stack *t)
{
    int min_index;
    int i;

    // Asegúrate de que t y t->cheap son válidos
    if (!t || !t->cheap || t->topa < 0) {
        return -1;  // Error, estructura no válida o arreglo vacío
    }

    // Inicializamos min_index con el primer índice
    min_index = 0;

    // Recorremos el arreglo t->cheap hasta el índice t->topa
    for (i = 1; i <= t->topa; i++) {
        if (t->cheap[i] < t->cheap[min_index]) {
            min_index = i;  // Actualizamos el índice del valor mínimo
        }
    }

    // Retornar el índice del valor mínimo
    return min_index;
} */

static t_stack     *sort_two_b(t_stack *t)
{
    int *nums;

    nums = t->stack_b;
    if (nums[0] < nums[1])
        swap("sb", t);
    return (t);
}

t_stack *turk_algorithm(t_stack *t)
{
    push_two_first(t);
    t = sort_two_b(t);
    //t = target_min(t);
    /* ft_printf("target %d\n", t->target[0]);
    ft_printf("target %d\n", t->target[1]);
    ft_printf("target %d\n", t->target[2]);
    ft_printf("target %d\n", t->target[3]);
    ft_printf("target %d\n", t->target[4]); */
    //t = calculate_target_min_all(t);
    /* ft_printf("op %d\n", t->cheap[0]);
    ft_printf("op %d\n", t->cheap[1]);
    ft_printf("op %d\n", t->cheap[2]);
    ft_printf("op %d\n", t->cheap[3]);
    ft_printf("op %d\n", t->cheap[4]); */
    /* ft_printf("top %d\n", t->stack_a[6]);
    ft_printf("top %d\n", t->stack_a[5]);
    ft_printf("top %d\n", t->stack_a[4]);
    ft_printf("top %d\n", t->stack_a[3]);
    ft_printf("top %d\n", t->stack_a[2]);
    ft_printf("top %d\n", t->stack_a[1]);
    ft_printf("bot %d\n", t->stack_a[0]);
    ft_printf("---------------------\n");
    ft_printf("top %d\n", t->stack_b[6]);
    ft_printf("top %d\n", t->stack_b[5]);
    ft_printf("top %d\n", t->stack_b[4]);
    ft_printf("top %d\n", t->stack_b[3]);
    ft_printf("top %d\n", t->stack_b[2]);
    ft_printf("top %d\n", t->stack_b[1]);
    ft_printf("bot %d\n", t->stack_b[0]);
    ft_printf("------------------"); */
    while (t->topa > 0)
    {
        t = target_min(t);
        /* int g = 19;
        while (g >= 0)
        {
            ft_printf("a %d\n", t->stack_a[g]);
            g--;
        }
        ft_printf("-----------------\n");
        int h = 19;
        while (h >= 0)
        {
            ft_printf("b %d\n", t->stack_b[h]);
            h--;
        }
        ft_printf("-----------------\n");
        int l = 19;
        while (l >= 0)
        {
            ft_printf("target %d\n", t->target[l]);
            l--;
        }
        ft_printf("-----------------\n");
        int m = 19;
        while (m >= 0)
        {
            ft_printf("op %d\n", t->cheap[m]);
            m--;
        }
        ft_printf("-----------------\n"); */
        int n = get_min(t);
        t = move_top_and_push(t, n);
        /* ft_printf("target %d\n", t->target[6]);
        ft_printf("target %d\n", t->target[5]);
        ft_printf("target %d\n", t->target[4]);
        ft_printf("target %d\n", t->target[3]);
        ft_printf("target %d\n", t->target[2]);
        ft_printf("target %d\n", t->target[1]);
        ft_printf("target %d\n", t->target[0]);
        ft_printf("---------------------\n");
        ft_printf("op %d\n", t->cheap[6]);
        ft_printf("op %d\n", t->cheap[5]);
        ft_printf("op %d\n", t->cheap[4]);
        ft_printf("op %d\n", t->cheap[3]);
        ft_printf("op %d\n", t->cheap[2]);
        ft_printf("op %d\n", t->cheap[1]);
        ft_printf("op %d\n", t->cheap[0]);
        ft_printf("---------------------\n");
        ft_printf("top %d\n", t->stack_a[6]);
        ft_printf("top %d\n", t->stack_a[5]);
        ft_printf("top %d\n", t->stack_a[4]);
        ft_printf("top %d\n", t->stack_a[3]);
        ft_printf("top %d\n", t->stack_a[2]);
        ft_printf("top %d\n", t->stack_a[1]);
        ft_printf("bot %d\n", t->stack_a[0]);
        ft_printf("---------------------\n");
        ft_printf("top %d\n", t->stack_b[6]);
        ft_printf("top %d\n", t->stack_b[5]);
        ft_printf("top %d\n", t->stack_b[4]);
        ft_printf("top %d\n", t->stack_b[3]);
        ft_printf("top %d\n", t->stack_b[2]);
        ft_printf("top %d\n", t->stack_b[1]);
        ft_printf("bot %d\n", t->stack_b[0]);
        ft_printf("------------------"); */
        //free(t->cheap);
        //free(t->target);
    }
    t = target_min(t);
    t = move_top_and_push(t, 0);
    /* int i = 19;
    while (i >= 0)
    {
        ft_printf("top %d\n", t->stack_b[i]);
        i--;
    }
    
    ft_printf("-----------------\n"); */


    /* int min = get_min_final(t);
    t = get_top(min, t); */

    while (t->topb > 0)
    {
        pa(t);
    }
    pa(t);

    /* int j = 19;
     while (j >= 0)
    {
        ft_printf("top %d\n", t->stack_a[j]);
        j--;
    }*/

    //ft_printf("-----------------\n"); 

    /* t->topb = 2;
    t->topa = 2;
    t->stack_a[0] = -3;
    t->stack_a[1] = 2;
    t->stack_a[2] = -5; */
    // a
    /* t->stack_b[0] = 10;
    t->stack_b[1] = 2;
    t->stack_b[2] = 1;  */

    //t = sort_three(t);

    // ft_printf("index menor %d\n", 3); 
    // ft_printf("target index menor %d\n", t->target[3]);// mando orden
    /* ft_printf("top %d\n", t->stack_a[2]);
    ft_printf("top %d\n", t->stack_a[1]);
    ft_printf("bot %d\n", t->stack_a[0]);
    ft_printf("-----------------\n");
    ft_printf("top %d\n", t->stack_b[2]);
    ft_printf("top %d\n", t->stack_b[1]);
    ft_printf("bot %d\n", t->stack_b[0]); */

    /* while (t->topb >= 30)
    {
        t = target_max(t);
        t = move_target_max(t, 0);
        //ft_printf("target %d\n", t->target[0]);
        // ft_printf("top %d\n", t->topa);
    } */

    /* ft_printf("tt %d\n", t->topa);
    ft_printf("top %d\n", t->stack_a[7]);
    ft_printf("top %d\n", t->stack_a[6]);
    ft_printf("top %d\n", t->stack_a[5]);
    ft_printf("top %d\n", t->stack_a[4]);
    ft_printf("top %d\n", t->stack_a[3]);
    ft_printf("top %d\n", t->stack_a[2]);
    ft_printf("top %d\n", t->stack_a[1]);
    ft_printf("bot %d\n", t->stack_a[0]); */

    int min = get_min_final(t);
    t = get_top(min, t);

    /* int k = 19;
    while (k >= 0)
    {
        ft_printf("top %d\n", t->stack_a[k]);
        k--;
    } */


    /* ft_printf("top %d\n", t->stack_b[6]);
    ft_printf("top %d\n", t->stack_b[5]);
    ft_printf("top %d\n", t->stack_b[4]);
    ft_printf("top %d\n", t->stack_b[3]);
    ft_printf("top %d\n", t->stack_b[2]);
    ft_printf("top %d\n", t->stack_b[1]);
    ft_printf("bot %d\n", t->stack_b[0]); */

    /* ft_printf("top %d\n", t->stack_a[6]);
    ft_printf("top %d\n", t->stack_a[5]);
    ft_printf("top %d\n", t->stack_a[4]);
    ft_printf("top %d\n", t->stack_a[3]);
    ft_printf("top %d\n", t->stack_a[2]);
    ft_printf("top %d\n", t->stack_a[1]);
    ft_printf("bot %d\n", t->stack_a[0]); */

    //ft_printf("move %s\n", s);
    
    return (t);
}

// ./a.out 276 -239 186 403 -192 148 -45 299 255 260 -100 -360 -349 232 408 384 32 407 -310 241