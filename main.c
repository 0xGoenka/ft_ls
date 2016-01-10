/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:35:55 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/10 20:45:12 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int	xit(char *s , char *path)
{
	ft_putstr(s);
	ft_putendl(path);
	return (0);
}

int	main(int argc, char **argv)
{
	DIR *stream;
	struct dirent *s_dir;
	struct stat s_stat;
	char *path = argv[1];

	if (!argv[1])
		path = ft_strdup(".");
	stream = opendir(argv[1]);
	
	if (!stream)
		return (xit("Can t open : " , path));
	while ((s_dir = readdir(stream)))
	{
		if (lstat(getpath(path, s_dir->d_name), &s_stat) == -1)
			perror("lstat");
		printf("size:%lld   " , s_stat.st_size);
		printf("mode: %s   " ,parse_right((char *)dec_to_bin(s_stat.st_mode)));
		printf("user:%s   ", ufid(s_stat.st_uid));
		printf("%s   " , get_time(&s_stat));
		printf("%s\n", s_dir->d_name);
		//printf("path : %s\n", getpath(argv[1], s_dir->d_name));
	}
	closedir(stream);
	return (0);
}
