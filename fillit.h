/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgorold <wgorold@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:08:57 by wgorold           #+#    #+#             */
/*   Updated: 2019/05/08 20:14:03 by wgorold          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define FIG_FIELD 5
# define FIG_NUM 26
# define M_EDGE 20

# define REF_FIGS_NUM 50
# define REF_FIGS "reference"

# define DEBUG 0
# define SHOW_CUT_FIG 0
# define SHOW_CUT_REF_FIG 0
# define SHOW_ADDED_FIG 0

# define FD_FOR_ERR 1
# include "./libft/libft.h"
# include <fcntl.h>

typedef	struct		s_task
{
	t_list			*tab_figs[FIG_NUM];
	char			mat[M_EDGE][M_EDGE];
	int				lim;
	int				figs_state_solved[FIG_NUM];
	int				figs_num;
	char			use_pos;
	char			no_char_ref;
	char			*file;
	char			first_sol;
	char			show_step;
	char			show_inc;
}					t_task;

int					error_msg(t_list **tab_figs, char *why);
int					check_line(int ret, char *buf, t_list **figs);
void				cut_fig(t_list **figs, t_list *cur, int count);
int					fig_read(t_list **figs, char *filename, int show_error);
int					figcmp_ref(t_list **fig, t_list **ref, int idx,
	t_task *task);
int					final_val_fig(t_list **figs, int fig_num, t_task *task);
void				print_mat(char mat[M_EDGE][M_EDGE], int lim, char *end);
void				set_as_used(t_list *tab[FIG_NUM], int *used,
	t_list *src, int fill);
void				pos2corr(int pos, int lim, int *line, int *col);
void				pos2corrt(int pos, int lim, int *l_c);
int					count_square(t_list *fig);
int					get_min_lim(t_list *tab_figs[FIG_NUM]);
void				init(int figs_used_init[FIG_NUM], t_task *task,
	int *figs_num, int *sum);
void				solve_state(int *figs_state_solved, int figs_num);
void				show_size_increase(char win, int lim);
int					no_place_fig(char mat[M_EDGE][M_EDGE], int lim,
	t_list *fig, int *l_c);
int					no_place(t_task *task, int pos, int idx);
void				push_fig(char mat[M_EDGE][M_EDGE], t_list *fig,
	int *l_c, char fill);
void				push_f(t_task *task, int pos, int idx, char fill);
void				set_as_used(t_list *tab[FIG_NUM], int *used,
	t_list *src, int fill);
int					check_win_out(t_task *task, int pos, int *sum);
int					try_all(t_task *task, int *figs_used_init,
	int pos, int *sum);
void				set_as_used(t_list *tab[FIG_NUM], int *used,
	t_list *src, int fill);
int					is_no_win(t_task *task, int *used, int *sum);
void				free_tab_fig(t_list **tab_figs);
void				show_fig(char *name, t_list *elem);
void				next_line(int *l_c);
int					is_first_hash(t_list *fig);
void				change_ref_fig_case(t_list *fig, int *l_c);
int					is_no_win_figrec(t_task *task, int pos, int idx, int *sum);
int					check_win_out_figrec(t_task *task, int *sum);
int					try_figrec(t_task *task, int *used, int pos, int *sum);

#endif
