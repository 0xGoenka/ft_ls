/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 03:34:46 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/24 17:39:34 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"


int		argvparser(char **argv, char **param, t_lst *lst, t_lst *error)
{
	int i;
	int ret;

	i = 1;

	while (argv[i]) // parse parameter
	{
		if (argv[i][0] == '-' && ft_strlen(argv[1]) == 1)
			break ;
		if ((ret = parseargv(argv[i], param, &i)) == -1)
			return (1);
		if (ret == 0)
			break ;
			i++;
	}
	while (argv[i]) // parse file
	{
		getfileinfo(&lst, argv[i], &error);
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
			ft_putstr_fd(ft_strjoin("ls: illegal option -- ", s), 2);
			ft_putstr_fd("\nusage: ls [-Raltr] [file ...]\n", 2);
			return (-1);
		}
		s++;
	}
	return (1);
}

int controller(char **argv)
{
	char *param;
	t_lst *name; // argument file
	t_lst *error;
	char *help;

	name = NULL;
	help = ft_strjoin(param, "a");
	error = init();
	name = init();
	param = NULL;
	if (argvparser(argv, &param, name, error) == 1)
	{
		ft_strdel(&param);
		return (0);
	}
	error_disp(error);
	if (countlst(name))
		sortfunc(help, &name, 'd');
	else if (countlst(error) ==  0) {
		getfileinfo(&name, ".", &error);
	}
	if (!param)
		param = ft_strdup("0");
	if (!ft_strchr(param, 'R') && countlst(name))
		printdir(name->next, param ,countlst(name) + countlst(error));
	if (ft_strchr(param, 'R'))
		rec_control(name->next, param);

	lstdel(error);
	lstdel(name);
	return (0);
}
int		main(int argc, char **argv)
{
	controller(argv);
	return (0);
}
