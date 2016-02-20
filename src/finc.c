/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:08:12 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/20 16:51:53 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void 	sortfunc(char *param, t_lst **lst, int skip)
{
	int rev;
	int a;
	t_maxlen *i;
	if (!countlst(*lst))
		return ;
	i = malloc(sizeof(t_maxlen));
	ct_all((*lst)->next, &i);
	rev = (ft_strchr(param, 'r')) ? -1 : 1;
	a = (ft_strchr(param, 'a')) ? 0 : 1;
	sortliste(lst, rev);
	if (ft_strchr(param, 't'))
		sortbytime(lst, rev);
	if (ft_strchr(param , 'l'))
		printlist((*lst)->next, *i, a, skip);
	else
		print((*lst)->next, skip, a);
}
void 	error_disp(t_lst *error)
{
	if (!error->next)
		return ;
	sortliste(&error, 1);
	while (error->next)
	{
		error = error->next;
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(error->info.name, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
}
int permDenied(char *s)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	return (0);
}
