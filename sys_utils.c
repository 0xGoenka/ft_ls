/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 15:51:29 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/09 23:16:29 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

const char	*get_time(struct stat *s_stat)
{
	char *s;

	s = ft_strdup(ctime(s_stat->mtime));
	s = ft_strsub(s, 4, ft_strlen(s) - 13);
	return (s);
}
const char	*ufid(uid_t uid) // user from id
{
	struct passwd *user;

	user = getpwuid(uid);
	return (user->pw_name);
}
const char	*gfid(gid_t gid) // group from	id
{
	struct group *g;
	g = getgrgid(gid);
	return (g->gr_name);
}
const char	*parse_right(int n)
{
	n  = 0;
	return ("");	
}
const char	*dec_to_bin(int n)
{
	char *s;
	int i;

	i = 0;
	s = (char *)malloc(sizeof(char) * nu_len(n, 2) + 1);
	s[nu_len(n, 2)] = '\0';
	while (n)
	{
		if (n & 1)
			s[i] = '1';
		else
			s[i] = '0';
		i++, n >>= 1;
	}
	return (s);
}
