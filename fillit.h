/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:10:44 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/03/07 13:18:51 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define FILE_MAX 545

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/get_next_line.h"

typedef struct s_fill
{
	char			**arr;
	char			mark;
	struct s_fill	*next;
}			t_fill;

int		is_valid_broad(int fd);
int		not_counted(t_fill *lst, int y, int x);
int		adj_check(char **box, int y,  int x, t_fill *lst);
int		get_index(char **str, char c);
char	**get_next_piece(int fd);
t_fill	*init_lst(char c, int fd);
t_fill	*is_valid(int fd);
int		hash_count(char **arr);
void	fill_lstdel(t_fill *head);

#endif
