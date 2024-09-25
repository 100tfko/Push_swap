/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:09:02 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/21 09:44:45 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	ft_push(t_stack **stack_src, t_stack **stack_dst)
{
	t_stack	*tmp;

	if (!ft_lstsize_stack(*stack_src))
		return ;
	tmp = *stack_src;
	*stack_src = (*stack_src)->next;
	ft_lstadd_front_stack(stack_dst, tmp);
}

void	ft_push_b(t_data *data)
{
	ft_push(&data->stack_a, &data->stack_b);
	ft_printf("pb\n");
}

void	ft_push_a(t_data *data)
{
	ft_push(&data->stack_b, &data->stack_a);
	ft_printf("pa\n");
}
