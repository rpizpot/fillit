/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 03:58:13 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/30 17:57:54 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrarr(int *tab, size_t len)
{
	size_t	idx;

	idx = 0;
	ft_putstr("[");
	while (idx < len)
	{
		if (tab[idx] > -1)
			ft_putstr(" ");
		ft_putnbr(tab[idx]);
		ft_putstr(", ");
		idx++;
	}
	ft_putstr("]");
}
