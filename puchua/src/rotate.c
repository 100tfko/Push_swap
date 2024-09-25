/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:09:51 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 10:10:03 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	ft_lstadd_back_stack(stack, tmp);
}

void	ft_rotate_a(t_data *data)
{
	ft_rotate(&data->stack_a);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_data *data)
{
	ft_rotate(&data->stack_b);
	ft_printf("rb\n");
}

void	ft_rotate_r(t_data *data)
{
	ft_rotate(&data->stack_a);
	ft_rotate(&data->stack_b);
	ft_printf("rr\n");
}
