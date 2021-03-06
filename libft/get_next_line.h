/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:28:35 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/03/07 00:05:19 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 30
# define INT_MAX 2147483647
# define FD_MAX 1000
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

int		get_next_line(const int fd, char **line);
int		got_next_line(char **file, const int fd, char **line);
int		find_newline(char **file, char **line);
void	ft_set_realloc(char **str, int new_pos);
int		find_nl(char **file, char **line);
int		sort_returns(long ret);
int		handle_eof(char **file, char **line);

#endif
