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

t_list		*find_user_in_chan(t_list *channel, int sd)
{
	t_list	*user;

	user = ((t_channel *)(channel->content))->users;
	while (user && ((t_user *)(user->content))->sock != sd)
		user = user->next;
	return (user);
}

t_list		*find_user_parent_in_chan(t_list *channel, int sd)
{
	t_list	*user;
	t_list	*parent;

	parent = NULL;
	user = ((t_channel *)(channel->content))->users;
	while (user && ((t_user *)(user->content))->sock != sd)
	{
		parent = user;
		user = user->next;
	}
	if (((t_user *)(user->content))->sock == sd)
		return (parent);
	return (NULL);
}

t_list		*find_last_user_in_chan(t_list *channel)
{
	t_list	*user;

	user = ((t_channel *)(channel->content))->users;
	while (user && user->next)
		user = user->next;
	if (user == ((t_channel *)(channel->content))->users)
		return (NULL);
	return (user);
}
