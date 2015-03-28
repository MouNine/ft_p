/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 13:36:07 by eboeuf            #+#    #+#             */
/*   Updated: 2015/01/26 13:41:09 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;

	i = 0;
	while ((src + i) && i < n)
	{
		*(char *)(dest + i) = *(char *)(src + i);
		if (*(char *)(src + i) == c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
