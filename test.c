#include "fillit.h"
#include <stdio.h>
#include <string.h>

t_fill	*init_lst(char c);
int		adj_check(char **box, int y,  int x, t_fill *lst);
int		not_counted(t_fill *lst, int y, int x);

int		main(int ac, char **av)
{
	t_fill	*lst;

	(void)ac;
	lst = init_lst('A');
	adj_check(&av[1], 0, 0, lst);
	return (0);
}

t_fill	*init_lst(char c)
{
	t_fill	*new;
	int		i;

	new = (t_fill*)malloc(sizeof(t_fill));
	new->arr = (char**)malloc(sizeof(char*) * 5);
	i = 0;
	while (new->arr[i])
	{
		new->arr[i] = (char*)ft_memalloc(sizeof(char) * 5);
		ft_memset(new->arr[i], 4, '.');
		i++;
	}
	new->mark = c;
	new->next = NULL;
	return (new);
}

int		adj_check(char **box, int y,  int x, t_fill *lst)
{
	int i;

	i = 0;
	if (x > 3 || y > 3)
		return (0);
	if (box[y][x] == '#' && not_counted(lst, y, x))
		return (1 + adj_check(box, y, x + 1, lst) + adj_check(box, y, x - 1, lst)
				+ adj_check(box, y + 1, x, lst) + adj_check(box, y - 1, x, lst));
	return (0);
}

int		not_counted(t_fill *lst, int y, int x)
{
	if (lst->arr[y][x] == lst->mark)
		return (0);
	lst->arr[y][x] = lst->mark;
	return (1);
}
