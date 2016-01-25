/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/10 12:55:10 by jbonnet           #+#    #+#             */
/*   Updated: 2015/03/16 12:33:45 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H

# include <libft.h>

typedef struct		s_stack
{
	int				nb;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_env
{
	t_stack			*stacka;
	t_stack			*stackb;
	t_list			*calls;
	int				opt_v;
	int				opt_w;
	int				opt_c;
}					t_env;

void				tab_to_lst(t_stack **list, char **tab, int i);
void				push(t_stack **src, t_stack **dest, char *str, t_env *e);
void				rotate(t_stack **stack, t_env *e);
t_stack				*lst_new(int content);
void				r_rotate(t_stack **stack, t_env *e);
void				swap(t_stack **list, char *str, t_env *e);
void				stack_push(t_stack **alst, t_stack *new);
void				add_to_lst(char *str, t_env *e);
void				print_lst(t_stack **list, char c);
void				quit_message(char *str);
void				init_env(t_env *e);
void				tab_to_lst(t_stack **list, char **tab, int i);
void				sort_this_shit(t_stack **stacka, t_stack **stackb,
		t_env *e);
void				print_calls(t_list **list, t_env *e);
int					check_options(char **tab, t_env *e);
void				print_opt_v(t_stack **stacka, t_stack **stackb);
int					is_list_sorted(t_stack **stacka);
int					last_content(t_stack **stack);
int					lst_size(t_stack **stack);
void				int_overflow(char **tab, int i);
int					min_in_stack(t_stack **stack);
int					second_min(t_stack **stack, int nmin);
#endif
