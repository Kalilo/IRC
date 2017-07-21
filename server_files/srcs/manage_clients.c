/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_clients.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:03:00 by khansman          #+#    #+#             */
/*   Updated: 2017/07/19 18:03:01 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void	manage_clients(void)
{
	int		k;
	int		sd;

	k = -1;
	while (++k < MAX_CLIENTS)
	{
		sd = CLIENT_SOCK(k);
		if (sd && FD_ISSET(sd, &CLIENT_READ_FD))
		{
			if (sock_gnl(sd, &MESSAGE) < 1 || !ft_strcmp("/quit", MESSAGE))
			{
				ft_putendl("Client disconnected");
				close(sd);
				CLIENT_SOCK(k) = 0;
			}
			else
			{
				if (manage_request(k))
					send(sd, "SUCCESS\n", 8, MSG_DONTWAIT);
				else
				{
					send(sd, MSG_ERROR, ft_strlen(MSG_ERROR), MSG_DONTWAIT);
					ft_strdel(&MSG_ERROR);
				}
				ft_strdel(&MESSAGE);
			}
		}
	}
}
