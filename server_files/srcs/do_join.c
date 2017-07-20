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
	while (chan && ft_strcmp(channel, chan->name))
		chan = chan->next;
	if (!chan)
	{
		MSG_ERROR = "Channel doesn't exist, or isn't avaliable.";
		return (0);
	}
	user = chan->users;
	while (user && user->next)
	{
		if (!ft_strcmp(user->content.name, CLIENT(sd).name))
		{
			MSG_ERROR = "Already in channel.";
			return (0);
		}
		user = user->next;
	}
	if (user)
	{
		if (!(user->next = ft_lstnew(CLIENT(sd), sizeof(t_user))))
			error_quit("failed to allocate memory.");
	}
	else
		if (!(chan->users = ft_lstnew(CLIENT(sd), sizeof(t_user))))
			error_quit("failed to allocate memory.");
	return (1);
}
