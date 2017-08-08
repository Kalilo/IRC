/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_who.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:32:09 by khansman          #+#    #+#             */
/*   Updated: 2017/07/20 10:32:10 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

char	show_channels(int pos)
{
	t_list		*chan;
	char		*str;

	if (!(chan = g_env.channels))
		str = ft_strdup("No Channels Avaliable.");
	else
		str = ft_strdup("Channels: ");
	while (chan)
	{
		ft_str_append(&str, ((t_channel *)chan->content)->name);
		if (chan->next)
			ft_str_append(&str, "; ");
		chan = chan->next;
	}
	ft_str_append(&str, "\n");
	write_msg_to_sock(CLIENT_SOCK(pos), str);
	ft_strdel(&str);
	return (2);
}

char	do_who(int pos)
{
	t_list		*chan;
	char		*str;

	chan = find_channel(CLIENT(pos).channel);
	if (!chan)
		return (show_channels(pos));
	chan = ((t_channel *)(chan->content))->users;
	str = ft_strdup("Users: ");
	while (chan)
	{
		if (((t_user *)chan->content)->nick)
			ft_str_append(&str, ((t_user *)chan->content)->nick);
		else
			ft_str_append(&str, "(anonymous)");
		if (chan->next)
			ft_str_append(&str, "; ");
		chan = chan->next;
	}
	ft_str_append(&str, "\n");
	write_msg_to_sock(CLIENT_SOCK(pos), str);
	ft_strdel(&str);
	return (2);
}
