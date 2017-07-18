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
** defines
*/
# define MAX_CLIENTS	1024

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

/*
** ----------\
** Structures |
** ----------/
*/

/*
** linked lists
*/

typedef struct		t_user
{
	int				sock;
	char			*nick;
	t_sock_addr		machine;
}					s_user;

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
	s_user			client_sock[MAX_CLIENTS];
}					t_client_def;

/*
** env
*/
typedef struct		s_env
{
	t_main_sock		main_sock;
	t_client_def	clients;
	t_msg			msg;
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
** file.c
*/

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
