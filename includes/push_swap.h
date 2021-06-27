#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define HEAD 1
# define TAIL 0

# include "libft.h"

typedef struct s_stack_elem
{
	int					order;
	int					value;
	struct s_stack_elem	*next;
	struct s_stack_elem	*previous;
}				t_stack_elem;

typedef struct s_stack
{
	int				size;
	t_stack_elem	*head;
	t_stack_elem	*tail;
}				t_stack;

typedef struct s_command
{
	char				*name;
	struct s_command	*next;
}						t_command;

typedef struct s_command_list
{
	size_t				size;
	t_command			*head;
}						t_command_list;

typedef struct s_steps_info
{
	int				steps;
	int				isHead;
	int				stepsA;
	int				isHeadA;
	int				sumSteps;
	t_stack_elem	*minA;
}				t_steps_info;

typedef struct s_alg_vars
{
	int		mid;
	int		prev_max;
	int		next_min;
	int		max;
}			t_alg_vars;

//validation and indexing
t_stack			*validation_of_args(int argc, char **argv);
int				split_len(char **s);
void			free_split(char **s);
int				*bubble_sort(int *arrayOfNumbers, int size);
int				find_index_of_num(int num, const int *sortedArray);

//solving
void	solve(t_stack *stackA, t_stack *stackB, t_command_list *list,
			  t_alg_vars *algVars);
int	calc_steps_b(t_stack_elem *ptr, int startRange, int endRange, int flag);
int	calc_steps_a(t_stack_elem *ptr, int startRange, int flag);




//lists
t_stack_elem	*create_new_element(int value);
void			add_to_stack(t_stack *stack, t_stack_elem *elem);

//actions
void			sn(t_stack *stack, const char *name, t_command_list *list);
void			ss(t_stack *a,
					t_stack *b,
					const char *name,
					t_command_list *list);
void			rn(t_stack *stack, const char *name, t_command_list *list);
void			rrn(t_stack *stack, const char *name, t_command_list *list);
void			pn(t_stack *to, t_stack *from, const char *name, t_command_list *list);

//commands
void			add_command_to_list(t_command_list *list, t_command *command);
void			print_commands(t_command_list *list);
t_command		*create_command(const char *name);

//freeing
void			free_stack(t_stack *stack);
void			free_commands(t_command_list *list);

//utils
void			*error_msg(void);

#endif
