/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_3_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 18:02:58 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/08 16:00:32 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_tab_ref(char **ref)
{
	ref[0] = "#...#...#...#";
	ref[1] = "####";
	ref[2] = "##..##";
	ref[3] = "##.##";
	ref[4] = "#...##...#";
	ref[5] = "##...##";
	ref[6] = "#..##..#";
	ref[7] = "#..###";
	ref[8] = "#..##...#";
	ref[9] = "#...##..#";
	ref[10] = "###..#";
	ref[11] = "###.#";
	ref[12] = "#...#...##";
	ref[13] = "#.###";
	ref[14] = "##...#...#";
	ref[15] = "#...###";
	ref[16] = "##..#...#";
	ref[17] = "###...#";
	ref[18] = "#...#..##";
	ref[19] = NULL;
}

int		make_ref_fig(t_list **tab_figs)
{
	int		idx;
	int		idx_char;
	char	*ref[20];
	t_list	*tmp;

	get_tab_ref(ref);
	idx = -1;
	while (ref[++idx])
	{
		idx_char = -1;
		while (ref[idx][++idx_char])
		{
			if ((tmp = ft_lstnew(ref[idx] + idx_char, 1)) == NULL)
			{
				free_tab_fig(tab_figs);
				return (1);
			}
			ft_lstadd(&tab_figs[idx], tmp);
		}
		if (SHOW_CUT_REF_FIG)
			show_fig("SHOW_CUT_REF_FIG", tab_figs[idx]);
	}
	return (0);
}

int		figcmp_ref(t_list **fig, t_list **ref, int idx, t_task *task)
{
	char	to_add;
	t_list	*tmp;

	to_add = (idx == 13) ? '2' : '1';
	if (!ref[idx])
		return (1);
	if (ft_lstcmp(*fig, ref[idx]) == 0)
	{
		if (task->no_char_ref)
			return (0);
		if (idx == 3 || idx == 6 || idx == 7 || idx == 8 || idx == 18
		|| idx == 13)
		{
			if ((tmp = ft_lstnew(&to_add, 1)) == NULL)
				return (1);
			ft_lstaddback(fig, tmp);
		}
		if (SHOW_ADDED_FIG)
		{
			ft_lstprintstr(*fig);
			ft_putstr("\n");
		}
		return (0);
	}
	return (figcmp_ref(fig, ref, idx + 1, task));
}

int		final_val_fig(t_list **figs, int fig_num, t_task *task)
{
	static t_list	*ref_figs[REF_FIGS_NUM];
	int				idx;

	if ((fig_read(ref_figs, REF_FIGS, 0)) == -1)
		if (make_ref_fig(ref_figs))
			return (1);
	idx = -1;
	while (++idx < fig_num)
	{
		if (figcmp_ref(&figs[idx], ref_figs, 0, task))
		{
			if (DEBUG)
			{
				ft_lstprintstr(figs[idx]);
				ft_putstr("\n");
			}
			free_tab_fig(ref_figs);
			return (1);
		}
	}
	free_tab_fig(ref_figs);
	return (0);
}

void	free_tab_fig(t_list **tab_figs)
{
	int idx;

	idx = -1;
	while (tab_figs[++idx] && idx < FIG_NUM)
		ft_lstfree(&tab_figs[idx]);
}
