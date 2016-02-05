/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:01:34 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/05 03:32:37 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	space(int i, int max, int pad)
{
	while (i < max + pad)
	{
		ft_putchar(' ');
		i++;
	}
}

void sortliste(t_lst **lst, int rev)
{
	t_lst *start;
	t_lst *ptr;
	int i;

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
