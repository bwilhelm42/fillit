/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwilhelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 20:05:49 by bwilhelm          #+#    #+#             */
/*   Updated: 2020/02/24 20:52:27 by bwilhelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrep(char *str, char n, char old)
{
	while (*str != '\0')
	{
		if (*str == old)
			*str = n;
		str++;
	}
}
