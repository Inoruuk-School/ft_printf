/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 20:37:59 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 18:11:41 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"
# include <wchar.h>
# include <stdlib.h>
# include <stddef.h>
# include <inttypes.h>
# include <locale.h>

# include <stdio.h>

void 		ft_find_data_type(uint64_t *flags, char *str);
char 		*ft_process_infos(va_list ap, const uint64_t flags);
int			ft_printf(const char *format, ...);
void		ft_error(int er);
char 		*ft_process_int_flags(char *str, uint64_t flags);
char		*ft_processing_char(void *val, uint64_t flags);
char 		*ft_process_point(wchar_t *val, uint64_t flags,\
														char *c, int width);
char		*ft_wcharstr(wchar_t c);
size_t		ft_wcharlen(const wchar_t c);
size_t		ft_calc_size(size_t strsize, uint64_t flags, int fla);

char		*ft_process_int_real(char *str, uint64_t flags, size_t prec,\
								size_t width);
char		*ft_process_width2(char *str, char *c, int width);
char		*ft_process_prec2(char *str, int i, uint64_t *flags, wchar_t *val);

# endif
