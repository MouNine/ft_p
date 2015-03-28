/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:16:50 by eboeuf            #+#    #+#             */
/*   Updated: 2014/01/13 18:19:00 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_len(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		return (1 + ft_putnbr_len(-n));
	}
	else if (n >= 10)
		return (ft_putnbr_len(n / 10) + ft_putchar_len(n % 10 + 48));
	else
		return (ft_putchar_len(n + 48));
}
