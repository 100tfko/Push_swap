/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:44:11 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/21 09:34:56 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

static int	ft_operation(char *line, t_data *data)
{
	if (!ft_strncmp(line, "sa\n", 3))
		return (ft_swap(&data->stack_a), 0);
	if (!ft_strncmp(line, "sb\n", 3))
		return (ft_swap(&data->stack_b), 0);
	if (!ft_strncmp(line, "ss\n", 3))
		return (ft_swap(&data->stack_a), ft_swap(&data->stack_b), 0);
	if (!ft_strncmp(line, "pa\n", 3))
		return (ft_push(&data->stack_b, &data->stack_a), 0);
	if (!ft_strncmp(line, "pb\n", 3))
		return (ft_push(&data->stack_a, &data->stack_b), 0);
	if (!ft_strncmp(line, "ra\n", 3))
		return (ft_rotate(&data->stack_a), 0);
	if (!ft_strncmp(line, "rb\n", 3))
		return (ft_rotate(&data->stack_b), 0);
	if (!ft_strncmp(line, "rr\n", 3))
		return (ft_rotate(&data->stack_a), ft_rotate(&data->stack_b), 0);
	if (!ft_strncmp(line, "rra\n", 4))
		return (ft_reverse_rotate(&data->stack_a), 0);
	if (!ft_strncmp(line, "rrb\n", 4))
		return (ft_reverse_rotate(&data->stack_b), 0);
	if (!ft_strncmp(line, "rrr\n", 4))
		return (ft_reverse_rotate(&data->stack_a),
			ft_reverse_rotate(&data->stack_b), 0);
	return (1);
}

static int	ft_checker(t_data *data)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_operation(line, data))
			return (free (line), ft_printf("Error\n"), 1);
		free (line);
		line = get_next_line(0);
	}
	if (ft_check_order(data) && data->stack_b == NULL)
		return (ft_printf("OK\n"), 0);
	return (ft_printf("KO\n"), 1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	ft_check(argc, argv, data);
	data->stack_b = NULL;
	ft_initialize(data);
	ft_indexator(data);
	if (ft_checker(data))
		exit(EXIT_FAILURE);
	if (argc < 3)
		ft_free_data(data);
	ft_liberator(data);
}
