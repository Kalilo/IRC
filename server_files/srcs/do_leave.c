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

char	do_leave(int sd, char *channel)
{
	t_list		*chan;
	t_list		*user;
	t_list		*tmp;

	if (!(chan = find_channel(channel)))
	{
		MSG_ERROR = ft_strdup(MSG_E03);
		return (0);
	}
	if (!(find_user_in_chan(chan, sd)))
	{
		MSG_ERROR = ft_strdup(MSG_E07);
		return (0);
	}
	if (!(user = find_user_parent_in_chan(chan, sd)))
	{
		tmp = ((t_channel *)(chan->content))->users;
		((t_channel *)(chan->content))->users = tmp->next;
	}
	else
	{
		tmp = user->next;
		user->next = tmp->next;
	}
	ft_strdel(&CLIENT(sd).channel);
	free(tmp->content);
	free(tmp);
	return (1);
}
