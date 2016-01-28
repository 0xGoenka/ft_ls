/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   somefunction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/10 15:20:05 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/28 14:02:19 by eleclet          ###   ########.fr       */
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
	if (s[i - 1] != '/')
		s[i] = '/', i++;
	//printf("path[i] = %s foleder = %s\n",path, folder);
	while (i < len + len2 + 1)
		s[i] = folder[i - len -1], i++;
	s[i] = '\0';
	//printf("path = %s\n",s);
	return (s);
}

char	*getperm(mode_t mode)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 11);
	str[0] = ((mode & S_IFMT) == S_IFLNK) ? 'l': str[0];
	str[0] = ((mode & S_IFMT) == S_IFREG) ? '-': str[0];
	str[0] = ((mode & S_IFMT) == S_IFDIR) ? 'd': str[0];
	str[0] = ((mode & S_IFMT) == S_IFBLK) ? 'b': str[0];
	str[0] = ((mode & S_IFMT) == S_IFSOCK)? 's': str[0];
	str[0] = ((mode & S_IFMT) == S_IFIFO)? 'p':  str[0];
	str[0] = ((mode & S_IFMT) == S_IFCHR)? 'c':  str[0];
	str[7] = (mode &S_IROTH) ? 'r' : '-';
	str[8] = (mode &S_IWOTH) ? 'w' : '-';
	str[9] = (mode &S_IXOTH) ? 'x' : '-';
	str[4] = (mode &S_IRGRP) ? 'r' : '-';
	str[5] = (mode &S_IWGRP) ? 'w' : '-';
	str[6] = (mode &S_IXGRP) ? 'x' : '-';
	str[1] = (mode &S_IRUSR) ? 'r' : '-';
	str[2] = (mode &S_IWUSR) ? 'w' : '-';
	str[3] = (mode &S_IXUSR) ? 'x' : '-';
	str[10] = '\0';
	return (str);
}
t_lst	*getinfo(char *s)
{
	DIR *stream;
	struct dirent *dir;
	struct stat stat;
	t_file	*info;
	t_lst *liste;

	//dir = malloc(sizeof(struct dirent));
	liste = init();
	info = malloc(sizeof(t_file));
	if(!(stream = opendir(s)))
	{
		perror("opendir");
		printf("ft_ls : %s: No such file or directory\n", s);
			return (0);
	}
		while((dir = readdir(stream)) != NULL)
		{
			//perror("readdir");
			if (lstat(getpath(s, dir->d_name), &stat) == -1)
				perror("lstat error : ");
			info->name = dir->d_name;
			info->perm = getperm(stat.st_mode);
			info->nblink = stat.st_nlink;
			info->owner = ufid(stat.st_uid);
			info->group = gfid(stat.st_gid);
			info->size = stat.st_size;
			info->time = get_time(&stat);
			add(liste, 3, *info);
		}
		free(info);
		free(dir);
		dir = NULL;
		closedir(stream);
	return (liste);
}
