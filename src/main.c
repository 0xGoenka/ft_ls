/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:35:55 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/27 20:53:16 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int	xit(char *s , char *path)
{
	ft_putstr(s);
	ft_putendl(path);
	return (0);
}
int	recursive(char *s)
{
	DIR *stream;
	struct dirent *dir;
	struct stat stat;
	char *str;
	t_lst *lst;
	lst = init();
	
	stream = opendir(s);
	if(!(lst = getinfo(s)))
	{
		return (0);
	}
	printf("%s :\n", s);
	printlist(lst->next,findmax(lst->next, 1), findmax(lst->next, 0));
	lstdel(lst);
	
	if (!stream)
	{
		printf("error exit ---------------------\n") ;
		   	return (0);
	}
	while ((dir = readdir(stream)))
	{
		lstat(getpath(s, dir->d_name) , &stat);
		str = getperm(stat.st_mode);
		if (str[0] == 'd')
		{
			//printf ("dir = %s\n", dir->d_name);
		   if (ft_strcmp(dir->d_name, ".") != 0 && ft_strcmp(dir->d_name, "..") != 0)	
		   {	 
				printf("\n");
				recursive(getpath(s,dir->d_name));
		   }
		}
	/*	else
			printf(" %s ", dir->d_name);*/
		//closedir(stream);
	}
	return (0);
}
int		main(int argc, char **argv)
{
	recursive(argv[1]);
	return (0);
}
/*int	main(int argc, char **argv)
{
	DIR *stream;
	struct dirent *s_dir;
	struct stat s_stat;
	char *path = argv[1];
	char *s;

	if (!argv[1])
		path = ft_strdup(".");
	stream = opendir(argv[1]);
	
	if (!stream)
		return (xit("Can t open : " , path));
	while ((s_dir = readdir(stream)))
	{
		if (lstat(getpath(path, s_dir->d_name), &s_stat) == -1)
			perror("lstat");
		s = getperm(s_stat.st_mode);
		if (s[0] == 'd')
			printf("main -> %s char s[0] = %c\n", s_dir->d_name, s[0]),recursive(s_dir->d_name);
		printf("path : %s\n", getpath(argv[1], s_dir->d_name));

	}
	closedir(stream);
	return (0);
}*/
