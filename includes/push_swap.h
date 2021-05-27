#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include <unistd.h>

typedef struct s_list
{
	int				value;
	int				order;
	int				flag;
	struct s_list	*next;
	struct s_list	*prev;

}				 t_list;

int		validation_of_args(int argc, char **argv);

int		ft_isdigit(int c);

#endif //PUSH_SWAP_PUSH_SWAP_H
