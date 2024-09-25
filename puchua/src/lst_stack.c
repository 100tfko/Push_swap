/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:17:00 by lcuevas-          #+#    #+#             */
/*   Updated: 2024/02/12 10:38:24 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/push_swap.h"

int	ft_lstsize_stack(t_stack *lst)
{
	int		n;

	n = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		n += 1;
	}
	return (n);
}

void	ft_lstadd_front_stack(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
}

void	ft_lstadd_back_stack(t_stack **lst, t_stack *new)
{
	t_stack	*back;

	back = *lst;
	if (!back)
	{
		*lst = new;
		return ;
	}
	while (back->next != 0)
		back = back->next;
	back->next = new;
	new->next = NULL;
	return ;
}

t_stack	*ft_lstnew_stack(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->index = 1;
	new_node->pos = 0;
	new_node->target_pos = 0;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->next = NULL;
	return (new_node);
}
