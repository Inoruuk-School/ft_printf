/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_error.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/18 15:59:17 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 19:09:34 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_error(int er)
{
	if (er == 1)
		write(1, "pas de type de conversion de  donne\n", 21);
	if (er == 2)
		write(1, "error malloc\n", 13);
	exit(0);
}

size_t		ft_calc_size(size_t strsize, uint64_t flags, int fla)
{
	size_t		s;
	size_t		width;
	size_t		prec;

	prec = (flags >> 35) & 0xFF;
	width = (flags >> 27) & 0xFF;
	s = 0;
	if (fla == 0x1 || fla == 0x2)
		s = prec < strsize ? prec : strsize;
	else if (fla >= 0x4 && fla <= 0x400)
		s = prec > strsize ? prec : strsize;
	else if (fla == 0x800)
		s = strsize;
	s = width > s ? width : s;
	if ((fla == 0x8 || fla == 0x10) && prec > 0 && !width)
	{
		s = ((flags >> 24) & 0x1) && !((flags >> 25) & 0x1) ? s + 15 : s;
		s = !((flags >> 24) & 0x1) && ((flags >> 25) & 0x1) ? s + 100 : s;
	}
	if (fla == 0x20 || fla == 0x40 || fla == 0x200 || fla == 0x400)
	{
		s = (flags & 0x100000) && fla <= 0x40 ? s + 1 : s;
		s = (flags & 0x100000) && fla > 0x40 ? s + 2 : s;
	}
	return (s);
}

char	*ft_process_width2(char *str, char *c, int width)
{
	if (width > 0)
		while (width-- > 0)
			ft_strcat(str, c);
	return (str);
}

char	*ft_process_prec2(char *str, int i, uint64_t *flags, wchar_t *val)
{
	int j;

	j = 0;
	if (((*flags & 0xFFF) > 0x4) && ((*flags >> 25) & 1))
		while (i-- > 0)
			ft_strcat(str, "0");
	else if (((*flags & 0xFFF) == 0x1) && ((*flags >> 25) & 1))
		str[i] = '\0';
	else if (((*flags & 0xFFF) == 0x2) && ((*flags >> 25) & 1))
	{
//		j = (int)ft_wcharlen(*val);
//		while (*val)
//		{
//			if ((i - j) < 0)
//				*val = '\0';
//			else
//			{
				val++;
//				i--;
//			}
//		}
		*flags &= ((uint64_t)i << 35 | 0xfffffC0effffffff);
		dprintf(1,"%#llx\n", *flags);
	}
	return (str);
}
