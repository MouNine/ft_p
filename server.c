/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:01:15 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/21 16:50:16 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <winsock2.h>
#include <sys/types.h>
#include <stdio.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
#include <unistd.h> /* close */

//#include <arpa/inet.h> //htons
//#include <netdb.h> // struct protoent
//#include <netinet/in.h> // struct sockaddr_in
//#include <stdio.h>
//#include <sys/socket.h>
//#include "libft/includes/libft.h"

// chacun a une @, chacun se connecte @ (pour localiser l ordinateur)
// et port (parler a un service en particulier, exemple http)

void        ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void        ft_putstr_fd(char const *s, int fd)
{
    int     i;

    i = 0;
    while (s[i] != '\0')
    {
        ft_putchar_fd(s[i], fd);
        i++;
    }
}

void        ft_putendl_fd(char const *s, int fd)
{
    int     i;

    i = 0;
    if (s != NULL)
    {
        while (s[i] != '\0')
        {
            ft_putchar_fd(s[i], fd);
            i++;
        }
        ft_putchar_fd('\n', fd);
    }
}

void					usage(char *str)
{
	ft_putstr_fd("Usage: ", 2);
	ft_putstr_fd(str, 2);
	ft_putendl_fd(" <port>", 2);
	exit(-1);
}
// initialisation :
// - ouverture d'un socket en mode flux (TCP/IP) : socket(...)
// - configurer adresse et port : bind()
// - configurer nombre d'ecoute : listen()
int						create_server(int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;	// adresse internet

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	if ((sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1) // PF_INET : Internet v4, SOCK_STREAM : protocole connecte (ouvre un canal de communication pour parler à l'intérieur / different du coup par coup, sms par exemple)
																	// p_proto : numero de protocole de TCP
	{
		ft_putendl_fd("Socket error", 2);
		exit(2);
	}
	printf ("socket %d is now opened in TCP/IP mode\n", sock);
	// association numero de port et adresse
	sin.sin_family = AF_INET; //famille d'adresse internet
	sin.sin_port = htons(port); // convertit une representation host vers une representation reseau sur un short (16 bits)
	sin.sin_addr.s_addr = htonl(INADDR_ANY); // 32bits
	// associe la socket a une adresse
	if (bind(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl_fd("Bind error", 2);
		exit(2);
	}
	listen(sock, 42); // donne le nombre de connexions simultanees qu'on peut recevoir
	printf("listening on port %d...\n", port);
	return (sock);
}
// dans une boucle :
// - accepter une connexion : accept()
// - tester la reception : select()
// - recevoir des donnees : recv()
// - emettre des donnees : send()
// - deconnecter : shutdown()
// dans une boucle (serveur multiclient) : (thread serveur)
// - attendre une connexion : accept()
// - creer un thread avec le socket client
// fin :
// - fermeture du socket : close()
int						main(int ac, char **av)
{
	// recuperation du port dans les param
	int	port;
	int	sock; // fd (un peu different)
	int	cs; // client socket
	unsigned int		cslen;
	struct sockaddr_in	csin;
	int 				r;
	char				buf[1024];
//	unsigned char 		data[128 + 1];
	// si pas de param :
	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	// creation du serveur sur le port, renvoie une socket
	sock = create_server(port);
	printf("waiting for a client connection on port %d...\n", port);
	while (42)
	{
		cslen = (unsigned int) sizeof csin;
		cs = accept(sock, (struct sockaddr*)&csin, &cslen); // appel systeme, recreer une socket qui permet de faire discuter le serveur avec le client
		if (cs != -1)
			printf("client connected with socket %d from %s:%d\n", cs, inet_ntoa(csin.sin_addr), htons(csin.sin_port));
		if (fork() == -1)
			printf("Fork failed\n");
		else if (fork() == 0)
		{
//	while ((r = recv(cs, data, (int) sizeof data - 1, 0)) > 0)
//	{
//		size_t nb_rec = (size_t) r;
//		if (nb_rec > 0)
//		{
			/* convert to string */
 //       	data[nb_rec] = 0;
//        	printf ("%u byte%s received:\n%s\n",(unsigned) nb_rec, nb_rec > 1 ? "s" : "",data);
 //       }
//        else
//            printf("client is disconnected\n");
//	}
			while ((r = read(cs, buf, 1023)) > 0)
			{
				sleep(2);
				buf[r] = '\0';
				printf("received %d bytes: [%s]\n", r, buf);
			}
			printf ("closing client socket %d...\n", cs);
			close(cs);
			exit(0);
		}
		else
		{
			printf ("closing client socket %d...\n", cs);
			close(cs);
		}
	}
	printf("closing socket %d...\n", sock);
	close(sock);
	printf("the socket is now closed\n");
	return (0);
}
