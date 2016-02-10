/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tfile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 02:34:11 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/10 11:00:37 by eleclet          ###   ########.fr       */
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
void sortname(t_name **lst, int rev)
{
	t_name *start;
	t_name *ptr;
	int i;

	start = *lst;
	i = 1;
	while (i == 1 && (*lst)->next)
	{
		i = 0;
		while ((*lst)->next->next)
		{
			if (ft_strcmp((*lst)->next->name,
			(*lst)->next->next->name) * rev > 0)
			{
				ptr = (*lst)->next;
				(*lst)->next = (*lst)->next->next;
				ptr->next = (*lst)->next->next;
				(*lst)->next->next = ptr;
				i = 1;
			}
			*lst = (*lst)->next;
		}
		*lst = start;
	}
}
