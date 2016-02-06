/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 03:34:46 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/06 04:58:25 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"


int		argvparser(char **argv)
{
	int i;
	char *param;

	param = NULL;
	i = 1;

	while (argv[i]) // parse parameter
	{
		if (argv[i][0] == '-' && argv[i][1] == '-' && ft_strlen(argv[1]) == 2)
		{
			i++;
			break ;
		}
		if (argv[i][0] != '-')
		{
			i++;
			break ;
		}
		if(!parseargv(argv[i], &param))
		{
			i++;
			break ;
		}
		i++;
	}
	i--;
	while (argv[i]) // parse file
	{
		if (validfile(argv[i]))
			printf("valid %s\n", argv[i]);
		i++;
	}
	ft_putendl(param);
	return (0);
}
int		parseargv(char *s, char **param)
{

	s++;
	*param = ft_strjoin(*param,s);
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
	ft_putendl(ft_strjoin("-", *param));
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
int		main(int argc, char **argv)
{
	argvparser(argv);
	return (0);
}
