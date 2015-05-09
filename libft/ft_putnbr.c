/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:44:43 by eboeuf            #+#    #+#             */
/*   Updated: 2015/05/08 08:36:16 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_putnbr(int n)
{
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	else if (n < 0)
		return (ft_putchar('-') + ft_putnbr(-n));
	else if (n >= 10)
		return (ft_putnbr(n / 10) + ft_putchar(n % 10 + '0'));
	else
		return (ft_putchar(n + 48));
	return (0);
}
