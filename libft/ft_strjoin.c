/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:28:37 by eboeuf            #+#    #+#             */
/*   Updated: 2015/01/26 13:59:44 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j;

	j = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(j, s1);
	j = ft_strcat(j, (char *)s2);
	return (j);
}
