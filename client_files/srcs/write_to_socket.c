/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_socket.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:46:26 by khansman          #+#    #+#             */
/*   Updated: 2017/07/22 10:46:26 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	write_to_socket(char *line)
{
	char		*tmp;

	tmp = ft_strjoin(line, "\n");
	if (write(g_env.socket_fd, tmp, ft_strlen(tmp)) < 0)
		error_quit("failed to write to the socket.");
	ft_strdel(&tmp);
}
