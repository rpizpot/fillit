/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_8_rec_pos_helper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 04:38:53 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/23 16:38:01 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_as_used(t_list *tab[FIG_NUM], int *used, t_list *src, int fill)
{
	size_t idx;

	idx = -1;
	while (tab[++idx])
		if (used[idx] != -2 && ft_lstcmp(tab[idx], src) == 0)
			used[idx] = fill;
}

int		check_win_out(t_task *task, int pos, int *sum)
{
	if ((task->first_sol && *sum) || pos >= task->lim * task->lim)
		return (1);
	return (0);
}

int		is_no_win(t_task *task, int *used, int *sum)
{
	if (ft_nbrarrcmp(used, task->figs_state_solved, FIG_NUM) == 0)
	{
		*sum += 1;
		print_mat(task->mat, task->lim, NULL);
		return (0);
	}
	return (1);
}

void	show_fig(char *name, t_list *elem)
{
	ft_putstr(name);
	ft_lstprintstr(elem);
	ft_putstr("\n");
}
