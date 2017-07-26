/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_msg_to_sock.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 07:14:42 by khansman          #+#    #+#             */
/*   Updated: 2017/07/26 07:14:44 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

size_t	write_msg_to_sock(int fd, char *msg)
{
	size_t	pos;
	size_t	len;
	size_t	rlen;

	len = ft_strlen(msg);
	pos = 0;
	while (pos < len)
	{
		rlen = ((pos - len) < WRITE_BUFF) ? (pos - len) : WRITE_BUFF;
		if (send(fd, &msg[pos], WRITE_BUFF, MSG_DONTWAIT) < 1)
			return (0);
		pos += rlen;
	}
	return (len);
}
