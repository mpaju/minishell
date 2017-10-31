/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaju <mpaju@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:49:59 by mpaju             #+#    #+#             */
/*   Updated: 2017/10/17 18:49:19 by mpaju            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define MAX_FD 10

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_fd {
	int			fd;
	int			read_ret;
	int			last_line;
	char		*buf;
}				t_fd;

int				get_next_line(const int fd, char **line);

#endif
