/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravily <mravily@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 09:01:02 by mravily           #+#    #+#             */
/*   Updated: 2021/09/09 18:30:05 by mravily          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

# include "libft.h"

# define PRINTPOS printf("%s line %d\n", __func__, __LINE__)

typedef struct s_element
{
	size_t				id;
	int					value;
	struct s_element	*next;
}						t_element;

typedef struct s_list
{
	t_element			*first;
}				t_list;

/* Debug function */
void		print_list();

/* Chain list function */
t_element	*ft_lstnew(int id, char *value);
t_list		*init_list(char **tab);
t_element	*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list *lst, t_element *new);
void		ft_lstadd_front(t_list *list, t_element *to_add);
void		create_chain_lst(char **argv, char **envp);

/* Sort Function */
void	switch_list(t_list *list);
void	push_list(t_list *list_1, t_list *list_2);

#endif