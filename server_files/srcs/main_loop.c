/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 10:58:51 by khansman          #+#    #+#             */
/*   Updated: 2017/07/18 10:58:53 by khansman         ###   ########.fr       */
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

void	accept_new_client(void)
{
	int		k;

	k = -1;
	if ((NEW_CLIENT_SOC = accept(MASTER_SOCK, (t_sock_addr *)&MASTER_ADDR,
			(socklen_t *)&MASTER_ADDRLEN)) < 0)
		error_quit("Failed to accept new client");
	ft_putendl("New client connected.");
	while (++k < MAX_CLIENTS)
		if (!CLIENT_SOCK(k))
		{
			CLIENT_SOCK(k) = NEW_CLIENT_SOC;
			break ;
		}
}

void	manage_clients(void)
{
	int		k;
	int		sd;

	k = -1;
	while (++k < MAX_CLIENTS)
	{
		sd = CLIENT_SOCK(k);
		// if (!FD_ISSET(sd, &CLIENT_READ_FD))
		// {
		// 	// if (get_next_line())

		// 	ft_putendl("Client disconnected");
		// 	close(sd);
		// 	CLIENT_SOCK(k) = 0;
		// }
		// else
		// {
		// 	// manage the request
		// 	ft_putendl_fd("Your request was recieved", sd);//temp
		// }
	}
}

void	main_loop(void)
{
	while (true)
	{
		prep_client_sockets();
		g_env.active_sock = select(MASTER_MAX_SD + 1,
			&CLIENT_READ_FD, NULL, NULL, NULL);
		if (g_env.active_sock < 0)
			error_quit("Failed to accept connection");//check that this works
		if (FD_ISSET(MASTER_SOCK, &CLIENT_READ_FD))
			accept_new_client();
		else
			NEW_CLIENT_SOC = 0;
		manage_clients();
	}
}
