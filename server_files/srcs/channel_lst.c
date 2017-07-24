/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   channel_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:24:33 by khansman          #+#    #+#             */
/*   Updated: 2017/07/21 10:24:35 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_list		*find_channel(char *name)
{
	t_list		*chan;

	if (!name)
		return (NULL);
	chan = g_env.channels;
	while (chan && ft_strcmp(name, ((t_channel *)(chan->content))->name))
		chan = chan->next;
	return (chan);
}

t_list		*find_channel_parent(char *name)
{
	t_list		*chan;
	t_list		*parent;

	if (!name)
		return (NULL);
	parent = NULL;
	chan = g_env.channels;
	while (chan && ft_strcmp(name, ((t_channel *)(chan->content))->name))
	{
		parent = chan;
		chan = chan->next;
	}
	if (!ft_strcmp(name, ((t_channel *)(chan->content))->name))
		return (parent);
	return (NULL);
}

t_list		*find_last_channel(void)
{
	t_list		*chan;

	chan = g_env.channels;
	while (chan && chan->next)
		chan = chan->next;
	return (chan);
}
