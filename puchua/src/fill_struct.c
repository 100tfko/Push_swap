/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:27:48 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 15:23:16 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	ft_locate_index(t_data *data, t_stack *stack_b)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	tmp = NULL;
	stack_a = data->stack_a;
	while (stack_a)
	{
		if (!tmp)
		{
			tmp = stack_a;
			stack_b->target_pos = tmp->pos;
		}
		if (tmp->index > stack_a->index)
		{
			tmp = stack_a;
			stack_b->target_pos = tmp->pos;
		}
		stack_a = stack_a->next;
	}
}

/*void	ft_locate_index(t_data *data, t_stack *tmp)
{
	t_stack	*stack_a;

	stack_a = data->stack_a;
	while (stack_a)
	{
		if (!tmp)
		{
			tmp = stack_a;
			data->stack_b->target_pos = tmp->pos;
		}
		if (tmp->index > stack_a->index)
		{
			tmp = stack_a;
			data->stack_b->target_pos = tmp->pos;
		}
		stack_a = stack_a->next;
	}
}*/

void	ft_target_position(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*tmp;

	stack_b = data->stack_b;
	while (stack_b)
	{
		tmp = NULL;
		stack_a = data->stack_a;
		while (stack_a)
		{
			if (stack_b->index < stack_a->index)
			{
				if (!tmp)
					tmp = stack_a;
				if (tmp->index > stack_a->index)
					tmp = stack_a;
				stack_b->target_pos = tmp->pos;
			}
			stack_a = stack_a->next;
		}
		if (!tmp)
			ft_locate_index(data, stack_b);
		stack_b = stack_b->next;
	}
}

void	ft_position(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		pos;

	pos = 1;
	stack_a = data->stack_a;
	while (stack_a)
	{
		stack_a->pos = pos;
		stack_a = stack_a->next;
		pos += 1;
	}
	pos = 1;
	stack_b = data->stack_b;
	while (stack_b)
	{
		stack_b->pos = pos;
		stack_b = stack_b->next;
		pos += 1;
	}
}

void	ft_indexator(t_data *data)
{
	t_stack	*tmp;
	t_stack	*aux;

	tmp = data->stack_a;
	while (tmp)
	{
		aux = data->stack_a;
		while (aux)
		{
			if (tmp->value > aux->value)
				tmp->index += 1;
			aux = aux->next;
		}
		tmp = tmp->next;
	}
}

void	ft_initialize(t_data *data)
{
	t_stack		*new_node;
	long int	value;
	int			i;

	i = 0;
	new_node = NULL;
	data->stack_a = NULL;
	while (data->str[i])
	{
		value = ft_atoi_long(data->str[i]);
		if (value > INT_MAX || value < INT_MIN)
			ft_error(data);
		check_duplicate(value, data);
		new_node = ft_lstnew_stack(value);
		ft_lstadd_back_stack(&data->stack_a, new_node);
		i += 1;
	}
}
