/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getparam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:52:08 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/05 04:39:35 by eleclet          ###   ########.fr       */
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

	i = 0;
	j = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' && argv[i][1] == '-' && ft_strlen(argv[i]) == 2)
			i++;
		else if (argv[i][0] == '-' && ft_strlen(argv[i]) != 1)
		{
			if (!parseargv(argv[i]))
				return (0);
		}
		else if (!validfile(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int		parseargv(char *s)
{
	char *argv;

	s++;
	argv = s;
	while (*s)
	{
		if (*s != 'R' && *s != 'r' && *s != 'l' && *s != 'a' && *s != 't')
		{
			ft_putstr(ft_strjoin("ls: illegal option -- ", s));
			ft_putstr("\nusage: ls [-Raltr] [file ...]\n");
			return (0);
		}
		s++;
	}
	ft_putendl(ft_strjoin("-", argv));
	return (1);
}

int		validfile(char *s)
{
	struct stat s_stat;

	if ((lstat(s, &s_stat) >= 0))
	{
		ft_putstr(ft_strjoin(s, " valid file! \n"));
		return (1);
	}
	ft_putstr("ls: ");
	ft_putstr(s);
	ft_putstr(": No such file or directory\n");
	return (0);
}

char	*getargv(int argc, char **argv)
{
	if (argc == 1)
		return (".");
	return (argv[1]);
}
