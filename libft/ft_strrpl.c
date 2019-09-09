/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrpl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:31:15 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/26 21:06:40 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strrpl(char *s, char target, char to_replace)
{
	size_t	idx;

	idx = -1;
	while (s[++idx])
		if (s[idx] == target)
			s[idx] = to_replace;
}
