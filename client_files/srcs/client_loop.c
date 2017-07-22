/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:44:26 by khansman          #+#    #+#             */
/*   Updated: 2017/07/22 10:44:27 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	main_socks(void)
{
	FD_ZERO(&g_env.fds);
	FD_SET(g_env.socket_fd, &g_env.fds);
	FD_SET(STDIN_FILENO, &g_env.fds);
}

void	manage_sock(void)
{
	char		*line;

	if (sock_gnl(g_env.socket_fd, &line) < 1)
		exit_message("Server died.");
	if (ft_strlen(line))
	{
		ft_putchar('\r');
		ft_putendl(line);
		ft_putstr("\rEnter Command: ");
	}
	ft_strdel(&line);
}

void	client_loop(void)
{
	char		*line;

	ft_putstr("Enter Command: ");
	line = NULL;
	while (1)
	{
		main_socks();
		if (FD_ISSET(g_env.socket_fd, &g_env.fds))
			manage_sock();
		if (FD_ISSET(STDIN_FILENO, &g_env.fds))
		{
			get_next_line(STDIN_FILENO, &line);
			if (!strcmp(line, "/quit"))
				break ;
			if (!valid_command(line))
			{
				ft_strdel(&line);
				ft_putstr("Invalid Command!\n\rEnter Command: ");
				continue ;
			}
			write_to_socket(line);
			ft_strdel(&line);
			ft_putstr("\rEnter Command: ");
		}
	}
	if (!strcmp(line, "/quit"))
		write_to_socket(line);
	ft_strdel(&line);
}
