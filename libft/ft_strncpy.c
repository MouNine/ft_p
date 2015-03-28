/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 13:42:52 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/04 11:04:00 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		c;

	c = 0;
	if (dest && src && n)
	{
		while (c < n && src[c] != '\0')
		{
			dest[c] = src[c];
			c++;
		}
		if (ft_strlen(dest) < n || (src[c] == '\0' && ft_strlen(src) <= n))
			dest[c] = '\0';
		while (c < n)
		{
			dest[c] = '\0';
			c++;
		}
	}
	return (dest);
}
