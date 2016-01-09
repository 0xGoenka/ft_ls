/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:35:55 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/09 23:16:27 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

static int	xit(char *s)
{
	ft_putstr(s);
	return (0);
}

int	main()
{
	DIR *stream;
	struct dirent *s_dir;
	struct stat *s_stat;
	char *s;

	s_stat = malloc(sizeof(stat));

	stream = opendir(".");
	
	if (!stream)
		return (xit("Can t open libft"));
	while ((s_dir = readdir(stream)))
	{
		lstat(s_dir->d_name, s_stat);
		printf("size:%lld   " , s_stat->st_size);
		printf("mode: %x   " , s_stat->st_mode);
		printf("user:%s   ", ufid(s_stat->st_uid));
		printf("%s   " , get_time(stat));
		printf("%s\n", s_dir->d_name);
	}
	free (s_stat);
	closedir(stream);
	return (0);
}
