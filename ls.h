/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:25:44 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/09 23:16:32 by eleclet          ###   ########.fr       */
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

typedef struct	s_file
{
	char	*name;
	char	*right;
	char	*link;
	char	*owner;
	char	*group;
	char	*size;
	char	*modif;
	struct s_file *next;
	struct s_file *prev;
}				t_file;
const char	*get_time(struct stat *s_stat);
const char	*dec_to_bin(int n);
const char *parse_right(int n);
const char	*ufid(uid_t uid);
const char	*gfid(gid_t gid);

#endif
