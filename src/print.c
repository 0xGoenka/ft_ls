/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 19:53:45 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/24 20:38:58 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void printdir(t_lst *lst , char *param, int nblst)
{
	t_lst *file;
	t_maxlen *i;

	i = malloc(sizeof(t_maxlen));
	if (!lst)
		return ;
	if (lst->info.perm[0] == 'd')
	{
		if (nblst > 1)
		{
			ft_putchar('\n');
			ft_putstr(ft_strjoin(lst->info.name,":\n"));

		}
		if (!(file = getinfo(lst->info.name)))
		{
			permDenied(lst->info.name);
			return ;
		}
		total(file->next, param);
		sortfunc(param, &file, 0);
	}
		printdir(lst->next, param, nblst);
}

void	printlist(t_lst *lst, t_maxlen i, int a, int skip)
{
	if (!lst)
		return ;
	if (a && lst->info.name[0] == '.')
		printlist(lst->next, i, a, skip);
	else
	{
		if (skip == 'f' && lst->info.perm[0] != 'd')
			printlist(lst->next, i, a, skip);
		else
		{
			if (skip == 'd' && lst->info.perm[0] == 'd')
				printlist(lst->next, i, a, skip);
			else
			{
				printlext(lst, i);
				printlist(lst->next, i, a, skip);
			}
		}
	}
}

void	printlext(t_lst *lst, t_maxlen i)
{
	ft_putstr(lst->info.perm);
	space(nu_len(lst->info.nblink, 10), i.a, 1);
	ft_putnbr(lst->info.nblink);
	ft_putstr(" ");
	ft_putstr(lst->info.owner);
	space(ft_strlen(lst->info.owner), i.c, 1);
	space(ft_strlen(lst->info.group), i.d, 1);
	ft_putstr(lst->info.group);
	space(nu_len(lst->info.size, 10), i.b, 2);
	ft_putnbr(lst->info.size);
	ft_putstr(" ");
	ft_putstr(lst->info.time);
	ft_putstr(" ");
	ft_putstr(lst->info.name);
	ft_putchar('\n');
}

void	print(t_lst *lst, int skip, int a)
{
	if (!lst)
		return ;
	if (a && lst->info.name[0] == '.')
		print(lst->next, skip, a);
	else
	{
		if (skip == 'f' && lst->info.perm[0] != 'd')
			print(lst->next, skip, a);
		else
		{
			if (skip == 'd' && lst->info.perm[0] == 'd')
				print(lst->next, skip, a);
			else
			{
				ft_putstr(lst->info.name);
				ft_putchar('\n');
				print(lst->next, skip, a);
			}
		}
	}
}
