/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:30:47 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/13 15:13:43 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

t_lst	*add(t_lst *liste, char *s, int index, t_file info)
{
	t_lst *tmp;

	tmp = malloc(sizeof(t_lst));
	if (tmp)
	{
		tmp->s = s;
		tmp->i = index;
		tmp->info = info;
		tmp->next = liste;	
	}
	return (tmp);

}
t_lst	*printlist(t_lst *lst)
{
	printf("%s  ",lst->info.perm);
	printf("%d  ",lst->info.nblink);
	printf("%s  ",lst->info.owner);
	printf("%s  ",lst->info.group);
	printf("%lld  ",lst->info.size);
	printf("%s \n",lst->info.name);
	write(1,lst->info.name, ft_strlen(lst->info.name));
	ft_putchar('\n');
	lst = lst->next;
	return (lst);
}
