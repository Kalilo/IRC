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

char	do_who(int sd)
{
	t_list		*chan;
	char		*str;

	chan = g_env.channels;
	while (chan && ft_strcmp(CLIENT(sd).channel,
			((t_channel *)(chan->content))->name))
		chan = chan->next;
	if (!chan)
	{
		MSG_ERROR = ft_strdup(MSG_E08);
		return (0);
	}
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
