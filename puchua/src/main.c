/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:44:25 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 15:53:39 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	ft_select(t_data *data)
{
	t_stack	*stack_b;
	t_stack	*tmp;
	int		cost_tmp;

	stack_b = data->stack_b;
	tmp = stack_b;
	cost_tmp = ft_cost_total(stack_b);
	while (stack_b)
	{
		if (cost_tmp > ft_cost_total(stack_b))
		{
			cost_tmp = ft_cost_total(stack_b);
			tmp = stack_b;
		}
		stack_b = stack_b->next;
	}
	if (tmp->cost_a == 0 && tmp->cost_b == 0)
		return ;
	else if (tmp->cost_a > 0 && tmp->cost_b > 0)
		ft_actions_positive(data, tmp);
	else if (tmp->cost_a < 0 && tmp->cost_b < 0)
		ft_actions_negative(data, tmp);
	else
		ft_actions_positive_and_negative(data, tmp);
}

void	ft_sort_algorithm(t_data *data)
{
	while (data->stack_a->next->next->next)
		ft_push_b(data);
	ft_sort_three(data);
	while (data->stack_b)
	{
		ft_position(data);
		ft_target_position(data);
		ft_cost_a(data);
		ft_cost_b(data);
		ft_select(data);
		ft_push_a(data);
	}
	ft_order_a(data);
}

void	ft_algorithms(t_data *data)
{
	int	n;

	n = ft_lstsize_stack(data->stack_a);
	if (n == 2)
		ft_swap_a(data);
	if (n == 3)
		ft_sort_three(data);
	else
		ft_sort_algorithm(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	ft_check(argc, argv, data);
	data->stack_b = NULL;
	ft_initialize(data);
	ft_indexator(data);
	if (ft_check_order(data))
		exit(EXIT_SUCCESS);
	ft_algorithms(data);
	if (argc < 3)
		ft_free_data(data);
	ft_liberator(data);
}
