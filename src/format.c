/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 12:01:34 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/25 13:14:57 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void	space(int i, int max)
{
	while (i < max)
	{
		ft_putchar(' ');
		i++;
	}
		ft_putchar(' ');
		ft_putchar(' ');
}
