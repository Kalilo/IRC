/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 10:32:12 by khansman          #+#    #+#             */
/*   Updated: 2017/07/21 10:32:17 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

t_list		*find_user_in_chan(t_list *channel, int pos)
{
	t_list	*user;

	user = ((t_channel *)(channel->content))->users;
	while (user && ((t_user *)(user->content))->sock != CLIENT_SOCK(pos))
		user = user->next;
	return (user);
}

t_list		*find_user_parent_in_chan(t_list *channel, int pos)
{
	t_list	*user;
	t_list	*parent;

	parent = NULL;
	user = ((t_channel *)(channel->content))->users;
	while (user && ((t_user *)(user->content))->sock != CLIENT_SOCK(pos))
	{
		parent = user;
		user = user->next;
	}
	if (((t_user *)(user->content))->sock == CLIENT_SOCK(pos))
		return (parent);
	return (NULL);
}

t_list		*find_last_user_in_chan(t_list *channel)
{
	t_list	*user;

	user = ((t_channel *)(channel->content))->users;
	while (user && user->next)
		user = user->next;
	return (user);
}

int			find_user_by_name(char *name)
{
	int		k;

	k = -1;
	while (++k < MAX_CLIENTS)
		if (CLIENT_SOCK(k) && CLIENT(k).nick &&
				!ft_strcmp(CLIENT(k).nick, name))
			return (k);
	return (-1);
}
