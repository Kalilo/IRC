/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:35:15 by khansman          #+#    #+#             */
/*   Updated: 2017/07/21 08:35:16 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

/*
** Used for creating channels
*/

char	do_create(int sd, char *channel)
{
	t_list		*chan;
	t_channel	new_chan;

	if (CLIENT(sd).channel != NULL)
	{
		MSG_ERROR = "Users can't create a channel while in one.\n";
		return (0);
	}
	new_chan.name = ft_strdup(channel);
	new_chan.users = NULL;
	chan = g_env.channels;
	while (chan && chan->next)
		chan = chan->next;
	if (chan)
		chan->next = ft_lstnew(&new_chan, sizeof(t_channel));
	else
		g_env.channels = ft_lstnew(&new_chan, sizeof(t_channel));
	return (do_join(sd, channel));
}
