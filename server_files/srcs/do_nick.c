/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_nick.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:31:04 by khansman          #+#    #+#             */
/*   Updated: 2017/07/20 10:31:20 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

/*
** Very basic, need to be upgraded
*/

char	do_nick(int pos, char *nick)
{
	int		k;

	k = -1;
	if (ft_strlen(nick) > 9)
		RET_ERR(MSG_E00);
	while (++k < MAX_CLIENTS)
		if (CLIENT_SOCK(k) > 0 && CLIENT(k).nick &&
				!ft_strcmp(CLIENT(k).nick, nick))
			RET_ERR(MSG_E01);
	if (find_channel(nick))
		RET_ERR(MSG_E01);
	ft_strdel(&CLIENT(pos).nick);
	CLIENT(pos).nick = ft_strdup(nick);
	return (1);
}
