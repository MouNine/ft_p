/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 10:17:40 by eboeuf            #+#    #+#             */
/*   Updated: 2015/05/08 13:41:07 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

static int					ft_rec_fd(char *file)
{
	int						fd;

	fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		ft_putendl_fd("ERROR Can't open file", 2);
	return (fd);
}

void						ft_receive_client(int cs)
{
	int						fd_new;
	int						ret;
	char					buff[sizeof(t_file)];
	t_file					*file;

	fd_new = 0;
	file = NULL;
	while (1)
	{
		if ((ret = recv(cs, buff, sizeof(t_file), 0)) > 0)
		{
			file = (t_file *)buff;
			if (!ft_strcmp(file->data, "END")
				break ;
			else if (!ft_strcmp(file->data, "ERROR"))
			{
				ft_putendl_fd("ERROR ", 2);
				return ;
			}
			else if (fd_new == 0)
				fd_new = ft_rec_fd(file->data);
			write(fd, file->buff, file->len);
			ft_bzero(buff, sizeof(t_file));
		}
		else if (ret == -1)
		{
			ft_putendl_fd("ERROR Can't receive file", 2);
			close(cs);
			break ;
		}
	}
	ft_putendl("SUCCESS1");
	close(fd_new);
}