/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:49:46 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/20 18:41:52 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*---------------------------------   LIBS   ---------------------------------*/
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*--------------------------------   MACROS   --------------------------------*/
/*INTS*/
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/*--------------------------------   STRUCTS   -------------------------------*/

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	char	**str;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_data;

/*-------------------------------   FUNCTIONS   ------------------------------*/

//de momento tengo un caso marginal cuando la lusta es par
//justo la primera acciom negativa cuesta lo mimsmo en positivo que en negativo

// main file
int		main(int argc, char **argv);
void	ft_algorithms(t_data *data);
void	ft_sort_algorithm(t_data *data);
void	ft_select(t_data *data); //cambiarle nombre?

// sort_three file
void	ft_sort_three(t_data *data);
void	ft_second_digit_is_bigger(t_data *data);
void	ft_first_digit_is_bigger(t_data *data);

// actions file
void	ft_actions_positive(t_data *data, t_stack *tmp);
void	ft_actions_negative(t_data *data, t_stack *tmp);
void	ft_actions_positive_and_negative(t_data *data, t_stack *tmp);
void	ft_order_a(t_data *data);

// fill_struct file
void	ft_initialize(t_data *data);
void	ft_indexator(t_data *data);
void	ft_position(t_data *data);
void	ft_target_position(t_data *data);
void	ft_locate_index(t_data *data, t_stack *stack_b);

// check file
void	ft_check(int argc, char **argv, t_data *data);
int		check_digits(char **str);
void	check_duplicate(long int value, t_data *data);
int		ft_check_order(t_data *data);

// lst_stack_2 file
void	ft_lstclear_stack(t_stack **stack);
void	ft_lstdelone_stack(t_stack *stack);

// lst_stack file
void	ft_lstadd_front_stack(t_stack **lst, t_stack *new);
void	ft_lstadd_back_stack(t_stack **lst, t_stack *new);
int		ft_lstsize_stack(t_stack *stack);
t_stack	*ft_lstnew_stack(int value);

// cost file
void	ft_cost_b(t_data *data);
void	ft_cost_a(t_data *data);
int		ft_cost_total(t_stack *stack_b);
// tengo hueco para mejorar mi caso marginal de lista par en la parte dabajo

// reverse_rotate file
void	ft_reverse_rotate_r(t_data *data);
void	ft_reverse_rotate_b(t_data *data);
void	ft_reverse_rotate_a(t_data *data);
void	ft_reverse_rotate(t_stack **stack);

// rotate file
void	ft_rotate_r(t_data *data);
void	ft_rotate_b(t_data *data);
void	ft_rotate_a(t_data *data);
void	ft_rotate(t_stack **stack);

// push file
void	ft_push(t_stack **stack_src, t_stack **stack_dst);
void	ft_push_b(t_data *data);
void	ft_push_a(t_data *data);

// swap file
void	ft_swap_s(t_data *data);
void	ft_swap_b(t_data *data);
void	ft_swap_a(t_data *data);
void	ft_swap(t_stack **stack);

// exit file
void	ft_error(t_data *data);
void	ft_free_data(t_data *data);
void	ft_liberator(t_data *data);

#endif
