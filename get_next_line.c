/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:41:38 by yait-kad          #+#    #+#             */
/*   Updated: 2019/11/16 18:03:27 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int		get_next_line(int fd, char **line)
{
	int				ret;
	char			*buff;
	static 	char	*str;
	char			*ptr;
	char			*temp;
	int				i;

	if (fd < 0 || line == NULL || fd > 4864)
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
	free(buff);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (i != 0 || str[i] == '\n')
	{
		*line = ft_substr(str, 0, i);
		temp = ft_strdup(str + i + 1);
		free(str);
		str = temp;
		return (1);
	}
	else
		*line = ft_strdup("");
	return (0);
}
