#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>


typedef struct s_data
{
	int count;
	char convert;
	va_list ap;
}				t_data;

int	ft_printf(const char *format, ...);
void	ft_putchar(char c, t_data *me);
void	ft_putstr(char *s, t_data *me);
void	ft_putnbr(long long n, t_data *me, int base);
void	ft_putnbr_unsigned(long n, t_data *me);

#endif
