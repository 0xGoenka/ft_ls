/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:08:12 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/03 17:22:29 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	error_disp(t_lst *error)
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

int		permdenied(char *s)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(": Permission denied\n", 2);
	return (0);
}
