/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/04 11:57:40 by eboeuf            #+#    #+#             */
/*   Updated: 2015/05/11 13:11:39 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <arpa/inet.h>
# include <dirent.h>
# include <fcntl.h>
# include <netdb.h>
# include <netinet/in.h>
# include <sys/stat.h>
# include <sys/socket.h>
# include <sys/types.h>
# include "../libft/includes/libft.h"

typedef struct	s_file
{
	int			len;
	char		data[1024];
	char		buff[4096];
}				t_file;

int				ft_pwd(int cs);
int				ft_ls(int cs);
int				ft_cd(char *data, int cs, char *pwd);
void			ft_get(char *data, int cs);
void			ft_receive_client(int cs);

void			error_display(char *s);

#endif
