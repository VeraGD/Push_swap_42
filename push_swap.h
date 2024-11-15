/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veragarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:22:35 by veragarc          #+#    #+#             */
/*   Updated: 2024/11/15 11:27:12 by veragarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdarg.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_push
{
	int	*stack_a;
	int	*stack_b;
	int	*target;
	int	*cheap;
	int	topa;
	int	topb;
}	t_stack;

void	free_split(char **split);
void	free_struct(t_stack *struct_ps);
void	free_moves(char **moves, int top);

char	**ft_split(char const *s, char c);
int		ft_strlen(const char *str);
int		ft_atoi(const char *nptr);
char	*ft_strcat(char *dest, const char *src);

int		ft_printf(char const *format, ...);

int		ft_strlen_double(char **split);
int		*ft_reverse(int *num, int len);
int		len_stack(int argc, char **argv);

int		check_caracter(char *str);
int		check_double(int *str, int len);
int		*numbers_string(char *str);
int		*check_more_argv(int argc, char **argv);

t_stack	*inicialization(int *num, int argc, char **argv);

t_stack	*sort_two(t_stack *t);
t_stack	*sort_three(t_stack *t);
t_stack	*sort_four(t_stack *t);
t_stack	*sort_five(t_stack *t);
t_stack	*choose_sort(t_stack *t);

t_stack	*turk_algorithm(t_stack *t);
t_stack	*calculate_target_min_all(t_stack *t);
t_stack	*target_min(t_stack *t);
t_stack	*target_max(t_stack *t);

void	rev_rot(char *str, t_stack *t);
void	rot(char *str, t_stack *t);
void	swap(char *str, t_stack *t);
void	pa(t_stack *t);
void	pb(t_stack *t);

char	**generate_moves(int top, char *flag);
t_stack	*move_top_and_push(t_stack *t, int index);

t_stack	*move_target_max(t_stack *t, int index);
int		get_min_final(t_stack *t);
t_stack	*get_top(int min, t_stack *t);

int		calculate_target_minima(int a, t_stack *t);
void	handle_rrr(t_stack *t, char **move_a, int *i, int *j);
void	handle_r(t_stack *t, char **move_a, int *i, int *j);

#endif
