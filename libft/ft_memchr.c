#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	b;
	int				i;

	i = 0;
	str = (unsigned char *)s;
	b = (unsigned char)c;
	while (n--)
	{
		if (str[i] == b)
			return (str + i);
		i++;
	}
	return (NULL);
}
