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
# define MASTER_MAX_SD	g_env.main_sock.max_sd

# define CLIENT(x)		g_env.clients.client_sock[x]
# define CLIENT_READ_FD	g_env.clients.read_fds
# define CLIENT_SOCK(x)	g_env.clients.client_sock[x].sock
# define NEW_CLIENT_SOC	g_env.clients.new_sock

# define MESSAGE		g_env.msg.msg
# define MSG_ERROR		g_env.msg.error

/*
** Strings
*/
# define MSG_E00 "Nicknames have to be less than 10 characters.\n"
# define MSG_E01 "Nickname already in use.\n"
# define MSG_E02 "Users can't create a channel while in one.\n"
# define MSG_E03 "Channel doesn't exist, or isn't avaliable.\n"
# define MSG_E04 "Can't delete a channel which has users in it.\n"
# define MSG_E05 "Already in channel.\n"
# define MSG_E06 "UNKNOWN COMMAND\n"
# define MSG_E07 "Can't leave channels you aren't in.\n"
# define MSG_E08 "Can't run command outside of a channel\n"
# define MSG_E09 "Channel already exists.\n"

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
	char			*channel;
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
	char			*error;
}					t_msg;

typedef struct		s_main_sock
{
	int				sock_opt;
	int				sock;
	int				addrlen;
	int				max_sd;
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
	int				active_sock;
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
** accept_new_client.c
*/
void				accept_new_client(void);

/*
** channel_lst.c
*/
t_list				*find_channel(char *name);
t_list				*find_channel_parent(char *name);
t_list				*find_last_channel(void);

/*
** do_connect.c
*/
char				do_connect(int client, char *details);

/*
** do_create.c
*/
char				do_create(int sd, char *channel);

/*
** do_delete.c
*/
char				do_delete(char *channel);

/*
** do_join.c
*/
char				do_join(int client, char *channel);

/*
** do_leave.c
*/
char				do_leave(int client, char *channel);

/*
** do_msg.c
*/
char				do_msg(int client, char *msg_details);

/*
** do_nick.c
*/
char				do_nick(int client, char *nick);

/*
** do_who.c
*/
char				do_who(int client);

/*
** init.c
*/
char				init(int port);

/*
** main_loop.c
*/
void				main_loop(void);

/*
** manage_clients.c
*/
void				manage_clients(void);

/*
** manage_request.c
*/
char				manage_request(int client);

/*
** prep_client_sockets.c
*/
void				prep_client_sockets(void);

/*
** user_lst.c
*/
t_list				*find_user_in_chan(t_list *channel, int sd);
t_list				*find_user_parent_in_chan(t_list *channel, int sd);
t_list				*find_last_user_in_chan(t_list *channel);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
