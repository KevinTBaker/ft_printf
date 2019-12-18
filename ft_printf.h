/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbaker <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:52:10 by kbaker            #+#    #+#             */
/*   Updated: 2019/12/17 19:58:32 by kbaker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_conv
{
	char		convchar;
	int			lil_s;
	int			lil_p;
	int			lil_i;
	int			lil_d;
	int			lil_o;
	int			lil_u;
	int			lil_x;
	int			lil_f;
	int			big_x;
	int			lil_c;
	int			single_h;
	int			double_h;
	int			big_l;
	int			single_l;
	int			double_l;
	int			plus;
	int			minus;
	int			space;
	int			zero;
	char		convert;
	int			percent;
	int			width;
	int			hash;
	int			prec;
	int			len;
	intmax_t	nbr;
	int			neg;
	int			flag;
	int			pw_exist;
	int			lengths;
	int			convs;
	int			dperc;
	int			nnbr;
	float		flnbr;
	int			rlen;
	int			dhash;
	int			wplus;
	int			mnbr;
	int			zlen;
	int			periprec;
}				t_conv;

typedef struct	s_convone
{
	int			retlen;
	int			unbr;
}				t_convone;

int				parser(char *str, t_conv *tools, t_convone *toolsone, int i);
void			ft_doing(t_conv *tools, t_convone *toolsone);
int				ft_printf(const char *format, ...);
int				gather_flags(char *str, int i,
		t_conv *tools, t_convone *toolsone);
int				gather_prec(char *str, int i, t_conv *tools);
int				gather_length(char *str, int i, t_conv *tools);
int				gather_strings_character(char *str, int i, t_conv *tools);
int				gather_pointers_hexes(char *str, int i, t_conv *tools);
int				gather_unsigned_octal_floats(char *str, int i, t_conv *tools);
int				gather_decimals_integers(char *str, int i, t_conv *tools);
int				gather_convs(char *str, int i, t_conv *tools);
void			flags_get_done(t_conv *tools, t_convone *toolsone);
void			minus_flag_done(t_conv *tools, t_convone *toolsone);
void			plus_and_space_flag_done(t_conv *tools, t_convone *toolsone);
void			zero_flag_done(t_conv *tools, t_convone *toolsone);
void			hash_flag_done(t_conv *tools, t_convone *toolsone);
int				convs_get_done(t_conv *tools, t_convone *toolsone, va_list vl);
int				integers_done(t_conv *tools, t_convone *toolsone, va_list vl);
int				octal_done(t_conv *tools, t_convone *toolsone, va_list vl);
int				strings_done(t_conv *tools, t_convone *toolsone, va_list vl);
int				unsigned_done(t_conv *tools, t_convone *toolsone, va_list vl);
int				uppercase_hex_done(t_conv *tools,
		t_convone *toolsone, va_list vl);
int				pointers_done(t_conv *tools, t_convone *toolsone, va_list vl);
int				floats_done(t_conv *tools, t_convone *toolsone, va_list vl);
void			zeroing_convs(t_conv *tools);
intmax_t		ft_turn_to_positive(t_conv *tools);
void			precision_and_width_get_it(t_conv *tools, t_convone *toolsone);
void			ints_width_and_precision(t_conv *tools, t_convone *toolsone);
void			ints_width_or_precision(t_conv *tools);
int				chars_done(t_conv *tools, t_convone *toolsone, va_list vl);
int				lowercase_hex_done(t_conv *tools,
		t_convone *toolsone, va_list vl);
char			ft_turn_to_lowercase(char *s1);
char			*ft_uitoa_base2(long long nb, const size_t base);
char			*ft_uitoa_base_pf(uintmax_t value, int base, char x);
char			*ft_ldtoa(double n, int precision);
void			ft_lengths_done(t_conv *tools, va_list vl);
int				ft_len_of_pw(char *str, int i, t_conv *tools);
void			ft_deci_lengths_done(t_conv *tools, va_list vl);
void			ft_octals_hex(t_conv *tools, va_list vl);
void			char_lens(char c, char *s1, t_conv *tools, va_list vl);
void			ft_floats_ls(t_conv *tools, va_list vl);
void			ft_unsigned_len(t_conv *tools, va_list vl);
void			hash_width_and_prec(t_conv *tools, t_convone *toolsone);
void			hash_width(t_conv *tools, t_convone *toolsone);
void			lilo_hash_width_and_prec(t_conv *tools, t_convone *toolsone);
void			lilx_hash_width_prec(t_conv *tools, t_convone *toolsone);
void			bigx_hash_width_prec(t_conv *tools, t_convone *toolsone);
void			main_width_and_prec(t_conv *tools, t_convone *toolsone);
void			ints_width_and_precision2(t_conv *tools, t_convone *toolsone);
void			ints_prec(t_conv *tools, t_convone *toolsone);
void			char_width(t_conv *tools, t_convone *toolsone);
void			ints_prec_or_width(t_conv *tools, t_convone *toolsone);
int				gather_doubleperc(char *str, int i, t_conv *tools);
int				double_perc_done(t_conv *tools, t_convone *toolsone);
void			ft_minus_hash(char *s1, t_conv *tools, t_convone *toolsone);
void			ft_minus_and_plus(char *s1, t_conv *tools, t_convone *toolsone);
void			minus_width(char *s1, t_conv *tools, t_convone *toolsone);
void			minus_prec_width(char *s1, t_conv *tools, t_convone *toolsone);
void			ft_minus_string_p_and_w(char *s1, char *s2,
		t_conv *tools, t_convone *toolsone);
void			ft_minus_string_w(char *s1, t_conv *tools, t_convone *toolsone);
char			*ft_itoa_base2(int value, int base);
char			*ft_uitoa_base3(size_t value, int base);
char			*ft_itoa_base3(intmax_t value, int base);
int				flag_search(char c);
void			ft_nbr_and_prec_is_zero(char *s1, t_conv *tools,
		t_convone *toolsone);
void			plus_and_space_if_nbr_is_positive(t_conv *tools,
		t_convone *toolsone);
void			space_if_nbr_is_positive(t_conv *tools, t_convone *toolsone);
void			ft_len_of_pw_w(int n, int len, t_conv *tools);
int				absolute(int n);
void			ft_hash_width_zero_flag(t_conv *tools, t_convone *toolsone);
void			ft_nbr_and_prec_else(char *s1, t_conv *tools,
		t_convone *toolsone);
void			lilo_no_width_hash_prec(t_conv *tools);
void			hexes_else_statement(char *s1, t_conv *tools,
		t_convone *toolsone);
void			octal_else_statement(char *s1, t_conv *tools,
		t_convone *toolsone);
void			strings_if_statement(char *s1, char *s2,
		t_conv *tools, t_convone *toolsone);
void			string_else_statement(char *s1, char *s2,
		t_conv *tools, t_convone *toolsone);
void			minus_prec_width_space_neg(t_conv *tools, t_convone *toolsone);
void			minus_width_hash(t_conv *tools, t_convone *toolsone);
void			if_neg_or_plus(t_conv *tools, t_convone *toolsone);
void			if_plus_or_neg(t_conv *tools);
int				else_if_prec(t_conv *tools, int n, int len);
void			width_and_prec_if(t_conv *tools, t_convone *toolsone);
void			width_and_prec_else_if(t_conv *tools, t_convone *toolsone);

#endif
