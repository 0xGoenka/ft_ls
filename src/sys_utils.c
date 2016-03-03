/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 15:51:29 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/03 17:14:51 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*get_time(struct stat *s_stat)
{
	return (ft_strsub(ctime(&s_stat->st_mtime), 4, 12));
}

char	*ufid(uid_t uid)
{
	struct passwd *user;

	user = getpwuid(uid);
	if (user)
		return (ft_strdup(user->pw_name));
	else
		return (ft_itoa(uid));
}

char	*gfid(gid_t gid)
{
	struct group *g;

	g = getgrgid(gid);
	if (g)
		return (ft_strdup(g->gr_name));
	else
		return (ft_strdup("wheel"));
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
			if (ret < (int)ft_strlen(lst->info.size))
				ret = ft_strlen(lst->info.size);
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
			if (ret < (int)ft_strlen(lst->info.owner))
				ret = ft_strlen(lst->info.owner);
			lst = lst->next;
		}
	}
	else
	{
		while (lst)
		{
			if (ret < (int)ft_strlen(lst->info.group))
				ret = ft_strlen(lst->info.group);
			lst = lst->next;
		}
	}
	return (ret);
}
