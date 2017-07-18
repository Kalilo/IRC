/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 07:57:06 by khansman          #+#    #+#             */
/*   Updated: 2017/07/18 07:57:07 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define SERVER_MAIN
#include "../includes/server.h"

int		main(int ac, char **av)
{
	if (ac != 2)
		exit_message("Usage: ./server port");
	init(ft_atoi(av[1]));
}
