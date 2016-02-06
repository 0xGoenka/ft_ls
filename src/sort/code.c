#include "../ls.h"

t_liste	*initlst(void)
{
	t_liste *lst;
	lst = malloc(sizeof(t_liste));
	lst->s = "Yo";
	lst->next = NULL;
	return (lst);
}
void addlst(t_liste *lst, char *s)
{
	while (lst->next != NULL)
		lst = lst->next;
	if (!(lst->next = malloc(sizeof(t_liste))))
		return;
	lst = lst->next;
	lst->s = s;
	lst->next = NULL;
}

void printlst(t_liste *lst)
{
	if (!lst)
		return;
	printf("%s  ",lst->s);
	printlst(lst->next);
}
