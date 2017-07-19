/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_client_sockets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:02:31 by khansman          #+#    #+#             */
/*   Updated: 2017/07/19 18:02:34 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	prep_client_sockets(void)
{
	int		k;
	int		sd;

	k = -1;
	FD_ZERO(&CLIENT_READ_FD);
	FD_SET(MASTER_SOCK, &CLIENT_READ_FD);
	MASTER_MAX_SD = MASTER_SOCK;
	while (++k < MAX_CLIENTS)
	{
		if ((sd = CLIENT_SOCK(k)) > 0)
			FD_SET(sd, &CLIENT_READ_FD);
		if (sd > MASTER_MAX_SD)
			MASTER_MAX_SD = sd;
	}
}
