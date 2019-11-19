/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:41:38 by yait-kad          #+#    #+#             */
/*   Updated: 2019/11/19 19:04:30 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		remplir(char **line, char **str)
{
	char			*temp;
	int				i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	if (i != 0 || (*str)[i] == '\n')
	{
		*line = ft_substr(*str, 0, i);
		if ((*str)[i] != '\0')
		{
			temp = ft_strdup(*str + i + 1);
			free(*str);
		}
		else if ((*str)[i] == '\0')
		{
			temp = ft_strdup(*str + i);
			free(*str);
		}
		*str = temp;
		return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			*buff;
	static char		*str;
	char			*ptr;

	if (fd < 0 || line == NULL || fd > 4864 || BUFFER_SIZE < 0)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (!str)
		if (!(str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[ret] = '\0';
		ptr = ft_strjoin(str, buff);
		free(str);
		str = ptr;
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	free(buff);
	return (remplir(line, &str));
}
