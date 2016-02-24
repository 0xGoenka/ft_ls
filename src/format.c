/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:01:34 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/24 20:38:15 by eleclet          ###   ########.fr       */
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

void total(t_lst *lst, char *param)
{
	size_t i;

	i = 0;
	while (lst)
	{
		if (!ft_strchr(param, 'a') && lst->info.name[0] == '.')
			lst = lst->next;
		else
		{
			i = i + lst->info.block;
			lst = lst->next;
		}
	}
	ft_putstr("total ");
	ft_putnbr((int)i);
	ft_putchar('\n');
}
