#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	**start;

	start = lst;
	while (*lst != NULL)
	{
		ft_lstdelone(*lst, del);
		*lst = (*lst)->next;
	}
	*start = NULL;
}
