#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	**alst;

	(void)del;
	if (lst == NULL)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	alst = &result;
	lst = lst->next;
	while (lst != NULL)
	{
		ft_lstadd_back(alst, ft_lstnew(f(lst->content)));
		lst = lst->next;
	}
	return (result);
}
