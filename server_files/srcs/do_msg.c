/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:32:19 by khansman          #+#    #+#             */
/*   Updated: 2017/07/20 10:32:21 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

void		send_msg_to_chan(t_msg msg)
{
	t_list		*chan;

	chan = find_channel(msg.dest);
	chan = ((t_channel *)(chan->content))->users;
	while (chan)
	{
		send((((t_user *)(chan->content))->sock), msg.msg,
			ft_strlen(msg.msg), MSG_DONTWAIT);
		chan = chan->next;
	}
}

char		do_msg(int pos, char *msg_details)
{
	t_msg		msg;
	int			k;

	if (!parse_message(pos, &msg, msg_details) && clear_msg(&msg))
		return (0);
	k = -1;
	if (msg.type == msg_direct)
	{
		while (++k < MAX_CLIENTS)
			if (CLIENT_SOCK(k) && !ft_strcmp(CLIENT(k).nick, msg.dest))
			{
				send(CLIENT_SOCK(k), msg.msg, ft_strlen(msg.msg),
					MSG_DONTWAIT);
				break ;
			}
	}
	else
		send_msg_to_chan(msg);
	clear_msg(&msg);
	return (1);
}
