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

int	ft_putpoint(long unsigned int n)
{
	if (n < 16)
	{
		if (n < 10)
			return (ft_putstr("0x") + ft_putchar(n + '0'));
		else
			return (ft_putstr("0x") + ft_putchar(n - 10 + 'a'));
	}
	else
	{
		if ((n % 16) < 10)
			return (ft_putpoint(n / 16) + ft_putchar((n % 16) + '0'));
		else
			return (ft_putpoint(n / 16) + ft_putchar((n % 16) - 10 + 'a'));
	}
}