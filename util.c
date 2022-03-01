/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wocho <wocho@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:47:01 by wocho             #+#    #+#             */
/*   Updated: 2022/03/01 18:26:16 by wocho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// used
size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;

	idx = 0;
	while (src[idx] && dstsize && idx < dstsize - 1)
	{
		dst[idx] = src[idx];
		idx++;
	}
	if (dstsize)
		dst[idx] = 0;
	while (src[idx])
		idx++;
	return (idx);
}

// used
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	di;
	size_t	si;
	size_t	len;

	di = ft_strlen(dst);
	if (di >= dstsize)
		return (dstsize + ft_strlen(src));
	len = di;
	si = 0;
	while (dstsize && di < dstsize - 1)
	{
		if (src[si])
			dst[di] = src[si];
		else
			break ;
		di++;
		si++;
	}
	dst[di] = 0;
	while (src[si])
		si++;
	len += si;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int		idx;
	char	target;

	idx = 0;
	target = c;
	if (target == 0)
	{
		while (s[idx])
			idx++;
		return ((char *)(s + idx));
	}
	while (s[idx])
	{
		if (s[idx] == target)
			return ((char *)(s + idx));
		idx++;
	}
	return (0);
}

// used
char	*ft_strrchr(const char *s, int c)
{
	int		idx;
	char	comp;

	comp = (char) c;
	idx = 0;
	while (s[idx])
		idx++;
	while (idx >= 0)
	{
		if (s[idx] == comp)
			return ((char *)(s + idx));
		idx--;
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		idx;
	int		size;
	char	*copy;

	size = 0;
	while (s1[size])
		size++;
	copy = malloc(sizeof (*copy) * (size + 1));
	if (copy == NULL)
		return (NULL);
	idx = 0;
	while (idx < size)
	{
		copy[idx] = s1[idx];
		idx++;
	}
	copy[idx] = 0;
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*result;

	len = ft_strlen(s1);
	len += ft_strlen(s2);
	result = malloc(sizeof (*result) * (len + 1));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, len + 1);
	ft_strlcat(result, s2, len + 1);
	return (result);
}

static int	get_count(char const *s, char c)
{
	int	idx;
	int	cnt;

	idx = 0;
	cnt = 0;
	while (s[idx])
	{
		while (s[idx] == c)
			idx++;
		if (s[idx])
			cnt++;
		while (s[idx] != 0 && s[idx] != c)
			idx++;
	}
	return (cnt);
}

static char	*process(char const *s, int *lt, int rt)
{
	int		idx;
	char	*str;

	str = malloc(sizeof (*str) * (rt - *lt + 1));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (*lt < rt)
	{
		str[idx] = s[*lt];
		(*lt)++;
		idx++;
	}
	str[idx] = 0;
	return (str);
}

static int	divide(char **arr, char const *s, char c)
{
	int	lt;
	int	rt;
	int	idx;

	lt = 0;
	rt = 0;
	idx = 0;
	while (s[rt])
	{
		while (s[rt] != c && s[rt] != '\0')
			rt++;
		if (lt != rt)
		{
			arr[idx] = process(s, &lt, rt);
			if (arr[idx++] == NULL)
				return (0);
		}
		while (s[rt] == c && s[rt] != '\0')
		{
			lt++;
			rt++;
		}
	}
	arr[idx] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		idx;
	int		cnt;
	int		flag;
	char	**result;

	cnt = get_count(s, c);
	result = malloc(sizeof (*result) * (cnt + 1));
	if (result == NULL)
		return (NULL);
	flag = divide(result, s, c);
	if (!flag)
	{
		idx = 0;
		while (result[idx])
			free(result[idx++]);
		free(result);
		return (NULL);
	}
	return (result);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				idx;
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	idx = 0;
	while (idx < n)
	{
		if (ptr1[idx] - ptr2[idx])
			return (ptr1[idx] - ptr2[idx]);
		idx++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (n_len == 0)
		return ((char *)haystack);
	idx = 0;
	while (haystack[idx] != '\0' && idx + n_len <= len)
	{
		if (ft_memcmp(haystack + idx, needle, n_len) == 0)
			return ((char *)(haystack + idx));
		idx++;
	}
	return (NULL);
}
