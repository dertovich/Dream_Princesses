#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	unsigned int	i;
	unsigned char	*c;

	i = 0;
	c = (unsigned char *)pointer;
	while (i < count)
		c[i++] = (unsigned char)value;
	pointer = (void *)c;
	return (pointer);
}
