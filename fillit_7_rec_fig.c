/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_7_rec_fig.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:38:53 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/23 16:37:57 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_no_win_figrec(t_task *task, int pos, int idx, int *sum)
{
	if (pos == task->figs_num && idx < task->lim * task->lim)
	{
		*sum += 1;
		print_mat(task->mat, task->lim, NULL);
		return (0);
	}
	return (1);
}

int		check_win_out_figrec(t_task *task, int *sum)
{
	if ((task->first_sol && *sum))
		return (1);
	return (0);
}

int		try_figrec(t_task *task, int *used, int pos, int *sum)
{
	int idx;
	int idx_mem;

	idx = -1;
	idx_mem = -1;
	while (++idx_mem < pos)
		if (ft_lstcmp(task->tab_figs[pos], task->tab_figs[idx_mem]) == 0)
			idx = (used[idx_mem] > idx) ? used[idx_mem] - 1 : idx;
	while (++idx < task->lim * task->lim)
	{
		if (no_place(task, idx, pos))
			continue;
		used[pos] = idx;
		push_f(task, idx, pos, pos + 65);
		if (task->show_step)
			print_mat(task->mat, task->lim, "\n");
		if (is_no_win_figrec(task, pos, idx, sum))
			if (try_all(task, used, pos + 1, sum))
				return (1);
		if (check_win_out_figrec(task, sum))
			return (0);
		push_f(task, idx, pos, '.');
		used[pos] = -1;
	}
	return (0);
}
