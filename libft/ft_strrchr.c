#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char		*str;

	str = s;
	str = str + ft_strlen(s);
	while (*str != (char)c && str != s)
		str--;
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}
