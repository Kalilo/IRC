/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:04:17 by khansman          #+#    #+#             */
/*   Updated: 2017/07/22 10:04:19 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	init(int av)
{
	if ((g_env.socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		error_quit("Can't open socket!");
	(void)av;
}
