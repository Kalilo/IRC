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

char	do_join(int pos, char *channel)
{
	t_list		*chan;
	t_list		*user;

	if (!(chan = find_channel(channel)))
		RET_ERR(MSG_E03);
	if ((CLIENT(pos).channel && !ft_strcmp(CLIENT(pos).channel, channel))
			|| find_user_in_chan(chan, pos))
		RET_ERR(MSG_E05);
	if ((user = find_last_user_in_chan(chan)))
		user->next = ft_lstnew(&CLIENT(pos), sizeof(t_user));
	else
		((t_channel *)(chan->content))->users =
			ft_lstnew(&CLIENT(pos), sizeof(t_user));
	ft_strdel(&CLIENT(pos).channel);
	CLIENT(pos).channel = ft_strdup(channel);
	return (1);
}
