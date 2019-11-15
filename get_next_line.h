/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:52:05 by yait-kad          #+#    #+#             */
/*   Updated: 2019/11/15 18:01:06 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__GET_NEXT_LINE_H
# define	__GET_NEXT_LINE_H
# define BUFFER_SIZE 6
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
int		get_next_line(int fd, char **line);
char	*ft_strchr(char *c1, int c2);
#endif
