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

	if ((chan = find_channel_parent(channel)))
	{
		if (((t_channel *)(chan->content))->users)
		{
			MSG_ERROR = ft_strdup(MSG_E04);
			return (0);
		}
		tmp = chan;
		chan->next = chan->next->next;
		free(tmp->content);
		free(tmp);
	}
	else if (g_env.channels &&
		!ft_strcmp(((t_channel *)(g_env.channels))->name, channel))
	{
		tmp = g_env.channels;
		g_env.channels = tmp->next;
		free(tmp->content);
		free(tmp);
	}
	else
	{
		MSG_ERROR = ft_strdup(MSG_E03);
		return (0);
	}
	return (1);
}