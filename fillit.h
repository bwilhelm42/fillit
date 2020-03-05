/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:10:44 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/03/04 18:11:48 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FILE_MAX 545

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_fillit
{
	char			**arr;
	char			mark;
	struct s_fillit	*next;
}			t_fill;

//t_fill is_valid_broad(int fd);
int		adjacent_check(char *box);

#endif
