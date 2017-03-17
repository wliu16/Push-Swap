/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:15:34 by wliu              #+#    #+#             */
/*   Updated: 2017/02/15 12:28:27 by wliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line.h"
# include "limits.h"

typedef struct	s_stack
{
	int		*a;
	int		size_a;
	int		*b;
	int		size_b;
	int		*op_num_a;// op_num_a[i]: # of steps to move a[i] to top
	int		*op_num_b;// op_num_b[i]: # of steps to move right position of a[i] to top
	//max, min, index of max, index of min
	int		a_max;
	int		a_min;
	int		a_max_ind;
	int		a_min_ind;
	int		b_max;
	int		b_min;
	int		b_max_ind;
	int		b_min_ind;
	bool	flag_v;
}				t_stack;

int				valid_num_input(const char *str, int *data);
int				valid_instr(char *instr);
void			solve(t_stack *s);
void			solve_3(t_stack *s);
void			solve_5(t_stack *s);
void			solve_large(t_stack *s);
void			calc_max_min(t_stack *s);
void			f_heuristic(t_stack *s, int index_a);
void			to_top_a(t_stack *s, int index);
int				get_min_steps(t_stack *s, int size);
int				steps_to_top(int index, int size, char up_down);
void			push_to_stack(t_stack *s, char to_stack, int i);
void			push_b_to_a(t_stack *s);
int				error(void);
int				res_ok(t_stack *s);
int				res_ko(t_stack *s);
void			print_stack(t_stack *s);
t_stack			*create_stack(int ac, char **av);
int				is_sort(int *arr, int size);
t_stack			*free_stack(t_stack *s);
void			free_matrix(char **matrix);
int				pop(int **arr, int size);
void			push(int **arr, int elem, int size);
void			op_swap(t_stack *s, char stack, bool print);
void			op_swap_ab(t_stack *s, bool print);
void			op_push(t_stack *s, char to_stack, bool print);
void			op_rotate(t_stack *s, char stack, bool print);
void			op_rotate_ab(t_stack *s, bool print);
void			op_reverse(t_stack *s, char stack, bool print);
void			op_reverse_ab(t_stack *s, bool print);

#endif
