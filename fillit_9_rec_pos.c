/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_9_rec_pos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:38:53 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/08 16:00:25 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	try_withskip(t_task *task, int *used, int pos, int *sum)
{
	if (try_all(task, used, pos + 1, sum))
		return (1);
	return (0);
}

int	try_put_fig(t_task *task, int *used, int pos, int *sum)
{
	int idx;

	idx = -1;
	while (task->tab_figs[++idx])
	{
		if (used[idx] != -2 && used[idx] != pos)
		{
			if (no_place(task, pos, idx) == 0)
			{
				used[idx] = -2;
				push_f(task, pos, idx, idx + 65);
				if (task->show_step)
					print_mat(task->mat, task->lim, "\n");
				if (is_no_win(task, used, sum))
					if (try_all(task, used, pos + 1, sum))
						return (1);
				if (check_win_out(task, pos, sum))
					return (0);
				push_f(task, pos, idx, '.');
				used[idx] = -1;
				set_as_used(task->tab_figs, used, task->tab_figs[idx], pos);
			}
		}
	}
	return (0);
}

int	free_and_return(int *to_free, int to_return)
{
	free(to_free);
	return (to_return);
}

int	try_all(t_task *task, int *figs_used_init, int pos, int *sum)
{
	int *used;
	int out;

	if ((used = ft_nbrarrdup(figs_used_init, FIG_NUM)) == NULL)
		return (1);
	if (task->use_pos)
	{
		if (check_win_out(task, pos, sum))
			return (free_and_return(used, 0));
		if ((out = try_put_fig(task, used, pos, sum)) == 0)
			out = try_withskip(task, used, pos, sum);
	}
	else
	{
		if (check_win_out_figrec(task, sum))
			return (free_and_return(used, 0));
		out = try_figrec(task, used, pos, sum);
	}
	return (free_and_return(used, out));
}
