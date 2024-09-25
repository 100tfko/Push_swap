/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:07:21 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 15:55:09 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*swaper;

	if (ft_lstsize_stack(*stack) < 2)
		return ;
	swaper = *stack;
	*stack = (*stack)->next;
	swaper->next = (*stack)->next;
	(*stack)->next = swaper;
}

void	ft_swap_a(t_data *data)
{
	ft_swap(&data->stack_a);
	ft_printf("sa\n");
}

void	ft_swap_b(t_data *data)
{
	ft_swap(&data->stack_b);
	ft_printf("sb\n");
}

void	ft_swap_s(t_data *data)
{
	ft_swap(&data->stack_a);
	ft_swap(&data->stack_b);
	ft_printf("ss\n");
}
