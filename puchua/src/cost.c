/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:14:15 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 14:35:19 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

int	ft_cost_total(t_stack *stack_b)
{
	int	cost;

	if (stack_b->cost_a > 0 && stack_b->cost_b > 0)
	{
		if (stack_b->cost_a > stack_b->cost_b)
			cost = ft_abs(stack_b->cost_a);
		else
			cost = ft_abs(stack_b->cost_b);
	}
	else if (stack_b->cost_a < 0 && stack_b->cost_b < 0)
	{
		if (stack_b->cost_a > stack_b->cost_b)
			cost = ft_abs(stack_b->cost_b);
		else
			cost = ft_abs(stack_b->cost_a);
	}
	else
		cost = ft_abs(stack_b->cost_a) + ft_abs(stack_b->cost_b);
	return (cost);
}

void	ft_cost_a(t_data *data)
{
	t_stack	*tmp;
	int		size;
	int		up;

	tmp = data->stack_b;
	size = ft_lstsize_stack(data->stack_a);
	up = size / 2;
	if (size % 2 == 1)
		up += 1;
	while (tmp)
	{
		if (tmp->target_pos <= up)
			tmp->cost_a = (tmp->target_pos) - 1;
		else
			tmp->cost_a = (size - tmp->target_pos + 1) * (-1);
		tmp = tmp->next;
	}
}

void	ft_cost_b(t_data *data)
{
	t_stack	*tmp;
	int		size;
	int		up;

	tmp = data->stack_b;
	size = ft_lstsize_stack(data->stack_b);
	up = size / 2;
	if (size % 2 == 1)
		up += 1;
	while (tmp && up)
	{
		tmp->cost_b = (tmp->pos) - 1;
		tmp = tmp->next;
		up -= 1;
	}
	while (tmp)
	{
		tmp->cost_b = (size - tmp->pos + 1) * (-1);
		tmp = tmp->next;
	}
}
