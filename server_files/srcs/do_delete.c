/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 08:47:20 by khansman          #+#    #+#             */
/*   Updated: 2017/07/21 08:47:21 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

/*
** Used for deleting channels
*/

char	do_delete(int pos, char *channel)
{
	t_list		*chan;
	t_list		*tmp;

	if (CLIENT(pos).channel != NULL)
		RET_ERR(MSG_E14);
	if (!find_channel(channel))
		RET_ERR(MSG_E15);
	if ((chan = find_channel_parent(channel)))
	{
		if (((t_channel *)(chan->content))->users)
			RET_ERR(MSG_E04);
		tmp = chan;
		chan->next = chan->next->next;
	}
	else if (g_env.channels &&
		ft_strcmp(((t_channel *)(g_env.channels))->name, channel))
	{
		if (((t_channel *)(g_env.channels->content))->users)
			RET_ERR(MSG_E04);
		tmp = g_env.channels;
		g_env.channels = tmp->next;
	}
	else
		RET_ERR(MSG_E03);
	return (1);
}
