/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 13:39:38 by eboeuf            #+#    #+#             */
/*   Updated: 2015/01/27 10:20:54 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	char			*str1;
	char			*str2;

	i = 0;
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (s1 && s2)
	{
		while (((str1[i] != '\0') && (i < n))\
				|| ((str2[i] != '\0') && (i < n)))
		{
			if (str1[i] != str2[i])
				return ((unsigned char)str1[i] - (unsigned char)str2[i]);
			i++;
		}
	}
	return (0);
}
