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
		MSG_ERROR = ft_strdup(MSG_E02);
		return (0);
	}
	if (find_channel(channel))
	{
		MSG_ERROR = ft_strdup(MSG_E09);
		return (0);
	}
	new_chan.name = ft_strdup(channel);
	new_chan.users = NULL;
	chan = find_last_channel();
	if (chan)
		chan->next = ft_lstnew(&new_chan, sizeof(t_channel));
	else
		g_env.channels = ft_lstnew(&new_chan, sizeof(t_channel));
	return (do_join(sd, channel));
}
