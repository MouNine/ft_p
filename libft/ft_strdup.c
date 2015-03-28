/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 13:40:54 by eboeuf            #+#    #+#             */
/*   Updated: 2015/01/26 13:58:19 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;

	dup = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (src)
	{
		if (!dup)
			return (NULL);
		if (dup)
			ft_strcpy(dup, src);
	}
	return (dup);
}
