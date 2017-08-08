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

void	manage_sock(void)
{
	char		*line;

	if (get_next_line(g_env.socket_fd, &line) < 1)
		exit_message("Server died.");
	if (ft_strlen(line))
	{
		ft_putstr("\r                               \r");
		ft_putendl(line);
		ft_putstr("\rEnter Command: ");
	}
	ft_strdel(&line);
}

int		main_socks(int sock)
{
	FD_ZERO(&g_env.fds);
	FD_SET(g_env.socket_fd, &g_env.fds);
	FD_SET(STDIN_FILENO, &g_env.fds);
	if ((sock = select(g_env.socket_fd + 1, &g_env.fds, NULL, NULL,
			NULL)) < 0)
		exit_message("Server died.");
	if (FD_ISSET(g_env.socket_fd, &g_env.fds))
		manage_sock();
	return (sock);
}

void	set_shell(char **line)
{
	if (!ft_strncmp(*line, "/connect ", 9))
	{
		close(g_env.socket_fd);
		do_connect(*line + 9);
	}
	else
		write_to_socket(*line);
	ft_strdel(line);
	ft_putstr("\rEnter Command: ");
}

void	client_loop(void)
{
	char		*line;
	int			sock;

	ft_putstr("Enter Command: ");
	line = NULL;
	sock = 0;
	while (1)
	{
		sock = main_socks(sock);
		if (FD_ISSET(STDIN_FILENO, &g_env.fds))
		{
			if (get_next_line(STDIN_FILENO, &line) < 1)
				continue ;
			if (!ft_strcmp(line, "/quit"))
				break ;
			if (!valid_command(line))
			{
				ft_strdel(&line);
				ft_putstr("Invalid Command!\n\rEnter Command: ");
				continue ;
			}
			set_shell(&line);
		}
	}
	write_to_socket("/quit");
	ft_strdel(&line);
}
