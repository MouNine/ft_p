/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/06 11:13:25 by eboeuf            #+#    #+#             */
/*   Updated: 2015/01/26 14:05:22 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int			nb_words(char const *s, char c)
{
	int				nbword;
	int				state;

	state = OUT;
	nbword = 0;
	while (*s)
	{
		if (state == OUT && *s != c)
		{
			state = IN;
			nbword++;
		}
		if (state == IN && *s == c)
			state = OUT;
		s++;
	}
	return (nbword);
}

static void			copy_into_array(char **array, char const *s, char c)
{
	int				state;
	int				beginning_word;
	int				i;

	state = OUT;
	i = 0;
	while (s[i])
	{
		if (state == OUT && s[i] != c)
		{
			state = IN;
			beginning_word = i;
		}
		if (state == IN && s[i] == c)
		{
			state = OUT;
			*array = ft_strsub(s, beginning_word, i - beginning_word);
			++array;
		}
		i++;
	}
	if (state == IN)
		*array = ft_strsub(s, beginning_word, i - beginning_word);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**ret;
	int				nbword;

	nbword = nb_words(s, c) + 1;
	if ((ret = (char **)malloc(nbword * sizeof(char *))) == NULL)
		return (NULL);
	if (ret)
	{
		copy_into_array(ret, s, c);
		ret[nbword - 1] = 0;
	}
	return (ret);
}
