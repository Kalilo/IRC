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

char	show_channels(int sd)
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
	send(sd, str, ft_strlen(str), MSG_DONTWAIT);
	free(str);
	return (1);
}

char	do_who(int sd)
{
	t_list		*chan;
	char		*str;

	chan = find_channel(CLIENT(sd).channel);
	if (!chan)
		return (show_channels(sd));
	chan = ((t_channel *)(chan->content))->users;
	str = ft_strdup("Users: ");
	while (chan)
	{
		ft_str_append(&str, ((t_user *)chan->content)->nick);
		if (chan->next)
			ft_str_append(&str, "; ");
		chan = chan->next;
	}
	ft_str_append(&str, "\n");
	send(sd, str, ft_strlen(str), MSG_DONTWAIT);
	free(str);
	return (1);
}
