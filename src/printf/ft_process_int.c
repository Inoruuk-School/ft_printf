/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_process_int.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/19 20:17:17 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 18:19:43 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*static	char	*ft_process_int_plus_espace(char *str, uint64_t *flags)
{
	if ((*flags & 0xFF) == 0x8 || (*flags & 0xFF) == 0x10)
	{
		if (((*flags >> 23) & 1) == 1)
		{
			if (!(str = ft_strjoin_free("+", str)))
				ft_error(2);
			*flags &= 0xFFFFFFFFFE7FFFFF;
		}
		if (((*flags >> 24) & 1) == 1)
		{
			if (!(str = ft_strjoin_free(" ", str)))
				ft_error(2);
			*flags &= 0xFFFFFFFFFEFFFFFF;
		}
	}
	return (str);
}

static	char	*ft_process_int_diez(char *str, uint64_t flags)
{
	if (((flags >> 20) & 1) == 1)
	{
		if (((flags >> 5) & 1) == 1 || ((flags >> 6) & 1) == 1)
			if (!(str = ft_strjoin_free("0", str)))
				ft_error(2);
		if (((flags >> 9) & 1) == 1)
			if (!(str = ft_strjoin_free("0x", str)))
				ft_error(2);
		if (((flags >> 10) & 1) == 1)
			if (!(str = ft_strjoin_free("0X", str)))
				ft_error(2);
	}
	return (str);
}

static	char	*ft_process_int_wp(char *str, uint64_t flags)
{
	int		i;

	if (((flags >> 35) & 0xFF) > 0)
	{
		if ((((flags & 0x20) == 0x20 || ((flags & 0x40) == 0x40))) &&\
		(str = ft_process_int_diez(str, flags)))
			flags &= 0xFFFFFFFFFFEFFFFF;
		i = ((flags >> 35) & 0xFF) - ft_strlen(str);
		while (i-- > 0)
			if (!(str = ft_strjoin_free("0", str)))
				ft_error(2);
	}
	str = ft_process_int_diez(str, flags);
	str = ft_process_int_plus_espace(str, &flags);
	if (((flags >> 27) & 0xFF) > 0)
	{
		i = ((flags >> 27) & 0xFF) - ft_strlen(str);
		i > 0 ? str = ft_realloc(str, i + ft_strlen(str)) : (void)i;
		while ((((flags >> 22) & 0x1) == 1) && (i-- > 0))
			str = ft_strcat(str, " ");
		while ((((flags >> 22) & 0x1) == 0) && (i-- > 0))
			if (!(str = ft_strjoin_free(" ", str)))
				ft_error(2);
	}
	return (str);
}

char		*ft_process_int_flags(char *str, uint64_t flags)
{
	int i;

	i = -1;
	if ((*str == '0' && ((flags >> 25) & 0x1) == 1) &&\
	((flags >> 35) & 0xFF) == 0 && (str = ft_realloc(str, 1)))
		*str = '\0';
	if (((flags >> 10) & 1) == 1)
		while (str[++i])
			str[i] = ft_tolower(str[i]);
	str = ft_process_int_wp(str, flags);
	return (str);
}*/

char		*ft_process_int_real(char *str, uint64_t flags, size_t prec,\
								size_t width)
{
	char		*ans;

	width = ((flags >> 27) & 0xFF) - prec - ((flags >> 23) & 1);
	if (((flags & 0xFFF) == 0x20) || ((flags & 0xFFF) == 0x40))
		width -= (flags >> 20) & 1;
	if (((flags & 0xFFF) == 0x200) || ((flags & 0xFFF) == 0x400))
		width -= ((flags >> 20) & 1) * 2;
	ans = ft_strnew(ft_calc_size(ft_strlen(str), flags, (flags & 0xFFF)));
	if (!((flags >> 22) & 1))
		ans = ft_process_width2(ans, " ", width);
	if (((flags >> 24) & 1) && prec && !width && !((flags >> 23) & 1))
		ans = ft_strcat(ans, " ");
	if (!((flags >> 24) & 1) && prec && ((flags >> 23) & 1))
		ans = ft_strcat(ans, "+");
	if (((flags & 0x20) == 0x20 || (flags & 0x40) == 0x40) && (flags >> 20) & 1)
		ans = ft_strcat(ans, "0");
	if (((flags & 0x200) == 0x200 || (flags & 0x400) == 0x400) &&\
		(flags >> 20) & 1)
		ans = ft_strcat(ans, "0X");
	ans = ft_process_prec2(ans, /*((flags >> 35) & 0xFF)*/prec - ft_strlen(str), &flags, NULL);
	ans = ft_strcat(ans, str);
	if ((flags >> 22) & 1)
		ans = ft_process_width2(ans, " ", width);
	free(str);
	return (ans);
}
