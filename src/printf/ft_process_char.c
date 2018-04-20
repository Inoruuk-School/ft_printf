/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_process_char.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 14:40:21 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 00:55:14 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*
static char		*ft_process_width(char *str, uint64_t flags)
{
	char	c;
	int		i;

	c = ' ';
	i = ((flags >> 27) & 0xFF) - ft_strlen(str);
	if (((flags >> 21) & 1) == 1 && ((flags >> 22) & 0x1) == 0)
		c = '0';
	while ((((flags >> 22) & 0x1) == 0) && (i-- > 0))
		if (!(str = ft_strjoin_free(&c, str)))
			ft_error(2);
	if (((flags >> 22) & 0x1) == 1 && i > 0)
	{
		str = ft_realloc(str, i + ft_strlen(str));
		while (i-- > 0)
			str = ft_strcat(str, &c);
	}
	return (str);
}*/

char			*ft_wcharstr(wchar_t c)
{
	char	*str;

	str = ft_strnew(ft_wcharlen(c));
	if (c <= 0x7F)
		str[0] = c;
	else if (c <= 0x7FF)
	{
		str[0] = ((c >> 6) | 0xC0);
		str[1] = ((c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		str[0] = ((c >> 12) | 0xE0);
		str[1] = (((c >> 6) & 0x3F) | 0x80);
		str[2] = ((c & 0x3F) | 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		str[0] = ((c >> 18) | 0xF0);
		str[1] = (((c >> 12) & 0x3F) | 0x80);
		str[2] = (((c >> 6) & 0x3F) | 0x80);
		str[3] = ((c & 0x3F) | 0x80);
	}
	return (str);
}

char			*ft_processing_char(void *val, uint64_t flags)
{
	char	*ans;
	char	*str;
	char	c[2];

	c[0] = ' ';
	c[1] = '\0';
	if ((flags >> 21) & 1)
		c[0] = '0';
	str = ft_wcharstr((wchar_t)val);
	ans = ft_strnew(ft_calc_size(ft_strlen(str), flags, (flags & 0xFFF)));
	if (!((flags >> 22) & 1))
		ans = ft_process_width2(ans, c, (flags >> 27) & 0xFF);
	ans = ft_strcat(ans, str);
	if ((flags >> 22) & 1)
		ans = ft_process_width2(ans, c, (flags >> 27) & 0xFF);
	free(str);
	return (ans);
}
