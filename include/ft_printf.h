/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alngo <alngo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 10:58:16 by alngo             #+#    #+#             */
/*   Updated: 2019/12/17 20:13:06 by alngo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

typedef enum			e_printf_flags
{
	FSP = 0x01,
	FPL = 0x02,
	FMI = 0x04,
	FNO = 0x08,
	FZE = 0x10,
	FPR = 0x20
}						t_printf_flags;

typedef enum			e_printf_types
{
	TL = 0x01,
	TLL = 0x02,
	TH = 0x04,
	THH = 0x08,
	TJ = 0x10,
	TZ = 0x32
}						t_printf_types;

typedef	enum			e_unicode_mask
{
	ENCODE_07BITS = 0x0,
	ENCODE_11BITS = 0xC080,
	ENCODE_16BITS = 0xE08080,
	ENCODE_21BITS = 0xF0808080
}						t_unicode_mask;

/*
** Printf colors
*/
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define NOCOLOR "\033[0m"
# define COLOR_LENGTH 10
# define NOCOLOR_LENGTH 7

typedef struct			s_args
{
	unsigned int		width;
	unsigned int		precision;
	unsigned short		flags;
	unsigned short		type;
}						t_args;

/*
**	PROTOTYPES
*/
int						ft_printf(const char *fmt, ...);
int						xprintf(void (*pf)(char), const char *fmt, va_list ap);
void					formatter(void (*outc)(char), const char **fmt,\
		t_args *args, va_list va);

void					get_flags(const char **fmt, t_args *args);
void					get_type(const char **fmt, t_args *args);
void					get_width(const char **fmt, t_args *args, va_list va);
void					get_precision(const char **fmt, t_args *args,\
		va_list va);

void					format_color(void (*outc)(char), const char **fmt);
void					format_character(void (*outc)(char), const char **fmt,\
		t_args *args, va_list va);
void					format_pointer(void (*outc)(char), const char **fmt,\
		t_args *args, va_list va);
void					format_string(void (*outc)(char), const char **fmt,\
		t_args *args, va_list va);
void					format_integer(void (*outc)(char), const char **fmt,\
		t_args *args, va_list va);

void					pad(void (*outc)(char), size_t len, char c);
void					format_out(void (*outc)(char), const char *buf,\
		t_args *args, char c);
void					error_out(void (*outc)(char), char c);
void					buffer_out(void (*outc)(char), const char *buf,\
		size_t size);

#endif
