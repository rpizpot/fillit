/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 02:28:49 by wgorold           #+#    #+#             */
/*   Updated: 2019/04/22 03:37:41 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstcmp(t_list *trg, t_list *src)
{
	if ((!trg && src) || (trg && !src))
		return (1);
	if (!trg && !src)
		return (0);
	if (trg->content_size != src->content_size)
		return (1);
	if ((!trg->content_size && src->content_size)
			|| (trg->content_size && !src->content_size))
		return (1);
	if (ft_memcmp(trg->content, src->content, src->content_size))
		return (1);
	return (ft_lstcmp(trg->next, src->next));
}
