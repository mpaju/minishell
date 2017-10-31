/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_filetype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 18:57:13 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/20 18:57:15 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_get_filetype(char *path)
{
	struct stat	statbuf;
	mode_t		mode;
	char		*ret;

	if (lstat(path, &statbuf))
		return (NULL);
	mode = statbuf.st_mode;
	ret = NULL;
	S_ISREG(mode) ? ret = "REG" : 0;
	S_ISDIR(mode) ? ret = "DIR" : 0;
	S_ISLNK(mode) ? ret = "LNK" : 0;
	S_ISBLK(mode) ? ret = "BLK" : 0;
	S_ISCHR(mode) ? ret = "CHR" : 0;
	S_ISFIFO(mode) ? ret = "FIFO" : 0;
	S_ISSOCK(mode) ? ret = "SOCK" : 0;
	return (ret);
}
