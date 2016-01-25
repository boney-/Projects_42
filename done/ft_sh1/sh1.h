/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 16:24:38 by jbonnet           #+#    #+#             */
/*   Updated: 2015/01/18 17:54:45 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH1_H
# define FT_SH1_H

# include <libft.h>

typedef struct	s_env
{
	char		**env;
	char		**args;
	t_list		*list;
}				t_env;

char			*ft_get_var_env(t_list **list, char *var);
int				ft_check_var_env(t_env *e, char *args1, char *args2, int nb);
void			ft_handler(int sig);
void			ft_get_stdin(t_env *e);
void			ft_prompt(void);
char			*ft_currentdir(char **dir);
int				ft_check_stdin(char *str, t_env *e);
int				ft_exec_cmd(char *cmd, t_env *e);
char			*ft_get_first_word(char *str, char ***args);
int				ft_exec_builtins(char *cmd, t_env *e);
void			ft_exit(t_env *e);
void			ft_cd(t_env *e);
int				ft_cd_error(char *args);
void			ft_update_pwd(t_env *e);
int				ft_cd_exceptions(t_env *e);
void			ft_env(t_env *e);
void			ft_setenv(t_env *e);
void			ft_setenv_value(t_env *e, char *arg1, char *arg2);
int				ft_check_var_env(t_env *e, char *args1, char *args2, int nb);
void			ft_unsetenv(t_env *e);
void			ft_lstdel_onelink(t_env *e);
void			ft_err(char *str);
int				ft_strchar(char *str, unsigned char c);
void			ft_tab_to_lst(t_list **list, char **tab);
char			*ft_check_path(char *cmd, t_env *e);
void			ft_init(char ***tab);
int				ft_cd_tilde(t_env *e);

#endif
