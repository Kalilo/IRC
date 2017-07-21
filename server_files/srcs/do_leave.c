/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_leave.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:31:57 by khansman          #+#    #+#             */
/*   Updated: 2017/07/20 10:31:58 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

char	do_leave(int sd, char *channel)
{
	t_list		*chan;
	t_list		*user;

	chan = g_env.channels;
	while (chan && ft_strcmp(channel, ((t_channel *)(chan->content))->name))
		chan = chan->next;
	if (!chan)
	{
		MSG_ERROR = ft_strdup(MSG_E03);
		return (0);
	}
	user = ((t_channel *)(chan->content))->users;
	while (user && user->next)
	{
		if (!ft_strcmp((((t_user *)user->next->content))->nick, CLIENT(sd).nick))
		{
			MSG_ERROR = ft_strdup(MSG_E04);
			return (0);
		}
		user = user->next;
	}
	ft_strdel(&CLIENT(sd).channel);
	return (1);
}
