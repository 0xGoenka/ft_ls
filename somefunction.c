/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somefunction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:20:05 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/10 20:18:50 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*getpath(char *path, char *folder)
{
	size_t len;
	size_t len2;
	size_t i;
	char *s;
	
	len = ft_strlen(path);
	len2 = ft_strlen(folder);
	i = 0;
	if(!(s = (char *)malloc(sizeof(char) * len + len2 + 2)))
		perror("malloc esteb : ");
	while (i < len)
		s[i] = path[i], i++;
	s[i] = '/', i++;
	while (i < len + len2 + 1)
		s[i] = folder[i - len -1], i++;
	s[i] = '\0';
	return (s);
}
