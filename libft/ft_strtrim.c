/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/14 15:29:13 by eboeuf            #+#    #+#             */
/*   Updated: 2015/01/27 10:22:26 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int					ft_isblank(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

char				*ft_strtrim(char const *s)
{
	int				d;
	int				trim_start;
	char			*new_str;
	unsigned int	i;

	d = 0;
	i = 0;
	trim_start = 0;
	new_str = ft_strnew(ft_strlen(s));
	while (i < ft_strlen(s))
	{
		if (!trim_start && ft_isblank(s[i]))
			i++;
		else
		{
			trim_start = 1;
			new_str[d++] = s[i++];
		}
	}
	while (ft_isblank(new_str[--d]))
		new_str[d] = '\0';
	return (new_str);
}
