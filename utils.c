#include "calc.h"

int		str_to_int(t_operation *op, int beginning, int end)
{
	int	to_int;
	int	sign;

	to_int = 0;
	sign = 1;
	if (op->str_ready[beginning] == '-')
	{
		sign = - 1;
		beginning++;
	}
	while (beginning <= end)
	{
		to_int = to_int * 10 + op->str_ready[beginning] - '0';
		beginning++;
	}
	return (sign*to_int);
}

void	itoa(int n, char* out)
{
	int	sign;
	int	i;

	sign = n < 0 ? 1 : 0;
	i = 0;
	if (n == 0)
	{
		out[i++] = '0';
	}
	else if (n < 0)
	{
		out[i++] = '-';
		n = -n;
	}
	while (n > 0)
	{
		out[i++] = '0' + n % 10;
		n /= 10;
	}
	out[i] = '\0';
	reverse(out + sign, i - sign);
}

void	reverse(char* str, int lenght)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = lenght - 1;
	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

int		write_computed(int i, t_operation *op, int result)
{
	char	result_as_a_fucking_char_again[12];

	itoa(result, result_as_a_fucking_char_again);
	while (op->beginning <= op->end)
	{
		while (result_as_a_fucking_char_again[i] != '\0')
		{
			op->str_ready[op->beginning] = result_as_a_fucking_char_again[i];
			i++;
			op->beginning = op->beginning + 1;
		}
		op->str_ready[op->beginning] = 'x';
		op->beginning = op->beginning + 1;
	}
	i = 0;
	clean_string(op);
	return (result);
}

void	clean_string(t_operation *op)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (op->str_ready[i] != '\0')
	{
		if (op->str_ready[i] != 'x')
		{
			op->str_ready[j] = op->str_ready[i];
			j++;
		}
		i++;
	}
	op->str_ready[j] = '\0';
	op->lenght_str_ready = j;
}
