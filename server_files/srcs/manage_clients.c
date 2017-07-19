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
			if (get_next_line(sd, &MESSAGE) < 1)
			{
				ft_putendl("Client disconnected");
				close(sd);
				CLIENT_SOCK(k) = 0;
			}
			else
			{
				// manage the request
				ft_putendl_fd("Your request was recieved", sd);//temp
			}
		}
	}
}
