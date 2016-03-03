/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somefunction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:20:05 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/03 17:14:48 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

char	*getpath(char *path, char *folder)
{
	if (path)
	{
		return (ft_strjoin(ft_strjoin(path, "/"), folder));
	}
	else
		return (folder);
}

char	*getperm(mode_t mode)
{
	char *str;

	str = ft_strnew(11);
	str[0] = ((mode & S_IFMT) == S_IFLNK) ? 'l' : str[0];
	str[0] = ((mode & S_IFMT) == S_IFREG) ? '-' : str[0];
	str[0] = ((mode & S_IFMT) == S_IFDIR) ? 'd' : str[0];
	str[0] = ((mode & S_IFMT) == S_IFBLK) ? 'b' : str[0];
	str[0] = ((mode & S_IFMT) == S_IFSOCK) ? 's' : str[0];
	str[0] = ((mode & S_IFMT) == S_IFIFO) ? 'p' : str[0];
	str[0] = ((mode & S_IFMT) == S_IFCHR) ? 'c' : str[0];
	str[7] = (mode & S_IROTH) ? 'r' : '-';
	str[8] = (mode & S_IWOTH) ? 'w' : '-';
	str[9] = (mode & S_IXOTH) ? 'x' : '-';
	str[4] = (mode & S_IRGRP) ? 'r' : '-';
	str[5] = (mode & S_IWGRP) ? 'w' : '-';
	str[6] = (mode & S_IXGRP) ? 'x' : '-';
	str[1] = (mode & S_IRUSR) ? 'r' : '-';
	str[2] = (mode & S_IWUSR) ? 'w' : '-';
	str[3] = (mode & S_IXUSR) ? 'x' : '-';
	str[3] = (mode & S_ISUID) ? (mode & 0100 ? 's' : 'S') : str[3];
	str[6] = (mode & S_ISGID) ? (mode & 0100 ? 's' : 'S') : str[6];
	str[9] = (mode & S_ISVTX) ? (mode & 0100 ? 't' : 'T') : str[9];
	str[10] = ' ';
	return (str);
}

void	getfileinfo(t_lst **liste, char *file, t_lst **error, char *param)
{
	t_file		info;
	struct stat statd;

	info.name = file;
	if (ft_strchr(param, 'l'))
	{
		if (lstat(file, &statd) == -1)
		{
			add(*error, info);
			return ;
		}
	}
	else
	{
		if (stat(file, &statd) == -1)
		{
			add(*error, info);
			return ;
		}
	}
	info = fillinfo(statd, file);
	add(*liste, info);
}

t_lst	*getinfo(char *s)
{
	DIR				*stream;
	struct dirent	*dir;
	struct stat		statt;
	t_file			info;
	t_lst			*liste;

	liste = init();
	if (!(stream = opendir(s)))
		return (0);
	while ((dir = readdir(stream)))
	{
		if (lstat(getpath(s, dir->d_name), &statt) == -1)
			return (0);
		else
		{
			info = fillinfo(statt, dir->d_name);
			add(liste, info);
		}
	}
	closedir(stream);
	return (liste);
}

t_file	fillinfo(struct stat stat, char *name)
{
	t_file info;

	info.name = ft_strdup(name);
	info.perm = getperm(stat.st_mode);
	info.nblink = stat.st_nlink;
	info.owner = ufid(stat.st_uid);
	info.group = gfid(stat.st_gid);
	if (info.perm[0] == 'c' || info.perm[0] == 'b')
	{
		info.size = pad(3, major(stat.st_rdev), minor(stat.st_rdev));
	}
	else
		info.size = ft_itoa(stat.st_size);
	info.time = get_time(&stat);
	info.modif = stat.st_mtime;
	info.block = stat.st_blocks;
	return (info);
}
