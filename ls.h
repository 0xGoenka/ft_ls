/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 15:25:44 by eleclet           #+#    #+#             */
/*   Updated: 2016/01/07 15:30:30 by eleclet          ###   ########.fr       */
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
#include <stdlib.>

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
}

#endif
