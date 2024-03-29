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

char		send_msg_to_chan(int pos, t_msg msg)
{
	t_list		*chan;

	if (!CLIENT(pos).channel || ft_strcmp(CLIENT(pos).channel, msg.dest))
		RET_ERR(MSG_E16);
	chan = find_channel(msg.dest);
	chan = ((t_channel *)(chan->content))->users;
	while (chan)
	{
		write_msg_to_sock((((t_user *)(chan->content))->sock), msg.msg);
		chan = chan->next;
	}
	return (1);
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
			if (CLIENT_SOCK(k) && CLIENT(k).nick &&
				!ft_strcmp(CLIENT(k).nick, msg.dest))
			{
				write_msg_to_sock(CLIENT_SOCK(k), msg.msg);
				break ;
			}
	}
	else
		return (send_msg_to_chan(pos, msg));
	clear_msg(&msg);
	return (1);
}
