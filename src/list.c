/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:30:47 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/24 20:08:57 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void		add(t_lst *lst, t_file info)
{
	while (lst->next != NULL)
		lst = lst->next;
	if (!(lst->next = malloc(sizeof(t_lst))))
		perror("malloc esteban : ");
	lst = lst->next;
	lst->next = NULL;
	lst->info = info;
}

t_lst		*init(void)
{
	t_lst *lst;

	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->next = NULL;
	return (lst);
}

void		lstdel(t_lst *lst)
{
	t_lst *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
		tmp = NULL;
	}
}

int			countlst(t_lst *lst)
{
	int i;

	i = 0;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
