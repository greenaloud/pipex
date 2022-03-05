#include <stdlib.h>

static int	get_arg_len(char *str)
{
	int		len;

	len = 1;
	if (*str == ' ')
		return (0);
	else if (*str == '\'')
		while (str[len] != '\'')
			len++;
	else if (*str == '\"')
		while (str[len] != '\"')
			len++;
	while (str[len] && str[len] != ' ')
		len++;
	return (len);
}

static int  get_arg_count(char *arg)
{
	int idx;
	int cnt;

	idx = 0;
	cnt = 0;
	while (s[idx])
    {
        while (s[idx] == ' ')
            idx++;
        if (s[idx])
        {
			idx += get_arg_len(s[idx]);
            cnt++;
        }
    }
	return (cnt);
}

static char	*fill_arg(char *arg, int lt, int rt)
{
	int 	idx;
	char	*str;

	if (arg[lt] == '\'' || arg[lt] == '\"')
	{
		lt++;
		rt--;
	}
	str = malloc(sizeof(*str) * (rt - lt + 1));
	if (str == NULL)
		return (NULL);
	idx = 0;
	while (lt < rt)
		str[idx++] = arg[lt++];
	str[idx] = '\0';
	return (str);
}

static int split(char **lst, char *arg)
{
	int lt;
	int rt;

	lt = 0;
	rt = 0;
	while (arg[rt])
	{
		rt += get_arg_len(arg[rt]);
		if (lt != rt)
		{
			*lst = fill_arg(arg, lt, rt);
			if (*lst++ == NULL)
				return (0);
		}
		while (arg[rt] == ' ')
			rt++;
		lt = rt;
	}
	*lst = NULL;
	return (1);
}

char    **split_arg(char *arg)
{
	int 	idx;
    int     cnt;
	int 	flag;
    char    **result;

    cnt = get_arg_count(arg);
	result = malloc(sizeof (*result) * (cnt + 1));
	if (result == NULL)
		return (NULL);
	flag = split(result, arg);
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