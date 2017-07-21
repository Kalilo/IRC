/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_request.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:25:14 by khansman          #+#    #+#             */
/*   Updated: 2017/07/20 10:25:16 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

char	manage_request(int client)
{
	if (!ft_strncmp(MESSAGE, "/connect ", 9))
		return do_nick(client, MESSAGE + 9);
	if (!ft_strncmp(MESSAGE, "/join ", 6))
		return do_join(client, MESSAGE + 6);
	if (!ft_strncmp(MESSAGE, "/leave ", 7))
		return do_leave(client, MESSAGE + 7);
	if (!ft_strncmp(MESSAGE, "/msg ", 5))
		return do_msg(client, MESSAGE + 5);
	if (!ft_strncmp(MESSAGE, "/nick ", 6))
		return do_nick(client, MESSAGE + 6);
	if (!ft_strcmp(MESSAGE, "/who"))
		return do_who(client);
	if (!ft_strncmp(MESSAGE, "/create ", 8))
		return do_create(client, MESSAGE + 8);
	if (!ft_strncmp(MESSAGE, "/delete ", 8))
		return do_delete(MESSAGE + 8);
	MSG_ERROR = ft_strdup(MSG_E06);
	return (0);
}
