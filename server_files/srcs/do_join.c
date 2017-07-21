/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:31:49 by khansman          #+#    #+#             */
/*   Updated: 2017/07/20 10:31:50 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

char	do_join(int sd, char *channel)
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
		if (!ft_strcmp(((t_user *)(user->content))->nick, CLIENT(sd).nick))
		{
			MSG_ERROR = ft_strdup(MSG_E05);
			return (0);
		}
		user = user->next;
	}
	if (user)
	{
		if (!(user->next = ft_lstnew(&CLIENT(sd), sizeof(t_user))))
			error_quit("failed to allocate memory.");
	}
	else
		if (!(((t_channel *)(chan->content))->users = ft_lstnew(&CLIENT(sd),
				sizeof(t_user))))
			error_quit("failed to allocate memory.");
	ft_strdel(&CLIENT(sd).channel);
	CLIENT(sd).channel = ft_strdup(channel);
	return (1);
}
