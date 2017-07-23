/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 09:05:20 by khansman          #+#    #+#             */
/*   Updated: 2017/07/22 09:05:22 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_msg_type	get_msg_type(char *dest)
{
	int			k;

	k = -1;
	while (++k < MAX_CLIENTS)
		if (CLIENT_SOCK(k) && !ft_strcmp(CLIENT(k).nick, dest))
			return (msg_direct);
	if (find_channel(dest))
		return (msg_channel);
	return (msg_none);
}

char		*prep_message(int pos, t_msg msg)
{
	char		*tmp;
	t_list		*chan;

	tmp = NULL;
	if (msg.type == msg_direct)
		tmp = ft_strjoin(CLIENT(pos).nick, ": ");
	else if (msg.type == msg_channel)
	{
		chan = find_channel(msg.dest);
		tmp = ft_strjoin(((t_channel *)(chan->content))->name, ": ");
		ft_str_append(&tmp, "[");
		ft_str_append(&tmp, CLIENT(pos).nick);
		ft_str_append(&tmp, "] ");
	}
	tmp = ft_str_append3(&tmp, &msg.msg);
	ft_str_append(&tmp, "\n");
	return (tmp);
}

char		parse_message(int pos, t_msg *msg, char *msg_details)
{
	char		*tmp;

	ft_bzero(msg, sizeof(t_msg));
	if (!ft_strlen(msg_details))
	{
		MSG_ERROR = ft_strdup(MSG_E11);
		return (0);
	}
	if (!(tmp = ft_strchr(msg_details, ' ')))
	{
		MSG_ERROR = ft_strdup(MSG_E10);
		return (0);
	}
	msg->dest = ft_strdup(msg_details);
	msg->dest[(tmp - msg_details)] = '\0';
	msg->msg = ft_strdup(tmp + 1);
	msg->msg = prep_message(pos, *msg);
	if ((msg->type = get_msg_type(msg->dest)) == msg_none)
	{
		MSG_ERROR = ft_strdup(MSG_E12);
		return (0);
	}
	return (1);
}

char		clear_msg(t_msg *msg)
{
	msg->type = msg_none;
	ft_strdel(&(msg->dest));
	ft_strdel(&(msg->msg));
	ft_strdel(&(msg->error));
	return (1);
}
