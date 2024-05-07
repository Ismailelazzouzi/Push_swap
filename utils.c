#include "push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2) + 2;
	res = (char *)malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, ft_strlen(s1) + 2);
	ft_strlcpy(res + ft_strlen(s1), s2, ft_strlen(s2) + 2);
	free((char *)s1);
	return (res);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *)malloc(ft_strlen(s1) + 2);
	if (!dst)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = ' ';
	dst[++i] = '\0';
	return (dst);
}

int	ft_strlcpy(char *dst, const char *src, int dstsize)
{
	char	*s;
	int		i;

	s = (char *)src;
	i = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	while (s[i] && dstsize - 1)
	{
		dst[i] = s[i];
		i++;
		dstsize--;
	}
	dst[i] = ' ';
	dst[++i] = '\0';
	return (ft_strlen(src));
}

int	ft_atoi(const char *str, char **numbers)
{
	unsigned long long	result;
	int					i;
	int					sign;
	int					ret;

	sign = 1;
	i = 0;
	result = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = result * 10 + str[i++] - 48;
	if ((result > 2147483648 && sign == -1) || (result > INT_MAX && sign == 1))
		free_numbers(numbers, 1);
	return (ret = result, ret * sign);
}
