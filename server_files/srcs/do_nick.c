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

char	do_nick(int sd, char *nick)
{
	if (ft_strlen(nick) > 9)
	{
		MSG_ERROR = "Nicknames have to be less than 10 characters.";
		return (0);
	}
	ft_strdel(&CLIENT(sd).nick);
	CLIENT(sd).nick = ft_strdup(nick);
	return (1);
}
