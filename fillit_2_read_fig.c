/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_2_read_fig.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:16:42 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/08 18:37:08 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		error_msg(t_list **tab_figs, char *why)
{
	free_tab_fig(tab_figs);
	ft_putstr_fd("error", FD_FOR_ERR);
	if (why && DEBUG)
	{
		ft_putstr_fd(" - ", FD_FOR_ERR);
		ft_putstr_fd(why, FD_FOR_ERR);
	}
	ft_putstr_fd("\n", FD_FOR_ERR);
	return (-1);
}

void	cut_fig(t_list **figs, t_list *cur, int count)
{
	if (!cur)
		return ;
	if (*(char *)cur->content == '#')
		cut_fig(figs, cur->next, count + 1);
	else
		cut_fig(figs, cur->next, count);
	if (count == 0 && *(char *)cur->content == '#')
		*figs = cur;
	if (count == 0 && *(char *)cur->content != '#')
	{
		free(cur->content);
		free(cur);
	}
}

int		check_line(int ret, char *buf, t_list **figs)
{
	int		idx;
	t_list	*tmp;

	idx = 0;
	if (ret != FIG_FIELD)
		return (1);
	while (idx < FIG_FIELD)
	{
		if (idx == FIG_FIELD - 1)
			return (*(buf + idx) != '\n') ? (1) : (0);
		if (*(buf + idx) != '.' && *(buf + idx) != '#')
			return (1);
		if (*figs || *(buf + idx) == '#')
		{
			if ((tmp = ft_lstnew((buf + idx), 1)) == NULL)
				return (1);
			ft_lstadd(figs, tmp);
		}
		idx++;
	}
	return (0);
}

int		buf_fig(int fd, char buf[FIG_FIELD + 1], t_list **figs, int idx_fig)
{
	int		ret;
	int		idx;

	idx = -1;
	while (++idx < 4)
	{
		if ((ret = read(fd, buf, FIG_FIELD)) == -1)
			return (error_msg(figs, "buf_fig: read error"));
		buf[FIG_FIELD] = '\0';
		if (check_line(ret, buf, &figs[idx_fig]))
			return (error_msg(figs, "check_line: map error"));
	}
	return (0);
}

int		fig_read(t_list **figs, char *filename, int show_error)
{
	int		fd;
	int		ret;
	int		idx_fig;
	char	buf[FIG_FIELD + 1];

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (show_error) ? (error_msg(figs, "open_file")) : -1;
	idx_fig = -1;
	while (++idx_fig < FIG_NUM + 1)
	{
		if (idx_fig == FIG_NUM)
			return (error_msg(figs, "more then 26 figs"));
		if (buf_fig(fd, buf, figs, idx_fig))
			return (-1);
		cut_fig(&figs[idx_fig], figs[idx_fig], 0);
		if (SHOW_CUT_FIG)
			show_fig("SHOW_CUT_FIG", figs[idx_fig]);
		if ((ret = read(fd, buf, 1)) == 0)
			break ;
		if (buf[0] != '\n')
			return (error_msg(figs, "map error - \'\\n\'"));
	}
	close(fd);
	return (idx_fig + 1);
}
