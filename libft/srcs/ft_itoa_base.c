#include "../includes/libft.h"

static char	*ft_strduprev(char *s1)
{
	char	*dup;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	dup = (char *)ft_memalloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		dup[i] = s1[len];
		len--;
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_itoa_base(unsigned long long n, int base)
{
	int		i;
	char	arr[64];
	char	*hexa;

	i = 0;
	hexa = "0123456789ABCDEF";
	if (n == 0)
		return (ft_strdup("0"));
	while (n > 0)
	{
		arr[i] = hexa[n % base];
		i++;
		n = n / base;
	}
	arr[i] = '\0';
	return (ft_strduprev(arr));
}