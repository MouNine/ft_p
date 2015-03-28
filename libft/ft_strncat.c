/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 13:44:35 by eboeuf            #+#    #+#             */
/*   Updated: 2015/01/26 14:03:04 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	n2;
	size_t	i;

	i = 0;
	n2 = ft_strlen(dest);
	while (src[i] != '\0' && i < n)
	{
		dest[n2 + i] = src[i];
		i++;
	}
	dest[i + n2] = '\0';
	return (dest);
}
