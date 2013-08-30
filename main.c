#include "calc.h"
#include <unistd.h>

int		main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(calc(av[1]));
		ft_putchar('\n');
	}
	return (0);
}

int		ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
	{
		return nbr = ft_putnbr(nbr / 10) - ft_putnbr(nbr % 10);
	}
	nbr += 48;
	write(1, &nbr, 1);
	return (0);
}

void	ft_putchar(char c)
{
		write(1, &c, 1);
}
