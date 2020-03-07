/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:03:37 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/03/07 13:31:29 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_lstdel(t_fill *head)
{
	if (head->next)
		fill_lstdel(head->next);
	while (*head->arr)
	{
		free(*head->arr);
		head->arr++;
	}
	free(head);
}

int		hash_count(char **arr)
{
	int i;
	int count;

	count = 0;
	if (!arr)
		return (0);
	while (*arr)
	{
		i = 0;
		while ((*arr)[i])
		{
			if ((*arr)[i] == '#')
				count++;
			i++;
		}
		arr++;
	}
	return (count);
}

t_fill	*init_lst(char c, int fd)
{
	t_fill *lst;

	lst = (t_fill*)malloc(sizeof(t_fill));
	lst->mark = c;
	lst->next = NULL;
	lst->arr = get_next_piece(fd);
	return (lst);
}

char	**get_next_piece(int fd)
{
	char	**str;
	int		i;

	str = (char**)malloc(sizeof(char*) * 5);
	str[4] = NULL;
	i = -1;
	while (++i < 4)
		get_next_line(fd, &str[i]);
	return (str);
}

int		get_index(char **str, char c)
{
	int i;
	int index;

	index = 0;
	if (!str)
		return (0);
	while (*str != NULL)
	{
		i = 0;
		while ((*str)[i] != '\0')
		{
			if ((*str)[i] == c)
				return (index);
			index++;
			i++;
		}
		str++;
	}
	return (0);
}
