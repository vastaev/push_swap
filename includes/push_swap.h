#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack_elem
{
	int					order;
	int					value;
	struct s_stack_elem	*next;
}				t_stack_elem;

typedef struct s_stack
{
	int				size;
	t_stack_elem	*head;
}				t_stack;

//validation and indexing
t_stack			*validation_of_args(int argc, char **argv);
int				split_len(char **s);
void			free_split(char **s);
int				*bubble_sort(int *arrayOfNumbers, int size);
int				find_index_of_num(int num, const int *sortedArray);

//lists
t_stack_elem	*create_new_element(int value);
t_stack_elem	*find_last_in_list(t_stack_elem *elem);
void			add_to_end_of_stack(t_stack *stack, t_stack_elem *elem);

//utils
void			*error_msg(void);

#endif
