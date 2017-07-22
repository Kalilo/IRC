/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_to_server.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:22:14 by khansman          #+#    #+#             */
/*   Updated: 2017/07/22 10:22:16 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	connect_to_server(void)
{
	ft_putendl("Connecting...");
	if (g_env.port <= 0 || g_env.port > SHRT_MAX)
		error_quit("Invalid port number!");
	if ((g_env.socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error_quit("Failed to open socket!");
	g_env.server_addr.sin_family = AF_INET;
	ft_memcpy(&g_env.server->h_addr, &g_env.server_addr.sin_addr.s_addr,
		g_env.server->h_length);
	g_env.server_addr.sin_port = htons(g_env.port);
	if (connect(g_env.socket_fd, (t_sock_addr *)&g_env.server_addr,
			sizeof(g_env.server_addr)) < 0)
		error_quit("Failed to connect to the server.");
	ft_putendl("Connected!");
}
