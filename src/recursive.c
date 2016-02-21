/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/21 11:21:42 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/21 17:57:03 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		rec_control(t_lst *lst, char *param)
{
	while (lst)
	{
		rec_main(lst->info.name, char *param, lst->info);
		lst = lst->next;
	}
	return (0);
}
int	rec_main(t_lst *lst, char *param, t_file info)
{
	t_lst *file;
	t_lst *start;

	printdir(getinfo(folder));
	if (info.perm[0] == 'd' && ft_strcmp(lst->info.name, ".") != 0 &&
	ft_strcmp(lst->info.name, "..") != 0)
	{
		rec_main(getpath());
	}

	return (0);
}
	void printdirrec(t_lst *lst , char *param, int nblst)
{
	t_lst *file;
	t_maxlen *i;

	i = malloc(sizeof(t_maxlen));
	if (!lst)
		return ;
	if (lst->info.perm[0] == 'd' && ft_strcmp(lst->info.name, ".") != 0 &&
	ft_strcmp(lst->info.name, "..") != 0)
	{
		if (nblst != 0)
		{
			ft_putchar('\n');
			ft_putstr(ft_strjoin(lst->info.name,":\n"));

		}
		if (!(file = getinfo(lst->info.name)))
		{
			permDenied(lst->info.name);
		}
		else
		{
			total(file->next);

		}
		recursive(lst->info.name);
	}
		printdirrec(lst->next, param, countlst(file->next));
}
