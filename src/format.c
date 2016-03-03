/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:01:34 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/03 17:18:47 by eleclet          ###   ########.fr       */
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

char	*pad(int max, int major, int minor)
{
	char *tmp;
	char *ret;

	ret = NULL;
	tmp = ft_itoa(major);
	ret = ft_strjoin(tmp, ", ");
	free(tmp);
	while (nu_len(minor, 10) < max)
	{
		ret = ft_strjoin(ret, " ");
		max--;
	}
	ret = ft_strjoin(ret, ft_itoa(minor));
	return (ret);
}

void	total(t_lst *lst, char *param)
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

void	ct_all(t_lst *lst, t_maxlen **i, char *path)
{
	(*i)->a = findmax(lst, 1);
	(*i)->b = findmax(lst, 0);
	(*i)->c = findmaxe(lst, 1);
	(*i)->d = findmaxe(lst, 0);
	(*i)->path = ft_strdup(path);
}
