/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_processing_infos.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/18 19:27:06 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 18:13:04 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*ft_process_pointer(wchar_t *val, uint64_t flags)
{
	char	*ans;
	char	c[2];

	c[0] = ' ';
	c[1] = '\0';
	if ((flags >> 21) & 1)
		c[0] = '0';
	setlocale(LC_ALL, "");
	ft_process_prec2(NULL, (flags >> 27) & 0xFF, &flags, val);
	dprintf(1,"val:%S\n", val);
	ans = ft_process_point(val, flags, c, (flags >> 27) & 0xFF);
	return (ans);
}

static char		*ft_process_char(wchar_t *val, const uint64_t flags)
{
	char	*ans;

	setlocale(LC_ALL, "");
	if ((wchar_t)val >= 0xD800 && (wchar_t)val <= 0xDFFF)
		return ("^@"); // quoi renvoyer??????????
	ans = ft_processing_char(val, flags);
	return (ans);
}

static char		*ft_process_int(void *val, const uint64_t flags)
{
	char	*ans;

	ans = NULL;
	if (((flags & 0xF) == 0x8) && (((flags >> 13) & 0xFE) == 0))
		ans = ft_itoa_base((int)val, 10);
	else if (((flags & 0xF) == 0x8) && ((flags & 0x2000) == 0x2000))
		ans = ft_itoa_base((short)val, 10);
	else if ((flags & 0xFF) == 0x10 || (((flags & 0xF) == 0x8) &&\
			((flags & 0x8000) == 0x8000)))
		ans = ft_itoa_base((long)val, 10);
	else if (((flags & 0xF) == 0x8) && ((flags & 0x10000) == 0x10000))
		ans = ft_itoa_base((long long)val, 10);
	else if (((flags & 0xF) == 0x8) && ((flags & 0x20000) == 0x20000))
		ans = ft_itoa_base((intmax_t)val, 10);
	else if (((flags & 0xF) == 0x8) && ((flags & 0x40000) == 0x40000))
		ans = ft_itoa_base((ssize_t)val, 10);
	else if (((flags & 0xF) == 0x8) && ((flags & 0x80000) == 0x80000))
		ans = ft_itoa_base((ptrdiff_t)val, 10);
	else if ((flags & 0xF0) == 0x20 || (flags & 0xF0) == 0x40)
		ans = ft_uitoa_base((uintmax_t)val, 8);
	else if ((flags & 0xF0) == 0x80 || (flags & 0xF00) == 0x100)
		ans = ft_uitoa_base((uintmax_t)val, 10);
	else if ((flags & 0xF00) == 0x200 || (flags & 0xF00) == 0x400)
		ans = ft_uitoa_base((uintmax_t)val, 16);
	return (ft_process_int_real(ans, flags, ((flags >> 35) & 0xFF), 0));
}

static void		ft_va_arg(void **val, va_list ap, const uint64_t flags)
{
	wint_t		cha;

	cha = 0;
	if ((flags & 0xF) <= 0x4)
		*val = va_arg(ap, void *);
	else if ((flags & 0xFFF) <= 0x400)
		*val = (void *)va_arg(ap, intmax_t);
	else if ((flags & 0xF00) == 0x800)
	{
		cha = va_arg(ap, wint_t);
		*val = &cha;
	}
}

char			*ft_process_infos(va_list ap, const uint64_t flags)
{
	void		*val;
	char		*ans;

	val = NULL;
	ans = NULL;
	ft_va_arg(&val, ap, flags);
	if (((flags & 0xFFF) > 0x4) && ((flags & 0xFFF) <= 0x400))
	{
		if (!(ans = ft_process_int(val, flags)))
			ft_error(2);
		(((flags >> 9) & 1) == 1) ? ft_str_tolower(ans) : ans;
	}
	else if (((flags & 0xF) <= 0x4) && ((flags & 0xF) > 0))
	{
		if (!(ans = ft_process_pointer((wchar_t *)val, flags)))
			ft_error(2);
	}
	else if (((flags & 0x800) == 0x800))
	{
		if (!(ans = ft_process_char(val, flags)))
			ft_error(2);
	}
	return (ans);
}
