/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 15:51:29 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/04 18:44:53 by eleclet          ###   ########.fr       */
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
int		findmax(t_lst *lst, int i)
{
	int ret;

	ret = 0;
	if (i)
	{
		while (lst)
		{
			if (ret < nu_len(lst->info.nblink, 10))
				ret = nu_len(lst->info.nblink, 10);
			lst = lst->next;
		}
	}
	else
	{
		while (lst)
		{
			if (ret < nu_len(lst->info.size,10))
				ret = nu_len(lst->info.size,10);
			lst = lst->next;
		}
	}
	return (ret);
}

int		findmaxe(t_lst *lst, int i)
{
	int ret;

	ret = 0;
	if (i)
	{
		while (lst)
		{
			if (ret < ft_strlen(lst->info.owner))
					ret = ft_strlen(lst->info.owner);
			lst = lst->next;
		}
	}
	else
	{
		while (lst)
		{
			if (ret < ft_strlen(lst->info.group))
				ret = ft_strlen(lst->info.group);
			lst = lst->next;
		}
	}
	return (ret);
}
