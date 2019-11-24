#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h> //DELETE//
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

#define FLAGS(x) (x == '#' || x == ' ' || x == '0' || x == '+' || x == '-')
#define CONV(x) (ft_strchr(CONVERSIONS, x))
#define CONVERSIONS "sSpidDoOuUxXcC"
#define CONVERT tools->convert
#define MINUS tools->minus
#define SPACE tools->space
#define ZERO tools->zero
#define PLUS tools->plus
#define WIDTH tools->width
#define HASH tools->hash
#define PREC tools->prec
#define SINGLEH tools->single_h
#define DOUBLEH tools->double_h
#define BIGL tools->big_l
#define SINGLEL tools->single_l
#define DOUBLEL tools->double_l
#define LILS tools->lil_s
#define LILP tools->lil_p
#define LILI tools->lil_i
#define LILD tools->lil_d
#define LILO tools->lil_o
#define LILU tools->lil_u
#define LILX tools->lil_x
#define LILF tools->lil_f
#define BIGX tools->big_x
#define LILC tools->lil_c
#define FLAG tools->flag
#define LEN tools->len
#define PERC tools->percent
#define CONVCHAR tools->convchar
#define UNINBR tools->uninbr
#define FNBR tools->fnbr
#define NEG tools->neg
#define FLAG tools->flag
#define PW_EXIST tools->pw_exist
#define	LENGTHS	tools->lengths
#define CONVS tools->convs
#define NBR tools->nbr
#define UNBR toolsone->unbr
#define NNBR tools->nnbr
#define F	tools->f
#define RLEN tools->rlen
#define DHASH tools->dhash
#define WPLUS tools->wplus
#define RETLEN	toolsone->retlen
#define D_PERC tools->dperc
#define	STRING tools->string
#define MNBR tools->mnbr
#define ZLEN tools->zlen
#define PERIPREC tools->periprec

typedef struct		s_conv
{
	char		convchar;
 	int		lil_s;
	int		lil_p;
	int		lil_i;
	int		lil_d;
	int		lil_o;
	int		lil_u;
	int		lil_x;
	int		lil_f;
	int		big_x;
	int		lil_c;
	int		single_h;
	int		double_h;
	int		big_l;
	int		single_l;
	int		double_l;
	int 		plus;
	int 		minus;
	int		space;
	int		zero;
	char		convert;
	int 		percent;
	int 		width;
	int 		hash;
	int 		prec;
	int 		len;
	int		uninbr;
	intmax_t	nbr;
	//uintmax_t	unbr;
	int		neg;
	int		flag;
	int		pw_exist;
	int		lengths;
	int		convs;
	//int		unbr;
	int		dperc;
	int		nnbr;
	float		f;
	int		rlen;
	int		dhash;
	int		wplus;
	int		mnbr;
	int		zlen;
	int		periprec;
}			t_conv;

typedef struct		s_convone
{
	int		retlen;
	int		unbr;
}			t_convone;

int			parser(char *str, t_conv *tools, t_convone *toolsone, int i);
void    		ft_doing(t_conv *tools, t_convone *toolsone);
int			ft_printf(const char *format, ...);
int			gather_flags(char *str, int i, t_conv *tools, t_convone *toolsone);
int			gather_prec(char *str, int i, t_conv *tools);
int			gather_length(char *str, int i, t_conv *tools);
int     		gather_strings_character(char *str, int i, t_conv *tools);
int			gather_pointers_hexes(char *str, int i, t_conv *tools);
int			gather_unsigned_octal_floats(char *str, int i, t_conv *tools);
int			gather_decimals_integers(char *str, int i, t_conv *tools);
int			gather_convs(char *str, int i, t_conv *tools);
void    		flags_get_done(t_conv *tools, t_convone *toolsone);
void			minus_flag_done(t_conv *tools, t_convone *toolsone);
void			plus_and_space_flag_done(t_conv *tools, t_convone *toolsone);
void			zero_flag_done(t_conv *tools, t_convone *toolsone);
void    		hash_flag_done(t_conv *tools, t_convone *toolsone);
int			convs_get_done(t_conv *tools, t_convone *toolsone, va_list vl);
int			integers_done(t_conv *tools, t_convone *toolsone, va_list vl);
int			octal_done(t_conv *tools, t_convone *toolsone, va_list vl);
int			strings_done(t_conv *tools, t_convone *toolsone, va_list vl);
int			unsigned_done(t_conv *tools, t_convone *toolsone, va_list vl);
int			uppercase_hex_done(t_conv *tools, t_convone *toolsone, va_list vl);
int			pointers_done(t_conv *tools, t_convone *toolsone, va_list vl);
int			floats_done(t_conv *tools, t_convone *toolsone, va_list vl);
void			zeroing_convs(t_conv *tools);
int			ft_turn_to_positive(t_conv *tools);
void			precision_and_width_get_it(t_conv *tools, t_convone *toolsone);
void			ints_width_and_precision(t_conv *tools, t_convone *toolsone);
void			ints_width_or_precision(t_conv *tools);
int			chars_done(t_conv *tools, t_convone *toolsone, va_list vl);
int			lowercase_hex_done(t_conv *tools, t_convone *toolsone, va_list vl);
char			ft_turn_to_lowercase(char *s1);
char			*ft_uitoa_base2(long long nb, const size_t base);
char			*ft_uitoa_base_pf(uintmax_t value, int base, char x);
char			*ft_ldtoa(double n, int precision);
void			ft_lengths_done(t_conv *tools, va_list vl);
int			ft_len_of_pw(char *str, int i, t_conv *tools);
void			ft_deci_lengths_done(t_conv *tools, va_list vl);
void			ft_octals_hex(t_conv *tools, va_list vl);
void			char_lens(char c, char *s1, t_conv *tools, va_list vl);
void			ft_floats_ls(t_conv *tools, va_list vl);
void			ft_unsigned_len(t_conv *tools, va_list vl);
void			hash_width_and_prec(t_conv *tools, t_convone *toolsone);
void    		hash_width(t_conv *tools, t_convone *toolsone);
void			lilo_hash_width_and_prec(t_conv *tools, t_convone *toolsone);
void			lilx_hash_width_prec(t_conv *tools, t_convone *toolsone);
void			bigx_hash_width_prec(t_conv *tools, t_convone *toolsone);
void			main_width_and_prec(t_conv *tools, t_convone *toolsone);
void			ints_width_and_precision2(t_conv *tools, t_convone *toolsone);
void			ints_prec(t_conv *tools, t_convone *toolsone);
void			char_width(t_conv *tools, t_convone *toolsone);
void			ints_prec_or_width(t_conv *tools, t_convone *toolsone);
int 			gather_doubleperc(char *str, int i, t_conv *tools);
int			double_perc_done(t_conv *tools, t_convone *toolsone);
void 			ft_minus_hash(char *s1, t_conv *tools, t_convone *toolsone);
void			ft_minus_and_plus(char *s1, t_conv *tools, t_convone *toolsone);
void 			minus_width(char *s1, t_conv *tools, t_convone *toolsone);
void 			minus_prec_width(char *s1, t_conv *tools, t_convone *toolsone);
void	ft_minus_string_p_and_w(char *s1, char *s2, t_conv *tools, t_convone *toolsone);
void	ft_minus_string_w(char *s1, t_conv *tools, t_convone *toolsone);
char	*ft_itoa_base2(int value, int base);
char	*ft_uitoa_base3(size_t value, int base);
char	*ft_itoa_base3(intmax_t value, int base);
//char	*ft_itoa_base(intmax_t value, int base);
//char	*ft_uitoa_base3(uintmax_t n, char const *base);
#endif
