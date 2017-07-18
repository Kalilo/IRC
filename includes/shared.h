/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/06 10:42:11 by khansman          #+#    #+#             */
/*   Updated: 2017/07/06 10:42:12 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

/*
** ----------\
** Includes   |
** ----------/
*/

/*
** System
*/
# include <sys/mman.h>
# include <sys/select.h>
# include <sys/socket.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>

/*
** Standard
*/
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/*
** Uncommon
*/
# include <arpa/inet.h>
# include <fcntl.h>
# include <netdb.h>
# include <signal.h>

/*
** Own Headers
*/
# include "../libft/includes/libft.h"

/*
** Bonus
*/
# include <limits.h>

/*
** ----------\
** Defines    |
** ----------/
*/

/*
** Defines
*/

/*
** Typedefs
*/
typedef struct sockaddr_in		t_sock_addrin;
typedef struct hostent			t_hostent;
typedef struct sockaddr			t_sock_addr;
typedef unsigned long long		t_ull;

/*
** ----------\
** Structures |
** ----------/
*/

/*
** ----------\
** Prototypes |
** ----------/
*/

/*
** error_quit.c
*/
void	error_quit(char *str);
void	exit_message(char *str);

/*
** ft_str_append.c
*/
void	ft_str_append(char **s1, char *s2);
void	ft_str_append2(char *s1, char **s2);
char	*ft_str_append3(char **s1, char **s2);

/*
** ft_swap_str.c
*/
void	ft_swap_str(char **s1, char **s2);

/*
** Bonus Summary:
** -> comming soon!
*/

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif