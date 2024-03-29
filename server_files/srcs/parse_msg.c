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
		if (CLIENT_SOCK(k) && CLIENT(k).nick &&
				!ft_strcmp(CLIENT(k).nick, dest))
			return (msg_direct);
	if (find_channel(dest))
		return (msg_channel);
	return (msg_none);
}

char		*prep_message(int pos, t_msg *msg)
{
	char		*tmp;
	t_list		*chan;

	tmp = NULL;
	if (msg->type == msg_direct && CLIENT(pos).nick)
		tmp = ft_strjoin(CLIENT(pos).nick, ": ");
	else if (msg->type == msg_channel)
	{
		chan = find_channel(msg->dest);
		tmp = ft_strjoin(((t_channel *)(chan->content))->name, ": ");
		ft_str_append(&tmp, "[");
		if (CLIENT(pos).nick)
			ft_str_append(&tmp, CLIENT(pos).nick);
		else
			ft_str_append(&tmp, "(anonymous)");
		ft_str_append(&tmp, "] ");
	}
	else
		tmp = ft_strdup("[anonymous]: ");
	tmp = ft_str_append3(&tmp, &msg->msg);
	ft_str_append(&tmp, "\n");
	return (tmp);
}

char		parse_message(int pos, t_msg *msg, char *msg_details)
{
	char		*tmp;

	ft_bzero(msg, sizeof(t_msg));
	if (!ft_strlen(msg_details))
		RET_ERR(MSG_E11);
	if (!(tmp = ft_strchr(msg_details, ' ')))
		RET_ERR(MSG_E10);
	msg->dest = ft_strdup(msg_details);
	msg->dest[(tmp - msg_details)] = '\0';
	msg->msg = ft_strdup(tmp + 1);
	if (!ft_strlen(msg->dest) || (msg->type = get_msg_type(msg->dest))
			== msg_none)
		RET_ERR(MSG_E12);
	if (!ft_strlen(msg->msg))
		RET_ERR(MSG_E10);
	msg->msg = prep_message(pos, msg);
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
