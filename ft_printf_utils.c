#include "ft_printf.h"

void	ft_putchar(char c, t_data *me)
{
	write(1, &c, 1);
	me->count++;
}

void	ft_putstr(char *s, t_data *me)
{
	int i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], me);
		i++;
	}
}

void	ft_putnbr(long long n, t_data *me, int base)
{
	long long x;
	char *str;
	
	x = n;
	if (me->convert == 'p' || me->convert == 'x')
		str = "0123456789abcdef";
	if (me->convert == 'X')
		str = "0123456789ABCDEF";
	if (me->convert == 'd' || me->convert == 'i')
		str = "0123456789";
	if (x < 0)
	{
		ft_putchar('-', me);
		x = -x;
	}
	if (x >= (unsigned long long)base)
	{
		ft_putnbr((x / base), me, base);
		ft_putnbr((x % base), me, base);
	}
	else
		ft_putchar((str[x]), me);
}

void	ft_putnbr_unsigned(long n, t_data *me)
{
	long x;

	if (n < 0)
	{
		x = 4294967295;
		x = (unsigned int)(x - n + 1);
	}
	else
		x = (unsigned int)n;
	if (x >= 9)
		ft_putnbr_unsigned((x / 10), me);
	ft_putchar((char)(x % 10 + 48), me);
}