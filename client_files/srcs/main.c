/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 09:49:52 by khansman          #+#    #+#             */
/*   Updated: 2017/07/22 09:49:54 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define CLIENT_MAIN
#include "../includes/client.h"

void	parse_arguments(int ac, char **av)
{
	char	*tmp;
	char	*tmp2;

	if (ac > 3)
		error_quit("Usage: ./client <server> <port>");
	else if (ac == 3)
	{
		g_env.server = gethostbyname(av[1]);
		g_env.port = ft_atoi(av[2]);
	}
	else if (ac == 2)
	{
		if (!(tmp = ft_strchr(av[1], ' ')) || ft_strrchr(av[1], ' ') != tmp)
			error_quit("Usage: ./client [server [port]]");
		g_env.port = ft_atoi(tmp + 1);
		tmp2 = ft_strdup(av[1]);
		tmp2[tmp - av[1]] = '\0';
		g_env.server = gethostbyname(tmp2);
		ft_strdel(&tmp2);
	}
	else
		return ;
	connect_to_server();
}

void	sig_listener(int signo)
{
	if (signo == SIGURG || signo == SIGCONT ||
			signo == SIGCHLD || signo == SIGIO)
		return ;
	if (signo == SIGPIPE)
		ft_putendl("Server died.");
	exit(0);
}

void	sig_setter(void)
{
	int		k;

	k = -1;
	while (++k < 28)
		signal(k, sig_listener);
}

void	connect_loop(void)
{
	char	*line;
	char	*tmp1;
	char	*tmp2;

	line = NULL;
	ft_putendl("Not Connected, please connect to a server.");
	ft_putstr("Enter Command: ");
	while (get_next_line(STDIN_FILENO, &line) > 0)
	{
		if (!ft_strncmp(line, "/connect ", 9) && (tmp2 = ft_strchr(line, ' '))
			!= (tmp1 = ft_strrchr(line, ' ')))
		{
			g_env.port = ft_atoi(tmp1 + 1);
			*tmp1 = '\0';
			g_env.server = gethostbyname(tmp2 + 1);
			connect_to_server();
			break ;
		}
		ft_putendl("Not Connected, please connect to a server.");
		ft_putstr("Enter Command: ");
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

int		main(int ac, char **av)
{
	ft_bzero(&g_env, sizeof(t_env));
	sig_setter();
	parse_arguments(ac, av);
	if (ac < 2)
		connect_loop();
	client_loop();
	close(g_env.socket_fd);
	return (0);
}
