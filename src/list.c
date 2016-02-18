/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:30:47 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/18 16:45:20 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	add(t_lst *lst, t_file info)
{
	while (lst->next != NULL)
		lst = lst->next;
	if(!(lst->next = malloc(sizeof(t_lst))))
		perror("malloc esteban : ");
	lst = lst->next;
	lst->next = NULL;
	lst->info = info;

}
void	printlist(t_lst *lst, t_maxlen i, int a)
{
	if (!lst)
		return;
	if (a && lst->info.name[0] == '.')
		printlist(lst->next, i, a);
	else
	{
		ft_putstr(lst->info.perm);
		space(nu_len(lst->info.nblink, 10), i.a, 2);
		ft_putnbr(lst->info.nblink);
		ft_putstr(" ");
		ft_putstr(lst->info.owner);
		space(ft_strlen(lst->info.owner), i.c, 1);
		space(ft_strlen(lst->info.group), i.d, 1);
		ft_putstr(lst->info.group);
		space(nu_len(lst->info.size , 10), i.b, 2);
		ft_putnbr(lst->info.size);
		ft_putstr(" ");
		ft_putstr(lst->info.time);
		ft_putstr("  ");
		ft_putstr(lst->info.name);
		ft_putstr("  ");
		ft_putchar('\n');
		printlist(lst->next, i, a);
	}
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
