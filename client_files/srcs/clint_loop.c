/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clint_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:44:26 by khansman          #+#    #+#             */
/*   Updated: 2017/07/22 10:44:27 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	client_loop(void)
{
	char		*line;

	ft_putstr("Enter Command: ");
	line = NULL;
	while (get_next_line(STDIN_FILENO, &line) > 0 && strcmp(line, "quit"))
	{
		if (!valid_command(line))
		{
			ft_putstr("Invalid Command!\nEnter Command: ");
			ft_strdel(&line);
			continue;
		}
		write_to_socket(line);
		ft_strdel(&line);
		line = read_from_socket();
		ft_putendl(line);
		ft_strdel(&line);
		ft_putstr("Enter Command: ");
	}
	if (!strcmp(line, "quit"))
		write_to_socket(line);
	ft_strdel(&line);
}
