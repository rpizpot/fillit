/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrarrcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:17:04 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/26 23:12:35 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrarrcmp(const int *s1, const int *s2, size_t len)
{
	size_t	idx;

	idx = 0;
	while (idx < len)
	{
		if (s1[idx] != s2[idx])
			return (s1 - s2);
		idx++;
	}
	return (0);
}
