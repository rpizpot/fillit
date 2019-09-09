/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_1_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:38:53 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/08 16:00:34 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	init_flags(t_task *task)
{
	task->use_pos = 0;
	task->no_char_ref = 0;
	task->file = NULL;
	task->first_sol = 1;
	task->show_step = 0;
	task->show_inc = 0;
}

void	init(int figs_used_init[FIG_NUM], t_task *task, int *figs_num, int *sum)
{
	int idx;
	int	line;
	int	col;

	idx = -1;
	while (++idx < FIG_NUM)
	{
		figs_used_init[idx] = -1;
		(task->figs_state_solved)[idx] = -1;
	}
	line = -1;
	while (++line < M_EDGE)
	{
		col = -1;
		while (++col < M_EDGE)
			task->mat[line][col] = '.';
	}
	idx = -1;
	while (++idx < FIG_NUM)
		task->tab_figs[idx] = NULL;
	*figs_num = -1;
	*sum = 0;
	init_flags(task);
}

void	solve_state(int *figs_state_solved, int figs_num)
{
	int idx;

	idx = -1;
	while (++idx < figs_num)
		figs_state_solved[idx] = -2;
}

void	show_size_increase(char win, int lim)
{
	ft_putstr("lim=");
	ft_putnbr(lim);
	if (win)
		ft_putstr(" - SOLVED ");
	else
		ft_putstr(" - FAILED ");
	ft_putstr("\n");
}
