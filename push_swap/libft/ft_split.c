/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyobicho <hyobicho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:53:02 by hyobicho          #+#    #+#             */
/*   Updated: 2023/02/02 13:53:22 by hyobicho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strlen1(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**free_res(char **res, int i)
{
	while (i-- > 0)
		free(res[i]);
	free(res);
	return (0);
}

static char	**result(char **res, char const *str, char c, int cnt)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < cnt)
	{
		len = ft_strlen1(str, c);
		res[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (res[i] == NULL)
			return (free_res(res, i));
		j = 0;
		while (j < len && str[j])
		{
			res[i][j] = str[j];
			j++;
		}
		res[i][j] = '\0';
		while (str[j] == c && str[j])
			j++;
		str += j;
		i++;
	}
	res[i] = 0;
	return (res);
}

static unsigned int	cntstr(char const *s, char c)
{
	int	cnt;
	int	i;
	int	flag;

	cnt = 0;
	i = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] != c && flag)
		{
			cnt++;
			flag = 0;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char			**res;
	unsigned int	cnt;

	while (*s == c && c != '\0')
		s++;
	if (*s == '\0')
		ft_error();
	cnt = cntstr(s, c);
	res = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (res == 0)
		return (0);
	return (result(res, s, c, cnt));
}
