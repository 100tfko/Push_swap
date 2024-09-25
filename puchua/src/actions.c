/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:34:48 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 14:59:03 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	ft_order_a(t_data *data)
{
	t_stack	*tmp;
	int		size;

	tmp = data->stack_a;
	while (tmp->index != 1)
		tmp = tmp->next;
	size = ft_lstsize_stack(tmp);
	if (size % 2 == 1)
		size += 1;
	ft_position(data);
	if (tmp->pos > size)
	{
		while (data->stack_a->index != 1)
		{
			ft_reverse_rotate_a(data);
		}
	}
	else
	{
		while (data->stack_a->index != 1)
		{
			ft_rotate_a(data);
		}
	}
}

void	ft_actions_positive_and_negative(t_data *data, t_stack *tmp)
{
	while (tmp->cost_a != 0 || tmp->cost_b != 0)
	{
		if (tmp->cost_a > 0)
		{
			ft_rotate_a(data);
			tmp->cost_a -= 1;
		}
		if (tmp->cost_a < 0)
		{
			ft_reverse_rotate_a(data);
			tmp->cost_a += 1;
		}
		if (tmp->cost_b > 0)
		{
			ft_rotate_b(data);
			tmp->cost_b -= 1;
		}
		if (tmp->cost_b < 0)
		{
			ft_reverse_rotate_b(data);
			tmp->cost_b += 1;
		}
	}
}

/*void	ft_actions_positive_and_negative(t_data *data, t_stack *tmp)
{
	if (tmp->cost_a > tmp->cost_b)
	{
		while (tmp->cost_a != 0)
		{
			ft_rotate_a(data);
			tmp->cost_a -= 1;
		}
		while (tmp->cost_b != 0)
		{
			ft_reverse_rotate_b(data);
			tmp->cost_b += 1;
		}
	}
	else
	{
		while (tmp->cost_a != 0)
		{
			ft_reverse_rotate_a(data);
			tmp->cost_a += 1;
		}
		while (tmp->cost_b != 0)
		{
			ft_rotate_b(data);
			tmp->cost_b -= 1;
		}
	}
}*/

void	ft_actions_negative(t_data *data, t_stack *tmp)
{
	while (tmp->cost_a != 0 && tmp->cost_b != 0)
	{
		ft_reverse_rotate_r(data);
		tmp->cost_a += 1;
		tmp->cost_b += 1;
	}
	while (tmp->cost_a != 0)
	{
		ft_reverse_rotate_a(data);
		tmp->cost_a += 1;
	}
	while (tmp->cost_b != 0)
	{
		ft_reverse_rotate_b(data);
		tmp->cost_b += 1;
	}
}

void	ft_actions_positive(t_data *data, t_stack *tmp)
{
	while (tmp->cost_a != 0 && tmp->cost_b != 0)
	{
		ft_rotate_r(data);
		tmp->cost_a -= 1;
		tmp->cost_b -= 1;
	}
	while (tmp->cost_a != 0)
	{
		ft_rotate_a(data);
		tmp->cost_a -= 1;
	}
	while (tmp->cost_b != 0)
	{
		ft_rotate_b(data);
		tmp->cost_b -= 1;
	}
}
