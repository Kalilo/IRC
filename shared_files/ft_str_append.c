/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 11:03:00 by khansman          #+#    #+#             */
/*   Updated: 2017/07/09 11:03:01 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shared.h"

void	ft_str_append(char **s1, char *s2)
{
	char	*tmp;

	if (!s1 || !s2)
		return ;
	if (!*s1)
	{
		*s1 = ft_strdup(s2);
		return ;
	}
	tmp = ft_strjoin(*s1, s2);
	ft_strdel(s1);
	*s1 = tmp;
}

void	ft_str_append2(char *s1, char **s2)
{
	char	*tmp;

	if (!s2 || !s1)
		return ;
	if (!*s2)
	{
		*s2 = ft_strdup(s1);
		return ;
	}
	tmp = ft_strjoin(s1, *s2);
	ft_strdel(s2);
	*s2 = tmp;
}

char	*ft_str_append3(char **s1, char **s2)
{
	char	*tmp;

	if (!s1 || !s2 || !*s1 || !*s2)
		return (NULL);
	tmp = ft_strjoin(*s1, *s2);
	ft_strdel(s1);
	ft_strdel(s2);
	return (tmp);
}
