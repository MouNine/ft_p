/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 10:12:24 by eboeuf            #+#    #+#             */
/*   Updated: 2015/05/11 13:14:47 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"

static int			ft_put_fd(char *file)
{
	int				fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_putendl_fd("ERROR Can't open file", 2);
	return (fd);
}

static int			ft_put_read(t_file file, int ret, int fd, int cs)
{
	char			buff[4096];

	ft_bzero(buff, 4096);
	while ((ret = read(fd, buff, 4095)) > 0)
	{
		file.len = ret;
		buff[ret] = '\0';
		ft_memcpy(file.buff, buff, 4096);
		send(cs, (char *)&file, sizeof(t_file), 0);
		ft_bzero(file.buff, 4096);
	}
	return (ret);
}

static void			ft_error(t_file file, int cs)
{
	ft_strcpy(file.data, "ERROR");
	send(cs, (char *)&file, sizeof(t_file), 0);
	error_display("ERROR Can't read file");
}

static void			ft_end(t_file file, int cs)
{
	ft_strcpy(file.data, "END");
	send(cs, (char *)&file, sizeof(t_file), 0);
	ft_putendl_fd("SUCCESS", 1);
}

void				ft_put(char *data, int cs)
{
	int				fd_new;
	int				ret;
	char			*path;
	char			tmp[4096];
	t_file			file;

	ret = 0;
	path = NULL;
	ft_bzero(tmp, 4096);
	ft_bzero(file.buff, 4096);
	getcwd(tmp, 4096);
	tmp[strlen(tmp)] = '/';
	ft_strcpy(file.data, data);
	path = ft_strjoin(tmp, data);
	path = ft_strtrim(path);
	fd_new = ft_put_fd(path);
	ret = ft_put_read(file, ret, fd_new, cs);
	if (ret == -1)
		ft_error(file, cs);
	else if (ret != -1)
	{
		ft_end(file, cs);
		close(fd_new);
	}
}
