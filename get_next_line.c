/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:41:38 by yait-kad          #+#    #+#             */
/*   Updated: 2019/11/15 21:13:53 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return 1;
}

int 	ft_putendl(char *str)
{
	int i = -1;

	while (str[++i])
		ft_putchar(str[i]);
	ft_putchar('\n');
	return 1;
}

int		get_next_line(int fd, char **line)
{
	int		ret;
	char	buff[BUFFER_SIZE + 1];
	static 	char	*str;
	char	*ptr;
	int		i;
	//ft_putchar('T');

	if (fd < 0 || line == NULL || fd > 4864)
		return (-1);
	if (!str && !(str =(char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);

	//ft_putchar('T');
	//printf("\nstr1%s\n",str);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		//printf("\nhadbau:%d\n",ret);
		//ft_putendl(buff);
		//if (ft_strchr(buff, '\n'));
		buff[ret] = '\0';
		//printf("\n1\n");
		ptr = ft_strjoin(str, buff);
		//printf("\n2\n");
		//free(str);
		//printf("\n3\n");
		str = ptr;
		//printf("str:%s\n",str);
		if (ft_strchr(str, '\n')) 
			break ;
	}
	//ft_putendl(str);
	//ft_putchar('T');
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (i == 0)
		*line = ft_strdup("");
	else
	{
		*line = ft_substr(str, 0, i);
		ptr = str + i + 1;
		free(str);
		str = ptr;
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{

	int fd;
	char *line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);

	int ret = get_next_line(fd, &line);
	ft_putendl(line);
	ret = get_next_line(fd, &line);
	//printf("%d",ret);
	ft_putendl(line);
	//ft_putstr("return value : %d\n%s",ret, line);

	return (0);

}
