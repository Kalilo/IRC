/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sock_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 09:27:01 by khansman          #+#    #+#             */
/*   Updated: 2017/07/20 09:27:08 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

int		sock_gnl(const int fd, char **line)
{
	static char	buff[SOCK_GNL_BS + 1];
	ssize_t		k;
	char		*tmp;

	if (!line)
		return (-1);
	*line = NULL;
	buff[SOCK_GNL_BS] = '\0';
	while (1)
	{
		k = recv(fd, &buff, SOCK_GNL_BS, MSG_DONTWAIT);
		ft_str_append(line, buff);
		if (k < SOCK_GNL_BS)
			break ;
	}
	if (k < 0 && *line == NULL)
		return (-1);
	if (*line == NULL)
		return (0);
	if ((tmp = (ft_strchr(*line, '\n'))))
		*tmp = '\0';
	return (1);
}
