#include <stdlib.h>
#include "calc.h"

int		calc(char *operation)
{
	t_operation	op;

	if ((op.str_ready = malloc(sizeof(char) * ft_custom_strlen(operation))))
	{
		op.result = 0;
		op.braces_nbr = 0;
		del_blanks_counts_operators(operation, &op);
		compute_the_shit(&op);
		return (op.result);
	}
	else
	{
		return (0);
	}
}

char	*del_blanks_counts_operators(char *str, t_operation *op)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	op->lenght_str_ready = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			op->str_ready[j] = str[i];
			j++;
			op->lenght_str_ready = op->lenght_str_ready + 1;
		}
		if (str[i] == '(')
		{
			op->braces_nbr = op->braces_nbr + 1;
		}
		i++;
	}
	op->str_ready[j] = '\0';
	return (op->str_ready);
}

int		ft_custom_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			j++;
		}
		i++;
	}
	return (i - j);
}

int		compute_the_shit(t_operation *op)
{
	if (op->braces_nbr > 0)
	{
		compute_parenthesis(op, 0, -1);
		op->braces_nbr = op->braces_nbr - 1;
		compute_the_shit(op);
		return (0);
	}
	op->beginning = -1;
	op->end = op->lenght_str_ready;
	return (compute_op(op, op->lenght_str_ready - 1, op->lenght_str_ready));
}
