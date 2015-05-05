/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_serv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 10:13:11 by eboeuf            #+#    #+#             */
/*   Updated: 2015/04/24 13:09:14 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/client.h"

static int					ft_rec_fd(char *file)
{
	int				fd;

	fd = open(file, O_RDWR | O_TRUNC | O_CREAT, 00644);
	if (fd == -1)
		error_display("ERROR Can't open file");
	return (fd);
}

void				ft_receive_server(int cs)
{
	int				ret;
	int				fd_new;
	char			buff[sizeof(t_file)];
	t_file			*file;

	file = NULL;
	fd_new = 0;
	while (1)
	{
		if ((ret = recv(cs, buff, sizeof(t_file), 0)) > 0)
		{
			file = (t_file *)buff;
			if (!ft_strcmp(file->data, "END"))
				break ;
			else if (!ft_strcmp(file->data, "ERROR"))
			{
				ft_putendl_fd("ERROR ", 2);
				return ;
			}
			else if (fd_new == 0)
				fd_new = ft_rec_fd(file->data);
			write(fd_new, (unsigned char *)file->buff, file->len);
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