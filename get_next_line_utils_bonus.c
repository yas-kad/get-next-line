/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:07:33 by yait-kad          #+#    #+#             */
/*   Updated: 2019/11/17 20:25:49 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t		ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(const char *src)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	i;
	size_t			j;

	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (j < start)
		return (ft_strdup("\0"));
	if (len >= j)
		if (!(dest = (char *)malloc(sizeof(char) * ((j - start) + 1))))
			return (NULL);
	if (len < j)
		if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
			return (NULL);
	i = start;
	j = 0;
	while (s[i] != '\0' && j < len)
	{
		dest[j] = s[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	s = NULL;
	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
						ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[j] != '\0')
	{
		s[i++] = s1[j++];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		s[i] = s2[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return (s);
}

char		*ft_strchr(char *c1, int c2)
{
	int		index;
	size_t	len;

	index = 0;
	len = ft_strlen(c1);
	if ((char)c2 == '\0')
		return ((char *)c1 + len);
	while (c1[index] != '\0')
	{
		if (c2 == c1[index])
			return ((char *)c1 + index);
		index++;
	}
	return (NULL);
}
