/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:24:31 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 15:28:29 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

int	ft_check_order(t_data *data)
{
	t_stack	*tmp;
	t_stack	*aux;

	tmp = data->stack_a;
	aux = data->stack_a->next;
	while (aux)
	{
		if (tmp->value > aux->value)
			return (0);
		aux = aux->next;
		tmp = tmp->next;
	}
	return (1);
}

void	check_duplicate(long int value, t_data *data)
{
	t_stack	*tmp;

	tmp = data->stack_a;
	if (!tmp)
		return ;
	while (tmp)
	{
		if ((long int)tmp->value == value)
			ft_error(data);
		tmp = tmp->next;
	}
}

int	check_digits(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '-' || str[i][j] == '+')
			{
				j += 1;
				if (!(str[i][j] >= '0' && str[i][j] <= '9'))
					return (1);
			}
			if (!((str[i][j] >= '0' && str[i][j] <= '9'))
				|| str[i][j] == ' ')
				return (1);
			j += 1;
		}
		i += 1;
	}
	return (0);
}

void	ft_check(int argc, char **argv, t_data *data)
{
	data->str = NULL;
	if (argc == 1)
		exit(EXIT_FAILURE);
	if (argc == 2)
		data->str = ft_split(argv[1], ' ');
	if (argc > 2)
		data->str = argv + 1;
	if (check_digits(data->str))
		ft_error(data);
}
