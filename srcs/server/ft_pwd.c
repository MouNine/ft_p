/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/24 10:24:38 by eboeuf            #+#    #+#             */
/*   Updated: 2015/04/24 11:03:11 by eboeuf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/server.h"

int							ft_pwd(int cs)
{
	char					data[4096];

	getcwd(data, 4096);
    printf("[%d]\x1B[32msend %d bytes: [%s]\x1B[0m\n",cs, (int)ft_strlen(data), data);
    send(cs, data, ft_strlen(data), 0);
	return (1);
}
