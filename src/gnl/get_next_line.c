/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orubin <orubin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 19:30:54 by orubin            #+#    #+#             */
/*   Updated: 2020/07/10 19:42:36 by tasmity          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char		*join(char *buf, char *tmp)
{
	char		*ptr;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (buf)
		i = ft_strlen(buf);
	if (tmp)
		j = ft_strlen(tmp);
	ptr = (char *)malloc(sizeof(char) * (i + j + 1));
	ft_memcpy(ptr, buf, i);
	ft_memcpy(ptr + i, tmp, j);
	ptr[i + j] = '\0';
	free(buf);
	ft_bzero(tmp, BUFF_SIZE + 1);
	return (ptr);
}

static int		end_line(char *buf)
{
	int			i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		buf[i] = '\0';
		return (i);
	}
	else
		return (-1);
}

static int		check(char **buf, char **tmp, char **line)
{
	char		*ptr;
	int			end;

	*buf = join(*buf, *tmp);
	end = end_line(*buf);
	if (end > -1)
	{
		*line = ft_strdup(*buf);
		ptr = *buf;
		*buf = ft_strdup(*buf + end + 1);
		free(ptr);
		return (1);
	}
	return (0);
}

static int		read_next_line(const int fd, char **line, char *tmp)
{
	static char *buf[10240];
	int			vol;

	while ((read(fd, tmp, BUFF_SIZE)) > 0)
	{
		vol = check(&buf[fd], &tmp, line);
		free(tmp);
		if (vol == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	if ((vol = check(&buf[fd], &tmp, line)))
	{
		free(tmp);
		return (1);
	}
	else if (ft_strlen(buf[fd]) > 0)
	{
		*line = ft_strdup(buf[fd]);
		ft_strdel(&buf[fd]);
		return (1);
	}
	ft_strdel(&buf[fd]);
	free(tmp);
	return (vol);
}

int				get_next_line(const int fd, char **line)
{
	char		*tmp;

	tmp = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || BUFF_SIZE <= 0 || (read(fd, tmp, 0)) < 0)
	{
		free(tmp);
		return (-1);
	}
	*line = NULL;
	return (read_next_line(fd, line, tmp));
}
