/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcuevas- <lcuevas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:45:27 by lcuevas-          #+#    #+#             */
/*   Updated: 2023/10/02 15:01:26 by lcuevas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*
pasa a mayuscula

#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'p';
	printf("%c\n", ft_toupper(c));
	printf("%c\n", toupper(c));
	return (0);
}*/
