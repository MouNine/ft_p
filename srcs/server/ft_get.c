/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 10:19:23 by eboeuf            #+#    #+#             */
/*   Updated: 2015/05/08 13:59:43 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

static int					ft_get_fd(char *file)
{
	int						fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_display("ERROR Can't open file");
	return (fd);
}

void						ft_get(char *data, int cs, char *pwd)
{
	int						fd_new;
	int						ret;
	char					*path;
	char					*tmp;
	char                    buff[4096];
	t_file					file;

	ret = 0;
	ft_bzero((void *)&file, sizeof(t_file));
	ft_strcpy(file.data, data);
	ft_printf("%s\n", file.data);

	tmp = ft_strjoin(pwd, "/");
	path = ft_strjoin(tmp, data);
	path = ft_strtrim(path);
	fd_new = ft_get_fd(path);
	while ((ret = read(fd, buff, 4095)) > 0)
	{
		file.len = ret;
		buff[ret] = '\0';
		ft_memcpy(file.buff, buff, ret);
		send(cs, (char *)&file, sizeof(t_file), 0);
		ft_bzero(buff, 4096);
	}
	if (ret == -1)
	{
		ft_strcpy(file.data, "ERROR");
		send(cs, (char *)&file, sizeof(t_file), 0);
		error_display("ERROR Can't read file");
	}
	send(cs, (char *)&file, sizeof(t_file), 0);
	if (ret != -1)
	{
		ft_strcpy(file.data, "END");
		send(cs, (char *)&file, sizeof(t_file), 0);
		ft_putendl_fd("SUCCESS2", 1);
		close(fd_new);
	}
}
