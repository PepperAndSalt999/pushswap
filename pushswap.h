/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pushswap.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rpicot <rpicot@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/25 06:22:25 by rpicot        #+#    #+#                 */
/*   Updated: 2022/08/08 22:00:43 by rpicot        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

enum	e_pushswap_choices
{
	push_a,
	push_b,
	swap_a,
	swap_b,
	swap_ab,
	rotate_a,
	rotate_b,
	rotate_ab,
	reverse_rotate_a,
	reverse_rotate_b,
	reverse_rotate_ab
};

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_metadata
{
	int	stack_size;
	int	bit_size;	
}	t_metadata;

char	**ft_split(char const *s, char c);
int		ft_double_strlen(char **s);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

//Init stacks
void	init_stacks(t_stack **stacks);
void	init_metadata(t_metadata *metadata, int argc,
			char ***array_charnums, char **argv);
void	checker_main(t_stack **stack_a, char ***array_charnums);
char	**init_lookup(char **lookup);
void	fill_index(t_stack *stack_static);
void	link_last_nodes(t_stack **stack);
void	loop_through_char_nums(char **array_charnums, t_stack **stack_a);

//Sorting Utils
void	sort_stack_main(t_stack	*stack_a, t_stack *stack_b,
			char **lookup, t_metadata *metadata);
t_stack	*sort_three(t_stack *stack_a, t_stack *stack_b, char **lookup);
void	sort_five(t_stack *stack_a, t_stack *stack_b,
			char **lookup, t_metadata *metadata);
int		is_stack_sorted(t_stack *stack_a);
int		is_set_sorted(t_stack *stack);

//Pushswap Utils
void	push(t_stack **stack_a, t_stack **stack_b,
			int choice, char **lookup);
t_stack	*rotate(t_stack *stack_a, t_stack *stack_b, int choice, char **lookup);
void	swap(t_stack *stack_a, t_stack *stack_b, int choice, char **lookup);
t_stack	*reverse_rotate(t_stack *stack_a,
			t_stack *stack_b, int choice, char **lookup);

//List utils
void	ft_lstadd_back(t_stack *lst, t_stack *new);
void	ft_push(t_stack **stack_a, int value);
t_stack	*ft_lstfirst(t_stack *lst);
t_stack	*ft_lstnew(t_stack *node, int value);

//Error _management
void	error_display(void);

//Writing utils
void	ft_putstr(char *str, int code);
void	print_result(int choice);

//Testing utils
char	*ft_itoa(int n);
void	ft_lst_size_utils(t_stack *lst);
void	check_input(char **argv, int argc);

#endif
