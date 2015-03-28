/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 12:02:12 by eboeuf            #+#    #+#             */
/*   Updated: 2015/03/21 10:59:45 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __cplusplus
#error Be sure you are using a C compiler...
#endif

//#if defined (WIN32) || defined (_WIN32)

//#elif defined (linux) || defined (_POSIX_VERSION) || defined (_POSIX2_C_VERSION)\
 || defined (_XOPEN_VERSION)

#include <winsock2.h>
#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
#include <unistd.h> /* close */

//#include <arpa/inet.h> //htons
//#include <netinet/in.h> // struct sockaddr_in
//#include <stdio.h>
//#include <sys/socket.h>
//#include "libft/includes/libft.h"

// chacun a une @, chacun se connecte @ (pour localiser l ordinateur)
// et un port (parler a un service en particulier, exemple http)

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
	ft_putendl_fd(" <addr> <port>", 2);
	exit(-1);
}
// initialisation :
// - ouverture d'un socket en mode flux TCP/IP : socket(...)
// - connexion : connect()
int						create_client(char *addr, int port)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;	// adresse internet

	proto = getprotobyname("tcp");
	if (proto == 0)
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto); // PF_INET : Internet v4, SOCK_STREAM : protocole connecte (ouvre un canal de communication pour parler à l'intérieur / different du coup par coup, sms par exemple)
														// p_proto : numero de protocole de TCP
	// association numero de port et adresse
	sin.sin_family = AF_INET; //famille d'adresse internet
	sin.sin_port = htons(port); // convertit une representation host vers une representation reseau sur un short (16 bits)
	sin.sin_addr.s_addr = inet_addr(addr); // permet de convertir une chaine de caractere en adresse
	// associe la socket a une adresse
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
	{
		ft_putendl_fd("Connect error", 2);
		exit(2);
	}
	return (sock);
}
// selon la demande :
// - emettre des donnees : send()
// - tester la reception : select()
// - recevoir des donnees : recv()
// dans un boucle (pour serveur multiclient) : (thread client)
// - attendre donnees et les lire : recv()
// - emettre des donnees en reponse : send()
//fin :
// - deconnecter : shutdown()
// - fermeture du socket : close()
int						main(int ac, char **av)
{
	// recuperation du port dans les param
	int	port;
	int	sock; // fd (un peu different)
	// si pas de param :
	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	// creation du client, renvoie une socket
	sock = create_client(av[1], port);
	write(sock, "bonjour\n", 8); // pour verifier que le serveur reçoit bien le message
	close(sock);
	return (0);
}
