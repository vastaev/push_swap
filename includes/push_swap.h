#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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

//validation and indexing
t_stack			*validation_of_args(int argc, char **argv);
int				split_len(char **s);
void			free_split(char **s);
int				*bubble_sort(int *arrayOfNumbers, int size);
int				find_index_of_num(int num, const int *sortedArray);

//lists
t_stack_elem	*create_new_element(int value);
t_stack_elem	*find_last_in_list(t_stack_elem *elem);
t_command		*find_last_command(t_command *elem);
void			add_to_end_of_stack(t_stack *stack, t_stack_elem *elem);

//commands
void			add_command_to_list(t_command_list *list, t_command *command);
t_command		*create_command(const char *name);

//utils
void			*error_msg(void);

#endif
