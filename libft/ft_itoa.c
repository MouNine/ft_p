/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:42:59 by eboeuf            #+#    #+#             */
/*   Updated: 2015/01/26 13:40:18 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void		ft_addnbr(int n, char *str)
{
	if (n != 0)
	{
		if (n / 10 != 0)
			ft_addnbr(n / 10, str - 1);
		n %= 10;
		if (n < 0)
			n = -n;
		*str = n + '0';
	}
	else
		*str = '0';
}

char			*ft_itoa(int n)
{
	char	*str;
	int		ncpy;
	int		size;

	ncpy = n;
	size = 1;
	while (ncpy >= 10 || ncpy <= -10)
	{
		size++;
		ncpy /= 10;
	}
	if (n < 0)
		size++;
	str = (char *)malloc((size + 1) * sizeof(*str));
	if (n < 0)
		str[0] = '-';
	ft_addnbr(n, &str[size - 1]);
	str[size] = 0;
	return (str);
}
