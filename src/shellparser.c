/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 03:34:46 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/08 05:37:50 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"


int		argvparser(char **argv, char **param, t_name *lst)
{
	int i;
	char *s;
	i = 0;

	while (argv[i++]) // parse parameter
	{
		if (parseargv(argv[i], param, &i) == - 1)
			return (1);
		if (parseargv(argv[i], param, &i) == 0)
			break ;
	}
	while (argv[i]) // parse file
	{
		addfile(lst, argv[i]);
		i++;
	}
	return (0);
}
int		parseargv(char *s, char **param, int *i)
{

	if (s[0] != '-')
		return (0);
	if (ft_strcmp(s, "--") == 0)
	{
		*i = *i + 1;
		return (0);
	}
	s++;
	*param = ft_strjoin(*param,s);
	while (*s)
	{
		if (*s != 'R' && *s != 'r' && *s != 'l' && *s != 'a' && *s != 't')
		{
			ft_putstr(ft_strjoin("ls: illegal option -- ", s));
			ft_putstr("\nusage: ls [-Raltr] [file ...]\n");
			return (-1);
		}
		s++;
	}
	return (1);
}

int		validfile(char *s)
{
	struct stat s_stat;

	if ((lstat(s, &s_stat) >= 0))
	{
		return (1);
	}
	ft_putstr("ls: ");
	ft_putstr(s);
	ft_putstr(": No such file or directory\n");
	return (0);
}
int controller(char **argv)
{
	char *param;
	t_name *name;

	name = initfile();
	param = NULL;
	if (argvparser(argv, &param, name) == 1)
	{
		ft_strdel(&param);
		return (0);
	}
	ft_putendl(param);
	ft_putstr("file -> \n");
	printname(name->next);

	return (0);
}
int		main(int argc, char **argv)
{
	controller(argv);
	return (0);
}
