/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 10:25:28 by eboeuf            #+#    #+#             */
/*   Updated: 2015/05/08 10:58:23 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

int							ft_ls(int cs)
{
	DIR						*dirp;
	struct dirent			*dir;
	char					ret[4096];

	dirp = opendir(".");
	ft_bzero(ret, 4096);
	if (!dirp)
		error_display("ERROR opendir");
	while ((dir = readdir(dirp)))
	{
		ft_strcat(ret, dir->d_name);
		ft_strcat(ret, "\n");
	}
	ft_strcat(ret, "SUCCESS");
	send(cs, ret, ft_strlen(ret), 0);
	ft_printf("[%d] \x1B[32msend %d bytes: [%s]\x1B[0m\n", cs,
			(int)ft_strlen(ret), ret);
	if (closedir(dirp) == -1)
		error_display("ERROR closedir");
	return (1);
}
