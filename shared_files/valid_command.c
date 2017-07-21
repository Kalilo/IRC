/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 10:16:51 by khansman          #+#    #+#             */
/*   Updated: 2017/07/20 10:16:52 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

char	valid_command(char *str)
{
	if (!ft_strncmp(str, "/nick ", 6))
		return (1);
	if (!ft_strncmp(str, "/join ", 6))
		return (1);
	if (!ft_strncmp(str, "/leave ", 7))
		return (1);
	if (!ft_strncmp(str, "/who", 4))
		return (1);
	if (!ft_strncmp(str, "/msg ", 5))
		return (1);
	if (!ft_strncmp(str, "/connect ", 9))
		return (1);
	if (!ft_strncmp(str, "/create ", 8))
		return (1);
	if (!ft_strncmp(str, "/delete ", 8))
		return (1);
	return (0);
}
