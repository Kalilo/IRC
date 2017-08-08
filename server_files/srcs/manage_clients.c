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

void	manage_client(int k, int sd)
{
	char	ret;

	if ((ret = manage_request(k)) == 1)
		write_msg_to_sock(sd, "SUCCESS\n");
	else if (ret < 1)
	{
		write_msg_to_sock(sd, MSG_ERROR);
		ft_strdel(&MSG_ERROR);
	}
	ft_strdel(&MESSAGE);
}

void	remove_client(int pos)
{
	if (CLIENT(pos).channel)
		do_leave(pos, CLIENT(pos).channel);
	ft_strdel(&CLIENT(pos).nick);
	ft_bzero(&CLIENT(pos), sizeof(t_user));
}

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
			if (get_next_line(sd, &MESSAGE) < 1 || !ft_strcmp("/quit", MESSAGE))
			{
				ft_putendl("Client disconnected");
				close(sd);
				remove_client(k);
			}
			else
				manage_client(k, sd);
		}
	}
}
