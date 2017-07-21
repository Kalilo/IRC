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

char	do_delete(char *channel)
{
	t_list		*chan;
	t_list		*tmp;

	chan = g_env.channels;
	if (ft_strcmp(channel, ((t_channel *)(chan->next))->name))
	{
		g_env.channels = chan->next;
		free(chan->content);
		free(chan);
		return (1);
	}
	while (chan && chan->next &&
			ft_strcmp(channel, ((t_channel *)(chan->next->content))->name))
		chan = chan->next;
	if (!chan || !chan->next)
	{
		MSG_ERROR = "Channel doesn't exist, or isn't avaliable.\n";
		return (0);
	}
	if (((t_channel *)(chan->content))->users)
	{
		MSG_ERROR = "Can't delete a channel which has users in it.\n";
		return (0);
	}
	tmp = chan->next;
	chan->next = chan->next->next;
	free(tmp->content);
	free(tmp);
	return (1);
}