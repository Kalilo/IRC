/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_socket.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:46:36 by khansman          #+#    #+#             */
/*   Updated: 2017/07/22 10:46:37 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

char	*read_from_socket(void)
{
	char		*line;

	if (get_next_line(g_env.socket_fd, &line) < 0)
		error_quit("Failed to read from the socket.");
	return (line);
}
