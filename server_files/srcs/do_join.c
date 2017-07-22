/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:31:49 by khansman          #+#    #+#             */
/*   Updated: 2017/07/20 10:31:50 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

char	do_join(int sd, char *channel)
{
	t_list		*chan;
	t_list		*user;

	if (!(chan = find_channel(channel)))
	{
		MSG_ERROR = ft_strdup(MSG_E03);
		return (0);
	}
	if ((CLIENT(sd).channel && !ft_strcmp(CLIENT(sd).channel, channel))
		|| find_user_in_chan(chan, sd))
	{
		MSG_ERROR = ft_strdup(MSG_E05);
		return (0);
	}
	if ((user = find_last_user_in_chan(chan)))
		user->next = ft_lstnew(&CLIENT(sd), sizeof(t_user));
	else
		((t_channel *)(chan->content))->users =
			ft_lstnew(&CLIENT(sd), sizeof(t_user));
	ft_strdel(&CLIENT(sd).channel);
	CLIENT(sd).channel = ft_strdup(channel);
	return (1);
}
