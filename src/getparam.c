/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getparam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:52:08 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/27 15:53:23 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		main(int argc, char **argv)
{
	if (!good(argv))
		return (0);
	getargv(argc, argv);
	printf("end of prog\n");
	return (0);
}
int		good(char **argv)
{
	int i;
	int j;
	int a;

	i = 1;
	j = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1] == '-' && ft_strlen(argv[i]) == 2)
			a = 5, i++;
		if (argv[i][0] == '-' && a != 5 && ft_strlen(argv[i]) != 1)
		{
			if (!parseargv(argv[i]))
				return (0);
		}
		else if (!validfile(argv[i]))
			return (0);
	ft_putstr(ft_strjoin(argv[i]," valid file! \n"));
		i++;
	}
	return (1);
}
int		parseargv(char *s)
{
	s++;
	while (*s)
	{
		if (*s != 'R' && *s != 'r' && *s != 'l' && *s != 'a' && *s != 't')
		{
			ft_putstr(ft_strjoin("ls: illegal option -- ",s));
			ft_putstr("\nusage: ls [-Raltr] [file ...]\n");
			return (0);
		}
		s++;
	}
	return (1);
}
int		validfile(char *s)
{
	struct stat s_stat;
	if((lstat(s, &s_stat) >= 0))
		return (1);
	ft_putstr("ls: ");
	ft_putstr(s);
	ft_putstr(": No such file or directory\n");	
	return (0);
}
char	*getargv(int argc,char **argv)
{
	if (argc == 1)
		return (".");
	return ("sdasd");
}
