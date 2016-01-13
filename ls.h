/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:25:44 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/13 14:47:23 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pwd.h>
#include "libft/libft.h"
#include <grp.h>

typedef struct		s_file
{
	char			*name;
	char			*perm;
	int				nblink;
	char			*owner;
	char			*group;
	long long int	size;
	char			*modif;
	struct s_file 	*next;
	struct s_file 	*prev;
}					t_file;

typedef struct s_lst
{
	int i;
	char *s;
	t_file info;
	struct s_lst *next;
}				t_lst;
t_lst	*add(t_lst *liste, char *s, int index, t_file info);
t_lst	*printlist(t_lst *lst);
t_lst		*getinfo(char *s);
char	*get_time(struct stat *s_stat);
char	*dec_to_bin(int n);
char	*parse_right(char *s);
char	*ufid(uid_t uid);
char	*gfid(gid_t gid);
char		*getpath(char *path, char *folder);
char		*getperm(mode_t mode);
#endif
