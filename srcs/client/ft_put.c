/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 10:12:24 by eboeuf            #+#    #+#             */
/*   Updated: 2015/04/24 10:39:53 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"

static int					ft_put_fd(char *file)
{
	int				fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_display("ERROR Can't open file");
	return (fd);
}

void				ft_put(char *data, int cs, char *pwd)
{
	int				fd_new;
	int				ret;
	char			*path;
	char			*tmp;
	char			buff[4096];
	t_file			file;

	ft_bzero(file.buff, 4096);
	ft_strcpy(file.data, data);
	tmp = ft_strjoin(pwd, "/");
	path = ft_strjoin(tmp, data);
	path = ft_strtrim(path);
	fd_new = ft_put_fd(path);
	while ((ret = read(fd_new, buff, 4095)) > 0)
	{
		file.len = ret;
		ft_memcpy(file.buff, buff, ret);
		send(cs, (char *)&file, sizeof(t_file), 0);
		ft_bzero(file.buff, 4096);
	}
	if (ret == -1)
		error_display("ERROR Can't read file");
	send(cs, (char *)&file, sizeof(t_file), 0);
	if (ret != -1)
		close(fd_new);
}
