/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 10:17:40 by eboeuf            #+#    #+#             */
/*   Updated: 2015/05/11 09:42:25 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

static int			ft_rec_fd(char *file)
{
	int				fd;

	fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		ft_putendl_fd("ERROR Can't open file", 2);
	return (fd);
}

static int			ft_write(t_file *file, int *fd)
{
	if (!ft_strcmp(file->data, "END"))
		return (1);
	else if (!ft_strcmp(file->data, "ERROR"))
		error_display("ERROR Don't know file");
	else if (*fd == 0)
		*fd = ft_rec_fd(file->data);
	write(*fd, file->buff, file->len);
	return (0);
}

void				ft_receive_client(int cs)
{
	int				ret;
	int				fd_new;
	char			buff[sizeof(t_file)];
	t_file			*file;

	fd_new = 0;
	file = NULL;
	while (1)
	{
		if ((ret = recv(cs, buff, sizeof(t_file), 0)) > 0)
		{
			file = (t_file *)buff;
			if (ft_write(file, &fd_new) == 1)
				break ;
			ft_bzero(buff, sizeof(t_file));
		}
		else if (ret == -1)
		{
			ft_putendl_fd("ERROR Can't receive file", 2);
			close(cs);
			break ;
		}
	}
	ft_putendl("SUCCESS");
	close(fd_new);
}
