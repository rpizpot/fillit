/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_5_fig_mat_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:38:53 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/08 16:00:29 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	change_ref_fig_case(t_list *fig, int *l_c)
{
	if (*(char *)(fig->content) == '1')
		l_c[1] += 1;
	if (*(char *)(fig->content) == '2')
		l_c[1] += 2;
}

int		is_first_hash(t_list *fig)
{
	if (*(char *)(fig->content) == '#'
		&& (!(fig->next) || *(char *)(fig->next->content) == '1'
		|| *(char *)(fig->next->content) == '2'))
		return (1);
	return (0);
}

void	next_line(int *l_c)
{
	l_c[0] += 1;
	l_c[1] -= 3;
}
