/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:10:25 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/03/07 13:29:57 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This will check for invalid chars and improper format
** but not validate specific pieces
*/

int		is_valid_broad(int fd)
{
	char	file[FILE_MAX + 1];
	int		ret;
	int		i;
	char	*temp;

	temp = file;
	if ((ret = read(fd, temp, FILE_MAX + 1)) > FILE_MAX)
		return (1);
	temp[ret] = '\0';
	while (*temp != '\0')
	{
		i = -1;
		while (++i < 20)
		{
			if (((i + 1) % 5 == 0 && temp[i] != '\n') ||
					((i + 1) % 5 != 0 && temp[i] != '#' && temp[i] != '.'))
				return (1);
		}
		if (temp[i] != '\n' && temp[i] != '\0')
			return (1);
		if (temp[i] == '\n')
			temp += 1;
		temp += i;
	}
	return (0);
}

/*
** After previous validation passes, this will check that
** specific pieces are valid and copy them into nodes in
** a linked list
*/

t_fill	*is_valid(int fd)
{
	t_fill	*head;
	t_fill	*lst;
	char	mark;
	int		index;
	char	*c;

	mark = 'A';
	lst = init_lst(mark, fd);
	head = lst;
	while (1)
	{
		index = get_index(lst->arr, '#');
		if ((hash_count(lst->arr) != 4) ||
			(adj_check(lst->arr, index / 4, index % 4, lst) != 4))
		{
			fill_lstdel(head);
			return (NULL);
		}
		if (get_next_line(fd, &c) <= 0)
			break ;
		lst->next = init_lst(++mark, fd);
		lst = lst->next;
	}
	return (head);
}

int		adj_check(char **box, int y, int x, t_fill *lst)
{
	if (x > 3 || y > 3 || x < 0 || y < 0)
		return (0);
	if (box[y][x] == '#' && not_counted(lst, y, x))
		return (1 + adj_check(box, y, x + 1, lst)
				+ adj_check(box, y, x - 1, lst)
				+ adj_check(box, y + 1, x, lst)
				+ adj_check(box, y - 1, x, lst));
	else
		return (0);
}

int		not_counted(t_fill *lst, int y, int x)
{
	if (lst->arr[y][x] == lst->mark)
		return (0);
	lst->arr[y][x] = lst->mark;
	return (1);
}
