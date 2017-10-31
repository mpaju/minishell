/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:43:37 by mpaju             #+#    #+#             */
/*   Updated: 2017/01/16 19:46:20 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_fd	*find_fd(t_list **block, int fd)
{
	t_list	*tmp_block;
	t_fd	*curr_fd;

	tmp_block = *block;
	while (tmp_block)
	{
		curr_fd = tmp_block->content;
		if (curr_fd->fd == fd)
			return (tmp_block->content);
		tmp_block = tmp_block->next;
	}
	if (!(curr_fd = (t_fd *)ft_memalloc(sizeof(t_fd))))
		return (0);
	curr_fd->fd = fd;
	curr_fd->last_line = 0;
	curr_fd->buf = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!(curr_fd->read_ret = read(fd, curr_fd->buf, BUFF_SIZE)))
		return (0);
	if (!(tmp_block = ft_lstnew(curr_fd, sizeof(t_fd))))
		return (0);
	ft_lstadd(block, tmp_block);
	free(curr_fd);
	return ((t_fd *)(*block)->content);
}

static int	read_until_nl(t_fd **fd_content)
{
	char	*freebuf;
	char	*tmpbuf;
	int		newlpos;

	newlpos = ft_chrpos((*fd_content)->buf, '\n');
	tmpbuf = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	(*fd_content)->read_ret = 1;
	while ((*fd_content)->read_ret && !newlpos)
	{
		(*fd_content)->read_ret = read((*fd_content)->fd, tmpbuf, BUFF_SIZE);
		if ((*fd_content)->read_ret < 0)
			return (-1);
		freebuf = (*fd_content)->buf;
		(*fd_content)->buf = ft_strjoin((*fd_content)->buf, tmpbuf);
		ft_bzero(tmpbuf, ft_strlen(tmpbuf));
		free(freebuf);
		newlpos = ft_chrpos((*fd_content)->buf, '\n');
	}
	free(tmpbuf);
	if (!*(*fd_content)->buf)
		return (0);
	return (1);
}

static int	push_line(t_fd **fd_content, char **line)
{
	int		newlpos;
	int		ret;
	char	*tmpbuf;

	ret = 1;
	tmpbuf = ft_strdup((*fd_content)->buf);
	newlpos = ft_chrpos(tmpbuf, '\n');
	if (!newlpos)
	{
		*line = ft_strdup(tmpbuf);
		ret = 0;
	}
	else
	{
		*line = ft_strdup((*fd_content)->buf);
		(*line)[newlpos - 1] = 0;
		ft_bzero((*fd_content)->buf, newlpos);
		ft_memmove((*fd_content)->buf, ((*fd_content)->buf) + newlpos, \
			ft_strlen(((*fd_content)->buf) + newlpos));
		ft_bzero(((*fd_content)->buf) + ft_strlen(((*fd_content)->buf) \
					+ newlpos), newlpos);
	}
	free(tmpbuf);
	return (ret);
}

int			get_next_line(int fd, char **line)
{
	static t_list	*block = NULL;
	t_fd			*fd_content;

	if (!(fd_content = find_fd(&block, fd)) || fd < 0 || !line)
		return (-1);
	if (fd_content->last_line)
		return (0);
	if (!(read_until_nl(&fd_content)))
		return (0);
	if (fd_content->read_ret < 0)
		return (-1);
	if (!push_line(&fd_content, line))
		fd_content->last_line = 1;
	return (1);
}
