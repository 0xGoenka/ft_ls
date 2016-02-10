/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 14:35:55 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/10 18:11:49 by eleclet          ###   ########.fr       */
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
	t_lst *lst;
	t_maxlen *i;
	int a;

	a = 1;

	lst = init();
	i = malloc(sizeof(t_maxlen));

	stream = opendir(s);
	//perror("open main");
	if(!(lst = getinfo(s)))
		return (0);
	printf("%s :\n", s);
	ct_all(lst->next, &i);
	sortliste(&lst, -1);
	printlist(lst->next, *i, a);
	lstdel(lst);

	if (!stream)
	{
		printf("error exit ---------------------\n") ;
		   	return (0);
	}
	while ((dir = readdir(stream)))
	{
		if (dir->d_type == DT_DIR)
		{
		   if (ft_strcmp(dir->d_name, ".") != 0 && ft_strcmp(dir->d_name, "..") != 0)
		   {
				printf("\n");
				recursive(getpath(s,dir->d_name));
		   }
		}
	}
		closedir(stream);
	return (0);
}
int		main(int argc, char **argv)
{
	recursive(argv[1]);
	return (0);
}
