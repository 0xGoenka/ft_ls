/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:30:47 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/25 18:48:29 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	add(t_lst *lst, char *s, int index, t_file info)
{
	while (lst->next != NULL)
		lst = lst->next;
	if(!(lst->next = malloc(sizeof(t_lst))))
		perror("malloc esteban : ");
	lst = lst->next;
	lst->i = index;
	lst->next = NULL;
	lst->info = info;
}
void	printlist(t_lst *lst,int i, int y)
{
	if (!lst)
		return;
	ft_putstr(lst->info.perm);
	space(nu_len(lst->info.nblink, 10), i);
	ft_putnbr(lst->info.nblink);
	ft_putstr(" ");
	ft_putstr(lst->info.owner);
	ft_putstr("  ");
	ft_putstr(lst->info.group);
	space(nu_len(lst->info.size , 10), y);
	ft_putnbr(lst->info.size);
	ft_putstr(" ");
	ft_putstr(lst->info.time);
	ft_putstr("  ");
	ft_putstr(lst->info.name);
	ft_putstr("  ");
	ft_putchar('\n');
	printlist(lst->next, i, y);
}
void	print(t_lst *lst)
{
	if (!lst)
		return;
	ft_putstr(lst->info.name);
	ft_putchar('\t');
	print(lst->next);
}
t_lst	*init(void)
{
	t_lst *lst;
	
	lst = (t_lst *)malloc(sizeof(t_lst));
	lst->i = -1;
	lst->next = NULL;
	return (lst);
}
