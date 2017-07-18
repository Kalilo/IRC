/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_quit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 10:37:35 by khansman          #+#    #+#             */
/*   Updated: 2017/07/06 10:37:37 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

void	error_quit(char *str)
{
	ft_putstr("ERROR: ");
	ft_putendl(str);
	exit(0);
}

void	exit_message(char *str)
{
	ft_putendl(str);
	exit(0);
}
