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
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/mman.h>
# include <sys/stat.h>
# include <sys/select.h>
# include <sys/time.h>

/*
** Standard
*/
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

/*
** Uncommon
*/
# include <signal.h>
# include <fcntl.h>
# include <netdb.h>
# include <arpa/inet.h>

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