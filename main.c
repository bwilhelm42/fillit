/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 13:30:15 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/03/07 13:30:56 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(void)
{
	t_fill	*lst;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	if (is_valid_broad(fd))
		return (write(1, "error\n", 6));
	close(fd);
	fd = open("test.txt", O_RDONLY);
	if (!(lst = is_valid(fd)))
		return (write(1, "error\n", 6));
	while (lst)
	{
		ft_putstrarr(lst->arr);
		write(1, "\n", 1);
		lst = lst->next;
	}
	return (0);
}
