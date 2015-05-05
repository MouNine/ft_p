/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_receive_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 10:17:40 by eboeuf            #+#    #+#             */
/*   Updated: 2015/04/24 14:05:29 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

static int							ft_rec_fd(char *file)
{
	int						fd;

	fd = open(file, O_RDWR | O_TRUNC | O_CREAT , 0644);
	if (fd == -1)
		ft_putendl_fd("ERROR Can't open file", 2);
	return (fd);
}

void						ft_receive_client(int cs)
{
	int						fd_new;
	int						ret;
	unsigned char			buff[sizeof(t_file)];
	t_file					*file;

	fd_new = 0;
	while (1)
	{
		if ((ret = recv(cs, buff, sizeof(t_file), 0)) > 0)
			file = (t_file *)buff;
		if (fd_new == 0)
			fd_new = ft_rec_fd(file->data);
		write(fd_new, (unsigned char *)file->buff, file->len);
		ft_bzero(buff, sizeof(t_file));
	}
	if (ret == -1)
		return ;
	else
		close(fd_new);
}
