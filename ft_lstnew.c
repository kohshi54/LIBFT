#include "libft.h"
#include <stdlib.h>

t_list *ft_lstnew(void *content)
{
	t_list *p;

	p = malloc(sizeof(t_list));
	p->content = content;
	p->next = NULL;
	return (p);
}