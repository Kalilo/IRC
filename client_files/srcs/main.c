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
}

int		main(int ac, char **av)
{
	ft_bzero(&g_env, sizeof(t_env));
	parse_arguments(ac, av);
	return (0);
}