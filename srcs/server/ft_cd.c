/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 10:25:04 by eboeuf            #+#    #+#             */
/*   Updated: 2015/05/08 10:27:48 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

int							ft_cd(char *data, int cs, char *pwd)
{
	char					*tmp;
	char					buf[4096];

	ft_bzero(buf, 4096);
	tmp = ft_strtrim(data + 3);
	if (chdir(tmp) != -1)
	{
		ft_printf("[%d] \x1B[32msend %d bytes: [%s]\x1B[0m\n", cs,
				(int)ft_strlen(tmp), tmp);
		if (ft_strlen(getcwd(buf, 4096)) >= ft_strlen(pwd))
			send(cs, "SUCCESS", 7, 0);
		else
		{
			chdir(pwd);
			send(cs, "ERROR You don't have right !", 28, 0);
		}
	}
	else
		send(cs, "ERROR You don't have right !", 28, 0);
	free(tmp);
	return (1);
}
