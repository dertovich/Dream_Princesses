#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*tab;

	count = 0;
	tab = 0;
	if (!s || !f)
		return (NULL);
	tab = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!tab)
		return (NULL);
	while (s[count])
	{
		tab[count] = (*f)(count, s[count]);
		count++;
	}
	tab[count] = '\0';
	return (tab);
}
