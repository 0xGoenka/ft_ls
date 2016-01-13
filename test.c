/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 13:56:52 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/13 14:37:04 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int main()
{
	t_lst *liste;	
	t_lst *ptr;
	liste = getinfo("libft");
	ptr = liste;
	while (liste)
	{
		liste = printlist(liste);
	}
	return (0);
}
