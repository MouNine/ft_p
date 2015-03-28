/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 13:36:50 by eboeuf            #+#    #+#             */
/*   Updated: 2015/01/26 13:49:26 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*tmp;

	tmp = (char *)malloc(sizeof(tmp) * n);
	i = 0;
	while (i < n)
	{
		tmp[i] = *(char *)(src + i);
		i++;
	}
	i = 0;
	while (i < n)
	{
		*(char *)(dest + i) = tmp[i];
		i++;
	}
	free(tmp);
	return (dest);
}
