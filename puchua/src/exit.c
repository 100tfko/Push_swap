/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:14:51 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 16:18:31 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

void	ft_error(t_data *data)
{
	ft_putstr_fd("Error", 2);
	ft_liberator(data);
	exit(EXIT_FAILURE);
}

void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->str[i])
	{
		free(data->str[i]);
		i ++;
	}
	free(data->str);
}

void	ft_liberator(t_data *data)
{
	ft_lstclear_stack(&data->stack_a);
	ft_lstclear_stack(&data->stack_b);
	free(data);
}
