#ifndef CALC_H
# define CALC_H
# define OPER(S) S == 37 || S == 42 || S == 43 || S == 45 || S == 47
# define PRIOR(S) S == 37 || S == 42 || S == 47
# define OPSTR op->str_ready

typedef struct 	s_sub_op	t_sub_op;
struct			s_sub_op
{
	int			nbr;
	char		oper;
	t_sub_op	*next;
	t_sub_op	*prev;
};
typedef struct	s_mlist		t_mlist;
struct			s_mlist
{
	int			lenght;
	t_sub_op	*head;
	t_sub_op	*tail;
};
typedef struct 	s_operation	t_operation;
struct						s_operation
{
	char		*str_ready;
	int			lenght_str_ready;
	int			beginning;
	int			end;
	int			result;
	int			braces_nbr;
};
int				calc(char *str);
char			*del_blanks_counts_operators(char *str, t_operation *op);
int				compute_the_shit(t_operation *op);
int				compute_parenthesis(t_operation *op, int i, int j);
int				compute_op(t_operation *op, int i, int j);
int				str_to_int(t_operation *op, int beginning, int end);
int				write_computed(int i, t_operation *op, int result);
int				ft_custom_strlen(char *str);
t_mlist			*fpush(t_mlist *list_op, char oper, int nbr);
t_mlist			*init_list(void);
int				do_the_math(t_operation *op, t_mlist *list_op);
void			simple_math(t_sub_op *new_couple, t_sub_op *tmp);
t_sub_op		*do_calc(t_sub_op *tmp, t_mlist *list_op);
void			itoa(int n, char* out);
void 			reverse(char* str, int length);
void			clean_string(t_operation *op);
int				ft_putnbr(int nbr);
void			ft_putchar(char c);

#endif
