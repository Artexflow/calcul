#include <stdlib.h>
#include "calc.h"

t_mlist		*init_list(void)
{
	t_mlist	*new_list;

	if ((new_list = malloc(sizeof(*new_list))))
	{
		new_list->lenght = 0;
		new_list->head = NULL;
		new_list->tail = NULL;
	}
	return (new_list);
}

t_mlist		*fpush(t_mlist *list_op, char oper, int nbr)
{
	t_sub_op	*new_couple;

	if ((new_couple = malloc(sizeof(t_sub_op))))
	{
		new_couple->nbr = nbr;
		new_couple->oper = oper;
		new_couple->prev = NULL;
		if (list_op->tail == NULL)
		{
			new_couple->next = NULL;
			list_op->head = new_couple;
			list_op->tail = new_couple;
		}
		else
		{
			list_op->head->prev = new_couple;
			new_couple->next = list_op->head;
			list_op->head = new_couple;
		}
		list_op->lenght++;
	}
	return (list_op);
}

t_sub_op	*do_calc(t_sub_op *tmp, t_mlist *list_op)
{
	t_sub_op	*new_couple;

	if ((new_couple = malloc(sizeof(new_couple))))
	{
		new_couple = tmp;
		simple_math(new_couple, tmp);
		new_couple->oper = tmp->next->oper;
		new_couple->next = tmp->next->next;
		if (new_couple->next == NULL)
		{
			list_op->tail = new_couple;
		}
		if (new_couple->prev == NULL)
		{
			list_op->head = new_couple;
		}
	}
	return (new_couple);
}
