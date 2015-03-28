/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:28:12 by eboeuf            #+#    #+#             */
/*   Updated: 2015/01/26 14:06:04 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*t;
	unsigned int	i;

	t = ft_strnew(len);
	i = 0;
	if (t)
	{
		while (i < len)
		{
			t[i] = s[i + start];
			i++;
		}
		t[i] = '\0';
	}
	return (t);
}
