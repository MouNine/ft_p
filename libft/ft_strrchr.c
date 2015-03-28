/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 13:52:22 by eboeuf            #+#    #+#             */
/*   Updated: 2015/01/26 14:04:55 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	n;
	size_t	i;

	i = 0;
	n = ft_strlen((char *)s);
	if ((char)c == 0)
		return (char *)(s + n);
	while (i < n)
	{
		if (s[n - i] == (char)c)
			return ((char *)(&s[n - i]));
		i++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
