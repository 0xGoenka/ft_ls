/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 20:03:31 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/03 17:13:33 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	sortfunc(char *param, t_lst **lst, int skip, char *path)
{
	int			rev;
	int			a;
	t_maxlen	*i;

	if (!countlst(*lst))
		return ;
	i = malloc(sizeof(t_maxlen));
	ct_all((*lst)->next, &i, path);
	rev = (ft_strchr(param, 'r')) ? -1 : 1;
	a = (ft_strchr(param, 'a')) ? 0 : 1;
	sortliste(lst, rev);
	if (ft_strchr(param, 't'))
		sortbytime(lst, rev);
	if (ft_strchr(param, 'l'))
	{
		if (skip != 'd')
			total((*lst)->next, param);
		printlist((*lst)->next, *i, a, skip);
	}
	else
		print((*lst)->next, skip, a, path);
}

void	sortliste(t_lst **lst, int rev)
{
	t_lst	*start;
	t_lst	*ptr;
	int		i;

	start = *lst;
	i = 1;
	while (i == 1)
	{
		i = 0;
		while ((*lst)->next->next)
		{
			if (ft_strcmp((*lst)->next->info.name,
			(*lst)->next->next->info.name) * rev > 0)
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

void	sortbytime(t_lst **lst, int rev)
{
	t_lst	*start;
	t_lst	*ptr;
	int		i;

	sortliste(lst, -1);
	start = *lst;
	i = 1;
	while (i == 1)
	{
		i = 0;
		while ((*lst)->next->next)
		{
			if (-rev * (*lst)->next->info.modif >
			-rev * (*lst)->next->next->info.modif)
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
