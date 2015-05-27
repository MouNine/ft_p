/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:01:15 by eboeuf            #+#    #+#             */
/*   Updated: 2015/05/11 13:15:37 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

static void						usage(char *str)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" <port>", 2);
	exit(-1);
}

static int						create_server(int port)
{
	int							sock;
	struct protoent				*proto;
	struct sockaddr_in			sin;

	if ((proto = getprotobyname("tcp")) == 0)
		error_display("ERROR Getprotobyname");
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		error_display("ERROR socket");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
		error_display("ERROR bind");
	listen(sock, 42);
	return (sock);
}

static void						ft_command(char *data, int cs, char *pwd)
{
	if (!ft_strncmp(data, "ls", 2))
		ft_ls(cs);
	else if (!ft_strncmp(data, "cd", 2))
		ft_cd(data, cs, pwd);
	else if (!ft_strncmp(data, "pwd", 3))
		ft_pwd(cs);
	else if (!ft_strncmp(data, "get ", 4))
		ft_get(data + 4, cs);
	else if (!ft_strncmp(data, "put ", 4))
		ft_receive_client(cs);
	else if (!ft_strncmp(data, "quit", 4))
	{
		close(cs);
		exit(1);
	}
	else
		send(cs, "ERROR Command not found", 23, 0);
}

static void						fork_child(int cs)
{
	int							ret;
	char						pwd[4096];
	char						data[1024];

	getcwd(pwd, 4096);
	while ((ret = recv(cs, data, 1024, 0)) > 0)
	{
		data[ret] = '\0';
		ft_printf("[%d] \x1B[33mreceived %d bytes: [%s]\x1B[0m\n",
				cs, ret, data);
		ft_command(data, cs, pwd);
		ft_bzero(data, 1024);
	}
}

int								main(int ac, char **av)
{
	int							port;
	int							sock;
	int							cs;
	unsigned int				cslen;
	struct sockaddr_in			csin;

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	sock = create_server(port);
	cslen = (unsigned int)sizeof(csin);
	while ((cs = accept(sock, (struct sockaddr*)&csin, &cslen)))
	{
		if (fork() == 0)
		{
			ft_printf("[\x1B[32mO\x1B[0m] New user [%d] connected\n", cs);
			fork_child(cs);
			ft_printf("[\x1B[31mX\x1B[0m] New user [%d] deconnected\n", cs);
		}
	}
	if (cs == -1)
		error_display("ERROR accept");
	close(cs);
	close(sock);
	return (0);
}
