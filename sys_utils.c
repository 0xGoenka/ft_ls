/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 15:51:29 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/13 15:44:36 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*get_time(struct stat *s_stat)
{
	char *s;

	s = ft_strdup(ctime(&s_stat->st_mtime));
	s = ft_strsub(s, 4, ft_strlen(s) - 13);
	return (s);
}
char	*ufid(uid_t uid) // user from id
{
	struct passwd *user;

	user = getpwuid(uid);
	return (user->pw_name);
}
 char	*gfid(gid_t gid) // group from	id
{
	struct group *g;
	g = getgrgid(gid);
	return (g->gr_name);
}
char	*parse_right(char *s)
{
	char *ret;

	int i;

	i = 0;
	printf("s = %s\n",s);
	while (i < 15)
	{
		s[i] = (s[i] == '1')? 'x' : '-',i++;
		s[i] = (s[i] == '1')? 'w' : '-',i++;
		s[i] = (s[i] == '1')? 'r' : '-',i++;
	}
	s = ft_strrvrs(s);
	printf("\n s rvrs = %s", s);
	ret = s;
	printf("\n ret sub = %s\n", ret);
	s[5] = (s[0] == '1')? '-' : 'd';
	ret = ft_strdup(s + 5);
	return (ret);
}
char	*dec_to_bin(int n)
{
	char *s;
	int i;

	i = 0;
	s = (char *)malloc(sizeof(char) * 16 + 1);
	//printf("n = %d\n", n);
	while (n)
	{
		if (n & 1)
			s[i] = '1';
		else
			s[i] = '0';
		i++, n >>= 1;
	}
	s[i] = '\0';
	return (s);
}
