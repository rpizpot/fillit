/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_4_mat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:26:32 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/08 16:00:31 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_mat(char mat[M_EDGE][M_EDGE], int lim, char *end)
{
	int	line;
	int	col;

	line = -1;
	while (++line < lim)
	{
		col = -1;
		while (++col < lim)
			ft_putchar(*(*(mat + line) + col));
		ft_putchar('\n');
	}
	if (end)
		ft_putstr(end);
}

void	pos2corr(int pos, int lim, int *line, int *col)
{
	*line = pos / lim;
	*col = pos % lim;
}

void	pos2corrt(int pos, int lim, int *l_c)
{
	l_c[0] = pos / lim;
	l_c[1] = pos % lim;
}

int		count_square(t_list *fig)
{
	int out;

	if (!fig)
		return (0);
	out = count_square(fig->next);
	return (*(char *)(fig->content)) == '#' ? (1 + out) : (0 + out);
}

int		get_min_lim(t_list *tab_figs[FIG_NUM])
{
	int idx;
	int count;

	count = 0;
	idx = -1;
	while (++idx < FIG_NUM)
		count += count_square(tab_figs[idx]);
	idx = 1;
	while (count > idx * idx)
		++idx;
	return (idx);
}
