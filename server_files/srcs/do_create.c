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

char	do_create(int pos, char *channel)
{
	t_list		*chan;
	t_channel	new_chan;
	int			k;

	k = -1;
	if (CLIENT(pos).channel != NULL)
		RET_ERR(MSG_E02);
	if (find_channel(channel))
		RET_ERR(MSG_E09);
	while (++k < MAX_CLIENTS)
		if (CLIENT_SOCK(k) > 0 && CLIENT(k).nick &&
				!ft_strcmp(CLIENT(k).nick, channel))
			RET_ERR(MSG_E01);
	new_chan.name = ft_strdup(channel);
	new_chan.users = NULL;
	chan = find_last_channel();
	if (chan)
		chan->next = ft_lstnew(&new_chan, sizeof(t_channel));
	else
		g_env.channels = ft_lstnew(&new_chan, sizeof(t_channel));
	return (do_join(pos, channel));
}
