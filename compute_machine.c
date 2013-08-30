#include <stddef.h>
#include "calc.h"

int		compute_parenthesis(t_operation *op, int i, int j)
{
	while (op->str_ready[i] != '\0')
	{
		if (op->str_ready[i] == '(')
		{
			if (j == - 1 || j > 0)
			{
				j = 0;
			}
		}
		if (op->str_ready[i] == ')')
		{
			op->end = i;
			op->beginning = i - j;
			return (compute_op(op, op->end - 2, op->end));
		}
		i++;
		if (j != - 1)
		{
			j++;
		}
	}
	return (compute_op(op, op->end - 2, op->end));
}

int		compute_op(t_operation *op, int i, int j)
{
	t_mlist	*list_op;

	list_op = init_list();
	while (i >= op->beginning)
	{
		if (op->str_ready[i] == '-' && (OPER(op->str_ready[i - 1])))
		{
			i = i - 1;
			list_op = fpush(list_op, OPSTR[j], str_to_int(op, i + 1, j - 1));
			j = i;
		}
		else if (OPER(op->str_ready[i]) || i == op->beginning)
		{
			list_op = fpush(list_op, OPSTR[j], str_to_int(op, i + 1, j - 1));
			j = i;
		}
		i = i - 1;
	}
	return (write_computed(0, op, do_the_math(op, list_op)));
}

int		do_the_math(t_operation *op, t_mlist *list_op)
{
	t_sub_op	*tmp;

	tmp = list_op->head;
	while (tmp != NULL)
	{
		if (PRIOR(tmp->oper))
		{
			tmp = do_calc(tmp, list_op);
		}
		else
		{
			tmp = tmp->next;
		}
	}
	tmp = list_op->head;
	while (tmp->oper != ')' && tmp->oper != '\0' && tmp->next != NULL)
	{
		tmp = do_calc(tmp, list_op);
	}
	op->result = tmp->nbr;
	return (tmp->nbr);
}

void	simple_math(t_sub_op *new_couple, t_sub_op *tmp)
{
	tmp = tmp->next;
	if (new_couple->oper == '%')
	{
		new_couple->nbr = new_couple->nbr % tmp->nbr;
	}
	else if (new_couple->oper == '*')
	{
		new_couple->nbr = new_couple->nbr * tmp->nbr;
	}
	else if (new_couple->oper == '/')
	{
		new_couple->nbr = new_couple->nbr / tmp->nbr;
	}
	else if (new_couple->oper == '+')
	{
		new_couple->nbr = new_couple->nbr + tmp->nbr;
	}
	else if (new_couple->oper == '-')
	{
		new_couple->nbr = new_couple->nbr - tmp->nbr;
	}
}
