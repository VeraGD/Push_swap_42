#include "../../push_swap.h"

int     main(int argc, char **argv)
{
    int    *num;
    t_stack *t;

    num = 0;
    if (argc == 2)
        num = numbers_string(argv[1]);
    else if (argc > 2) //  && argc <= 11
        num = check_more_argv(argc, argv);
    if (num != NULL)
    {
        t = inicialization(num, argc, argv);
        t = choose_sort(t);
        free_struct(t);
        free(num);
    }
    else
        ft_printf("Error\n");
}

// ccw -g3 src/error_control/error_control_more.c src/error_control/error_control_str.c src/operations/operations_push.c src/operations/operations_rev_rotate.c src/operations/operations_rotate.c src/operations/operations_swap.c src/sort/move_target_array.c src/sort/move_target.c src/sort/sort_big.c src/sort/sort_two_five.c src/sort/calculate_target_min.c src/sort/calculate_cheap_min.c src/error_control/error_checks.c src/sort/get_min_to_top.c src/sort/move_target_aux.c src/utils/ps_free.c src/utils/ps_utils.c src/initialization/ini.c src/initialization/main.c src/libft/libft.a src/printf/libftprintf.a  