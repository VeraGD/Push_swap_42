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

typedef struct s_ps
{
	int		data;
    char    *next;
}	t_ps;

char	**ft_split(char const *s, char c);

int		ft_strlen(const char *str);

int	ft_atoi(const char *nptr);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);

//printf

int		ft_putchar(char c, int cont);

int		ft_putstr(char *str, int cont);

int		ft_putnbr(int nb, int cont);

int		ft_putnbr_u(unsigned int nb, int cont);

int		ft_putnbr_hexa(unsigned int nb, int cont, char d);

int		ft_putptr_hexa(unsigned long nb, int cont);

int		ft_printf(char const *format, ...);

int		ft_printf_bonus(char const *format, ...);

#endif