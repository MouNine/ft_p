/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/26 11:57:23 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/26 12:01:18 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_isin(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			if (s[i] == '\n')
				return (i + 1);
			i++;
		}
	}
	return (0);
}

static char	*ft_readline(char *s, char *buf)
{
	char	*tmp;

	if (s != NULL)
	{
		tmp = s;
		s = ft_strjoin((const char *)tmp, (const char *)buf);
		free(tmp);
	}
	else
	{
		s = (char *)malloc((ft_strlen((const char *)buf) + 1) * sizeof(char));
		s = ft_strcpy(s, (const char *)buf);
	}
	return (s);
}

static char	*ft_tobesave(char *s, int n, char **line)
{
	char	*tobefree;

	*line = ft_strsub(s, 0, n);
	tobefree = s;
	s = ft_strsub(tobefree, n + 1, ft_strlen(tobefree) - n - 1);
	free(tobefree);
	return (s);
}

int			get_next_line(int const fd, char **line)
{
	static char		*s;
	int				ret;
	char			buf[BUFF_SIZE + 1];
	int				n;

	ret = 1;
	while (ret > 0 && ft_isin(s) == 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[ret] = '\0';
		s = ft_readline(s, buf);
	}
	n = ft_isin(s);
	if (ret == 0 && n == 0)
	{
		*line = s;
		return (0);
	}
	if (n > 0)
	{
		s = ft_tobesave(s, n - 1, line);
		return (1);
	}
	return (-1);
}