/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 11:57:20 by eboeuf            #+#    #+#             */
/*   Updated: 2015/05/11 13:14:59 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <arpa/inet.h>
# include <dirent.h>
# include <fcntl.h>
# include <netdb.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <sys/types.h>
# include "../libft/includes/libft.h"

typedef struct	s_file
{
	int			len;
	char		data[1024];
	char		buff[4096];
}				t_file;

void			ft_receive_server(int cs);
void			ft_put(char *data, int cs);

void			error_display(char *s);

#endif
