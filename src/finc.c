/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:08:12 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/18 17:54:33 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void 	sortfunc(char *param, t_lst **lst)
{
	int rev;
	int a;
	t_maxlen *i;

	i = malloc(sizeof(t_maxlen));
	ct_all((*lst)->next, &i);
	rev = (ft_strchr(param, 'r')) ? 1 : -1;
	a = 1;
	sortliste(lst, rev);
	if (ft_strchr(param, 't'))
		sortbytime(lst, rev);
	if (ft_strchr(param , 'l'))
		printlist((*lst)->next, *i, a);
	else
		print((*lst)->next);
		putchar('\n');
}
void 	error_disp(t_lst *error)
{
	sortliste(&error, 1);
	while (error->next)
	{
		error = error->next;
		ft_putstr("ft_ls: ");
		ft_putstr(error->info.name);
		ft_putstr(": No such file or directory\n");

	}
}
