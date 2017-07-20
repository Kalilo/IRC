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

void	main_loop(void)
{
	while (true)
	{
		prep_client_sockets();
		g_env.active_sock = select(MASTER_MAX_SD + 1,
			&CLIENT_READ_FD, NULL, NULL, NULL);
		if (g_env.active_sock < 0)
			error_quit("Failed to accept connection");
		if (FD_ISSET(MASTER_SOCK, &CLIENT_READ_FD))
			accept_new_client();
		else
			NEW_CLIENT_SOC = 0;
		manage_clients();
	}
}
