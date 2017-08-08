/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 10:26:25 by khansman          #+#    #+#             */
/*   Updated: 2017/07/06 10:26:26 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

/*
** ----------\
** Includes   |
** ----------/
*/

# include "../../includes/shared.h"

/*
** ----------\
** Structures |
** ----------/
*/

typedef struct		s_env
{
	int				socket_fd;
	int				port;
	t_hostent		*server;
	t_sock_addrin	server_addr;
	char			*error;
	fd_set			fds;
}					t_env;

/*
** ----------\
** Defines    |
** ----------/
*/
# define BREAK_CON if(!ft_strcmp(line,"/quit"))break

/*
** ----------\
** Globals    |
** ----------/
*/

# ifdef CLIENT_MAIN

t_env				g_env;

# else

extern t_env		g_env;

# endif

/*
** ----------\
** Prototypes |
** ----------/
*/

/*
** client_loop.c
*/
void				client_loop(void);

/*
** connect_to_server.c
*/
void				connect_to_server(void);

/*
** do_connect.c
*/
char				do_connect(char *details);

/*
** read_from_socket.c
*/
char				*read_from_socket(void);

/*
** write_to_socket.c
*/
void				write_to_socket(char *line);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
