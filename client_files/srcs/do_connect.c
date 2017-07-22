/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_connect.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:27:23 by khansman          #+#    #+#             */
/*   Updated: 2017/07/22 10:27:26 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

char	do_connect(char *details)
{
	char	*tmp;
	char	*tmp2;

	if (!(tmp = ft_strchr(details, ' ')) || ft_strrchr(details, ' ') != tmp)
	{
		g_env.error = ft_strdup("Please specify both server and port.");
		return (0);
	}
	g_env.port = ft_atoi(tmp + 1);
	tmp2 = ft_strdup(details);
	tmp2[tmp - details] = '\0';
	g_env.server = gethostbyname(tmp2);
	ft_strdel(&tmp2);
	connect_to_server();
	return (1);
}
