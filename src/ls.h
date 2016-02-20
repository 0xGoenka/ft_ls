/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:25:44 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/20 17:42:32 by eleclet          ###   ########.fr       */
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
	char			*time;
	struct s_file 	*next;
	int				modif;
	int				block;
}					t_file;

typedef struct		s_lst
{
	t_file 			info;
	struct s_lst 	*next;
}					t_lst;
typedef struct 		s_argv
{
	int 			recursive;
	int				a;
	int				l;
	int				t;
	int				r;
	char 			*file;
}					t_argv;
typedef struct		s_maxlen
{
	int				a;
	int				b;
	int				c;
	int				d;
}					t_maxlen;
typedef struct		s_name
{
	char			*name;
	struct s_name	*next;
}					t_name;

void				add(t_lst *liste, t_file info);
void				printlist(t_lst *lst, t_maxlen i, int a, int skip);
t_lst				*getinfo(char *s);
char				*get_time(struct stat *s_stat);
char				*dec_to_bin(int n);
char				*parse_right(char *s);
char				*ufid(uid_t uid);
char				*gfid(gid_t gid);
char				*getpath(char *path, char *folder);
char				*getperm(mode_t mode);
int					findmax(t_lst *lst,int i);
void				space(int i, int max, int pad);
void				lstdel(t_lst *lst);
t_lst				*init(void);
void				print(t_lst *lst, int skip, int a);
int					good(char **argv);
int					parseargv(char *s, char **param, int *i);
int					validfile(char *s);
char				*getargv(int argc, char **argv);
int					findmaxe(t_lst *lst, int i);
void				ct_all(t_lst *lst, t_maxlen **i);
void 				sortliste(t_lst **lst, int rev);
int					parsefile(char *s, char **file);
t_name				*initfile(void);
void				addfile(t_name *lst, char *name);
void				printname(t_name *file);
void				sortname(t_name **lst, int rev);
void				sortit(t_name **name, char *param);
void 				sortbytime(t_lst **lst, int rev);
void 				getfileinfo(t_lst	**liste, char *file, t_lst **error);
void 				sortfunc(char *param, t_lst **lst, int skip);
void 				error_disp(t_lst *error);
void 				printlext(t_lst *lst, t_maxlen i);
void 				printdir(t_lst *lst , char *param, int nblst);
int					countlst(t_lst *lst);
void 				total(t_lst *lst);
int 				permDenied(char *s);
#endif
