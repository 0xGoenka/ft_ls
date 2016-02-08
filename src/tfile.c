/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 02:34:11 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/08 05:06:21 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		addfile(t_name *lst, char *name)
{
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = malloc(sizeof(t_name));
	lst = lst->next;
	lst->name = name;
	lst->next = NULL;
}
t_name		*initfile(void)
{
	t_name *lst;

	lst = malloc(sizeof(t_name));
	lst->next = NULL;
	return (lst);
}
void		printname(t_name *file)
{
	if (!file)
		return ;
	while (file)
	{
		ft_putstr(file->name);
		ft_putchar('\n');
		file = file->next;
	}
}
