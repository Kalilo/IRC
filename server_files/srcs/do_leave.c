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

	ft_putstr("1\n");//debug
	if (!(chan = find_channel(channel)))
	{
		MSG_ERROR = ft_strdup(MSG_E03);
		return (0);
	}
	ft_putstr("2\n");//debug
	if (!ft_strcmp(CLIENT(sd).channel, channel))
		ft_strdel(&CLIENT(sd).channel);
	ft_putstr("3\n");//debug
	if (!(find_user_in_chan(chan, sd)))// MSG_ERROR = ft_strdup(MSG_E07);
		return (1);
	ft_putstr("4\n");//debug
	if (!(user = find_user_parent_in_chan(chan, sd)))
	{
		ft_putstr("5\n");//debug
		tmp = ((t_channel *)(chan->content))->users;
		((t_channel *)(chan->content))->users = tmp->next;
	}
	else
	{
		ft_putstr("6\n");//debug
		tmp = user->next;
		user->next = tmp->next;
	}
	// ft_strdel(&CLIENT(sd).channel);
	ft_putstr("7\n");//debug
	free(tmp->content);
	free(tmp);
	return (1);
}
