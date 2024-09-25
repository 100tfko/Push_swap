/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:10:59 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 10:11:26 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*aux;

	aux = *stack;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack;
	*stack = tmp->next;
	(*stack)->next = aux;
	tmp->next = NULL;
}

void	ft_reverse_rotate_a(t_data *data)
{
	ft_reverse_rotate(&data->stack_a);
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_data *data)
{
	ft_reverse_rotate(&data->stack_b);
	ft_printf("rrb\n");
}

void	ft_reverse_rotate_r(t_data *data)
{
	ft_reverse_rotate(&data->stack_a);
	ft_reverse_rotate(&data->stack_b);
	ft_printf("rrr\n");
}
