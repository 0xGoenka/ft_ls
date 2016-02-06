/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleclet <eleclet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 20:58:42 by eleclet           #+#    #+#             */
/*   Updated: 2016/02/05 02:52:44 by eleclet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ls.h"
void printlst(t_liste *lst);
t_liste	*initlst(void);
void addlst(t_liste *lst, char *s);

void sortliste(t_liste **lst, int rev)
{
	t_liste *start;
	t_liste *ptr;
	int i;

	start = *lst;
	i = 1;
	while (i == 1)
	{
		i = 0;
		while ((*lst)->next->next)
		{
			if (ft_strcmp((*lst)->next->s,(*lst)->next->next->s) * rev > 0)
			{
				ptr = (*lst)->next;
				(*lst)->next = (*lst)->next->next;
				ptr->next = (*lst)->next->next;
				(*lst)->next->next = ptr;
				i = 1;
			}
			*lst = (*lst)->next;
		}
		*lst = start;
	}
}
int main()
{
	t_liste *lst;
	int i;

	i = 1;
	lst = initlst();

	addlst(lst, "n");
	addlst(lst, "a");
	addlst(lst, "l");
	addlst(lst, "k");
	addlst(lst, "j");
	addlst(lst, "i");
	addlst(lst, "f");
	addlst(lst, "e");
	addlst(lst, "d");
	addlst(lst, "c");
	addlst(lst, "b");
	addlst(lst, "a");


	printlst(lst->next);
	printf("\n");

	sortliste(&lst, -1);
	printlst(lst->next);
	printf("\n");

}
