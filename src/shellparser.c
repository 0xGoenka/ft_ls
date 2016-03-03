/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellparser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 03:34:46 by eleclet           #+#    #+#             */
/*   Updated: 2016/03/03 17:12:30 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

int		argvparser(char **argv, char **param, t_lst *lst, t_lst *error)
{
	int i;
	int ret;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '-' && ft_strlen(argv[1]) == 1)
			break ;
		if ((ret = parseargv(argv[i], param, &i)) == -1)
			return (1);
		if (ret == 0)
			break ;
		i++;
	}
	while (argv[i])
	{
		getfileinfo(&lst, argv[i], &error, *param);
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
	*param = ft_strjoin(*param, s);
	while (*s)
	{
		if (*s != 'R' && *s != 'r' && *s != 'l' && *s != 'a' && *s != 't')
		{
			ft_putstr_fd("ft_ls: illegal option -- ", 2);
			ft_putchar_fd(*s, 2);
			ft_putstr_fd("\nusage: ./ft_ls [-Raltr] [file ...]\n", 2);
			return (-1);
		}
		s++;
	}
	return (1);
}

int		controller(char **argv)
{
	char	*param;
	t_lst	*name;
	t_lst	*error;

	error = init();
	name = init();
	param = NULL;
	if (argvparser(argv, &param, name, error) == 1)
		return (0);
	error_disp(error);
	if (countlst(name))
		sortfunc(ft_strjoin(param, "a"), &name, 'd', "");
	else if (countlst(error) == 0)
		getfileinfo(&name, ".", &error, param);
	param = (!param) ? ft_strdup("0") : param;
	if (!ft_strchr(param, 'R') && countlst(name))
		printdir(name->next, param, countlst(name) + countlst(error));
	if (ft_strchr(param, 'R'))
		rec_control(name->next, param);
	lstdel(error);
	lstdel(name);
	return (0);
}

int		main(int argc, char **argv)
{
	argc++;
	controller(argv);
	return (0);
}
