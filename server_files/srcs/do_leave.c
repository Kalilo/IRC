/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_leave.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:31:57 by khansman          #+#    #+#             */
/*   Updated: 2017/07/20 10:31:58 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

char	do_leave(int pos, char *channel)
{
	t_list		*chan;
	t_list		*user;
	t_list		*tmp;

	if (!(chan = find_channel(channel)))
		RET_ERR(MSG_E03);
	if (CLIENT(pos).channel && !ft_strcmp(CLIENT(pos).channel, channel))
		ft_strdel(&CLIENT(pos).channel);
	if (!(find_user_in_chan(chan, pos)))
		RET_ERR(MSG_E07);
	if (!(user = find_user_parent_in_chan(chan, pos)))
	{
		tmp = ((t_channel *)(chan->content))->users;
		((t_channel *)(chan->content))->users = tmp->next;
	}
	else
	{
		tmp = user->next;
		user->next = tmp->next;
	}
	free(tmp->content);
	free(tmp);
	return (1);
}
