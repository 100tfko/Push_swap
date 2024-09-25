/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:36:58 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 10:39:31 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	ft_first_digit_is_bigger(t_data *data)
{
	if (data->stack_a->index < data->stack_a->next->next->index)
	{
		ft_swap_a(data);
		return ;
	}
	ft_rotate_a(data);
	if (data->stack_a->index > data->stack_a->next->index)
		ft_swap_a(data);
}

void	ft_second_digit_is_bigger(t_data *data)
{
	ft_reverse_rotate_a(data);
	if (data->stack_a->index > data->stack_a->next->index)
		ft_swap_a(data);
}

void	ft_sort_three(t_data *data)
{
	if (ft_check_order(data))
		return ;
	if (data->stack_a->index < data->stack_a->next->index)
		ft_second_digit_is_bigger(data);
	if (data->stack_a->index > data->stack_a->next->index)
		ft_first_digit_is_bigger(data);
}
