/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbonnet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 13:57:15 by jbonnet           #+#    #+#             */
/*   Updated: 2015/02/04 14:54:34 by jbonnet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <stdarg.h>
# include <wchar.h>
# include <wctype.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_env
{
	int			new;
	t_list		*list;
	int			nargs;
	va_list		ap;
	int			point;
	int			prespace;
	char		*tab[4];
	char		**precision;
	int			rvalue;
	int			diez;
	int			zero;
	int			moins;
	int			plus;
	int			space;
	int			isint;
	int			h;
	int			l;
	int			j;
	int			z;
	int			o;
	int			u;
	int			x;
	int			gx;
	int			go;
	int			gu;
	int			oct;
	int			nb;
}				t_env;

int				ft_printf(char *str, ...);
int				ft_check_flags(char c);
int				ft_check_c(char c, t_env *e);
void			ft_putchar_mod(char c, t_env *e);
void			ft_putstr_mod(char *str, t_env *e);
int				ft_check_convs(char c, t_env *e);
void			ft_space_precision(char *str, t_env *e);
void			ft_treat_options(char *flags, t_env *e);
void			ft_print_char(int i, char c, t_env *e);
void			ft_justification(char *str, t_env *e);
void			ft_treat_string(char *flags, char *str, t_env *e);
void			ft_treat_int_str(char *nombre, t_env *e);
void			ft_treat_long_int(long nb, t_env *e);
void			ft_treat_normal_int(int nb, t_env *e);
void			ft_treat_int(char *flags, t_env *e);
char			ft_itohex(int nb, t_env *e);
char			*ft_dec_to_hex(long nombre, t_env *e);
char			*ft_dec_to_hex_ul(unsigned long nombre, t_env *e);
char			*ft_dec_to_bin(int nombre);
char			*ft_dec_to_oct(unsigned long nombre);
void			ft_treat_char(char *flags, char c, t_env *e);
void			ft_treat_address(char *flags, unsigned long adr, t_env *e);
void			ft_treat_ogo(char *flags, unsigned long nombre, t_env *e);
void			ft_treat_xgx(char *flags, unsigned long nombre, t_env *e);
void			ft_treat_oux(char *flags, unsigned long nombre, t_env *e);
void			ft_up_convs(char c, t_env *e);
void			ft_up_flags(char *flags, int i, t_env *e);
void			ft_putwchar(int c, t_env *e);
void			ft_print_wchar(char *mask, t_env *e);
void			ft_fill_mask(char *maskk, char *str, int len, t_env *e);
void			ft_check_char(int i, t_env *e);
int				ft_wchar_len(int i);
int				ft_wstrlen(wchar_t *str, int max);
int				ft_precision_gs(wchar_t *str, t_env *e);
void			ft_treat_gs(char *flags, wchar_t *str, t_env *e);
void			ft_treat_gc(char *flags, wint_t c, t_env *e);
void			ft_exec_arg(char *str, int i, t_env *e);
int				ft_check_str(char *str, t_env *e);
void			ft_parse(char *str, t_env *e);
char			*ft_itoa_long(long n);
char			*ft_itoa_ulong(unsigned long n);
void			ft_init(t_env *e);
void			ft_init_mask(t_env *e);
#endif
