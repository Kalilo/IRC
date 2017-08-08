/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 07:57:10 by khansman          #+#    #+#             */
/*   Updated: 2017/07/18 07:57:11 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

/*
** Signals:
** Discarded: 13
** Kill program: 2
*/

void	sig_listener(int signo)
{
	if (signo == SIGPIPE || signo == SIGURG || signo == SIGCONT ||
			signo == SIGCHLD || signo == SIGIO)
		return ;
	close(MASTER_SOCK);
	exit(0);
}

void	sig_setter(void)
{
	int		k;

	k = -1;
	while (++k < 28)
		signal(k, sig_listener);
}

char	init(int port)
{
	if (port <= 0 || SHRT_MAX <= port)
		error_quit("Invalid port number given.");
	ft_bzero(&g_env, sizeof(t_env));
	if ((MASTER_SOCK = socket(AF_INET, SOCK_STREAM, 0)) == 0)
		error_quit("Failed to open master socket.");
	sig_setter();
	if (setsockopt(MASTER_SOCK, SOL_SOCKET, SO_REUSEADDR, (char *)&MASTER_OPT,
			sizeof(MASTER_OPT)) < 0)
		error_quit("Failed to set master socket to allow multiple connections");
	MASTER_ADDR.sin_family = AF_INET;
	MASTER_ADDR.sin_addr.s_addr = INADDR_ANY;
	MASTER_ADDR.sin_port = htons(port);
	if (bind(MASTER_SOCK, (t_sock_addr *)&MASTER_ADDR, sizeof(MASTER_ADDR)) < 0)
		error_quit("Falied to bind master socket to port.");
	if (listen(MASTER_SOCK, 3) < 0)
		error_quit("Failed to run listen on master socket");
	MASTER_ADDRLEN = sizeof(MASTER_ADDR);
	return (1);
}
