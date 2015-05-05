/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 11:55:46 by eboeuf            #+#    #+#             */
/*   Updated: 2014/04/16 11:55:46 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_putnbru(unsigned int n, int b)
{
	if (b == 'u')
		b = 10;
	else if (b == 'o')
		b = 8;
	else if (b == 'x' || b == 'p')
		b = 16;
	if (n < (unsigned int)b)
	{
		if (n < 10)
			return (ft_putchar(n + '0'));
		else
			return (ft_putchar(n - 10 + 'a'));
	}
	else
	{
		if ((n % b) < 10)
			return (ft_putnbru((n / b), b) + ft_putchar((n % b) + '0'));
		else
			return (ft_putnbru((n / b), b) + ft_putchar((n % b) - 10 + 'a'));
	}
}