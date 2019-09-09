/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_6_fig_mat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:38:53 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/08 16:00:27 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		no_place_fig(char mat[M_EDGE][M_EDGE], int lim, t_list *fig, int *l_c)
{
	if (!fig)
		return (0);
	if (no_place_fig(mat, lim, fig->next, l_c))
		return (1);
	change_ref_fig_case(fig, l_c);
	if (is_first_hash(fig))
		return (mat[l_c[0]][l_c[1]] != '.') ? 1 : 0;
	if (*(char *)(fig->content) == '#' && *(char *)(fig->next->content) == '#')
	{
		l_c[1] += 1;
		return (l_c[1] >= lim || mat[l_c[0]][l_c[1]] != '.') ? 1 : 0;
	}
	if (*(char *)(fig->content) == '.' && *(char *)(fig->next->content) == '#')
		next_line(l_c);
	if (*(char *)(fig->content) == '.' && *(char *)(fig->next->content) == '.')
		l_c[1] += 1;
	if (*(char *)(fig->content) == '#' && *(char *)(fig->next->content) == '.')
	{
		l_c[1] += 1;
		return (l_c[1] < 0 || l_c[1] >= lim || l_c[0] >= lim
						|| mat[l_c[0]][l_c[1]] != '.') ? 1 : 0;
	}
	return (0);
}

void	push_fig(char mat[M_EDGE][M_EDGE], t_list *fig, int *l_c, char fill)
{
	if (!fig)
		return ;
	push_fig(mat, fig->next, l_c, fill);
	change_ref_fig_case(fig, l_c);
	if (is_first_hash(fig))
	{
		mat[l_c[0]][l_c[1]] = fill;
		return ;
	}
	if (*(char *)(fig->content) == '#' && *(char *)(fig->next->content) == '#')
	{
		l_c[1] += 1;
		mat[l_c[0]][l_c[1]] = fill;
	}
	if (*(char *)(fig->content) == '.' && *(char *)(fig->next->content) == '#')
		next_line(l_c);
	if (*(char *)(fig->content) == '.' && *(char *)(fig->next->content) == '.')
		l_c[1] += 1;
	if (*(char *)(fig->content) == '#' && *(char *)(fig->next->content) == '.')
	{
		l_c[1] += 1;
		mat[l_c[0]][l_c[1]] = fill;
	}
	return ;
}

int		no_place(t_task *task, int pos, int idx)
{
	int l_c[2];

	pos2corrt(pos, task->lim, l_c);
	return (no_place_fig(task->mat, task->lim, task->tab_figs[idx], l_c));
}

void	push_f(t_task *task, int pos, int idx, char fill)
{
	int l_c[2];

	pos2corrt(pos, task->lim, l_c);
	push_fig(task->mat, task->tab_figs[idx], l_c, fill);
}
