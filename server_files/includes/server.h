/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 10:26:39 by khansman          #+#    #+#             */
/*   Updated: 2017/07/06 10:26:40 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

/*
** ----------\
** Includes   |
** ----------/
*/

# include "../../includes/shared.h"

/*
** ----------\
** Defines    |
** ----------/
*/

/*
** defined constants
*/
# define MAX_CLIENTS	1024

/*
** shorthand
*/
# define MASTER_SOCK	g_env.main_sock.sock
# define MASTER_OPT		g_env.main_sock.sock_opt
# define MASTER_ADDR	g_env.main_sock.addr
# define MASTER_ADDRLEN	g_env.main_sock.addrlen

/*
** enums
*/
typedef enum		e_msg_type
{
	msg_none,
	msg_direct,
	msg_channel,
	msg_command
}					t_msg_type;

typedef enum		e_bool
{
	false,
	true
}					t_bool;

/*
** ----------\
** Structures |
** ----------/
*/

/*
** linked lists
*/

typedef struct		s_user
{
	int				sock;
	char			*nick;
	t_sock_addr		machine;
}					t_user;

typedef struct		s_channel
{
	char			*name;
	t_list			*users;
}					t_channel;

/*
** env components
*/
typedef struct		s_msg
{
	t_msg_type		type;
	char			*msg;
	char			*channel;
	char			*send_nick;
	char			*dest_nick;
}					t_msg;

typedef struct		s_main_sock
{
	int				sock_opt;
	int				sock;
	int				addrlen;
	t_sock_addrin	addr;
}					t_main_sock;

typedef struct		s_client_def
{
	int				new_sock;
	fd_set			read_fds;
	t_user			client_sock[MAX_CLIENTS];
}					t_client_def;

/*
** env
*/
typedef struct		s_env
{
	t_main_sock		main_sock;
	t_client_def	clients;
	t_msg			msg;
	t_list			*channels;
}					t_env;

/*
** ----------\
** Globals    |
** ----------/
*/

# ifdef SERVER_MAIN

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
** init.c
*/
char				init(int port);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
