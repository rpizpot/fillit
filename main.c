/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:38:53 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/08 21:47:08 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		flags_handler(t_task *task, int argc, char **argv)
{
	int idx;

	if (argc == 1)
		return (-1);
	idx = 0;
	while (++idx < argc && task->file == NULL)
	{
		if (ft_strcmp(argv[idx], "-p") == 0)
			task->use_pos = 1;
		if (ft_strcmp(argv[idx], "-r") == 0)
			task->no_char_ref = 1;
		if (ft_strcmp(argv[idx], "-f") == 0)
			task->first_sol = 0;
		if (ft_strcmp(argv[idx], "-s") == 0)
			task->show_step = 1;
		if (ft_strcmp(argv[idx], "-i") == 0)
			task->show_inc = 1;
		if (argv[idx][0] != '-')
			task->file = argv[idx];
	}
	if (idx != argc)
		return (-1);
	return (0);
}

int		usage(void)
{
	ft_putstr("usage: fillit [-p] [-r] [-f] [-s] [-i] tetriminos_file\n");
	return (-1);
}

int		main(int argc, char **argv)
{
	int		figs_used_init[FIG_NUM];
	int		sum;
	t_task	task;

	init(figs_used_init, &task, &task.figs_num, &sum);
	if (flags_handler(&task, argc, argv))
		return (usage());
	if ((task.figs_num = fig_read(task.tab_figs, task.file, 1)) == -1)
		return (-1);
	if (final_val_fig(task.tab_figs, task.figs_num, &task))
		return (error_msg(task.tab_figs, "final_val_fig"));
	solve_state(task.figs_state_solved, task.figs_num);
	task.lim = get_min_lim(task.tab_figs);
	task.lim = (task.lim) ? task.lim - 1 : task.lim;
	while (sum == 0 && task.lim < M_EDGE)
	{
		task.lim += 1;
		if (try_all(&task, figs_used_init, 0, &sum))
			return (error_msg(task.tab_figs, "in try_all"));
		if (task.show_inc && sum == 0)
			show_size_increase(0, task.lim);
	}
	if (task.show_inc)
		show_size_increase(1, task.lim);
	free_tab_fig(task.tab_figs);
}
