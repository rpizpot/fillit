/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrarrdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 01:30:46 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/26 23:05:31 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_nbrarrdup(const int *s1, size_t len)
{
	int	*out;

	if (!len)
		return (NULL);
	out = (int *)malloc(sizeof(int) * len);
	if (!out)
		return (NULL);
	while (--len > 0)
	{
		out[len] = s1[len];
	}
	out[len] = s1[len];
	return (out);
}
