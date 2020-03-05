/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 12:10:25 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/03/04 14:23:50 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* This will check for invalid chars and improper format
 * but not validate specific pieces */

t_list	*is_valid_broad(int fd)
{
	int		pieces;
	char	file[FILE_MAX + 1];
	int		ret;
	char	*temp;

	temp = file;
	if ((ret = read(fd, file, FILE_MAX +  1)) > FILE_MAX)
		return (NULL);
	file[ret] = '\0';
	while (*file != '\0')
	{
		i = 0;
		while (i < 20)
		{
			if (i % 5 == 0 && file[i] != '\n')
				return (NULL);
			else if (file[i] != '#' || file[i] != '.')
				return (NULL);
			i++;
		}
		if (file[i] != '\n' && file[i] != '\0')
			return (NULL);
		if (file[i] == '\0')
			break ;
		file += (i + 1);
	}
	return (is_valid(temp));
}

/* After previous validation passes, this will check that
 * specific pieces are valid */

t_list	*is_valid(char *temp)
{
	t_list	*lst;
	t_list	*temp;
	char	rep;

	rep = 'A';
	temp = lst;
	while (*temp != '\0' && *(temp - 1) != '\0')
	{
		if (adjacent_check(temp, 0) == 4)
			temp->coord = copy_coord(temp);
		else
			return (NULL);
		temp->next = new_lst;
		temp = temp->next;
		temp += 21;
	}
	return (lst);
}

int		adjacent_check(char *box, int total)
{
	if (*box != '\0' || (*box == '\n' && *(box - 1) == '\n'))
	{
		if (*box != '#')
			return (0);
		return (adjacent_check(box + 1) + adjacent_check(box + 5));
	}
	return (0);
}
			
