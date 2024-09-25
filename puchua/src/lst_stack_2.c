/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_stack_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:18:37 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 10:38:18 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	ft_lstclear_stack(t_stack **stack)
{
	t_stack	*cpstack;

	if (stack != 0)
	{
		while (*stack != 0)
		{
			cpstack = (*stack)->next;
			ft_lstdelone_stack(*stack);
			(*stack) = cpstack;
		}
	}
}

void	ft_lstdelone_stack(t_stack *stack)
{
	if (stack != 0)
	{
		free(stack);
	}
}
