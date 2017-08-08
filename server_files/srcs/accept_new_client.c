/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   accept_new_client.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 18:02:47 by khansman          #+#    #+#             */
/*   Updated: 2017/07/19 18:02:48 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

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
			ft_bzero(&CLIENT_SOCK(k), sizeof(t_user));
			CLIENT_SOCK(k) = NEW_CLIENT_SOC;
			break ;
		}
}
