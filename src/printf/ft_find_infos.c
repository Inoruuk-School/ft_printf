/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_find_infos.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/13 18:26:33 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 22:00:21 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_fill_data_type(uint64_t *flags, char type)
{
	if (type == 's')
		*flags |= 0x1;
	else if (type == 'S')
		*flags |= 0x2;
	else if (type == 'p')
		*flags |= 0x4;
	else if (type == 'd' || type == 'i')
		*flags |= 0x8;
	else if (type == 'D')
		*flags |= 0x10;
	else if (type == 'o')
		*flags |= 0x20;
	else if (type == 'O')
		*flags |= 0x40;
	else if (type == 'u')
		*flags |= 0x80;
	else if (type == 'U')
		*flags |= 0x100;
	else if (type == 'x')
		*flags |= 0x200;
	else if (type == 'X')
		*flags |= 0x400;
	else if (type == 'c' || type == 'C')
		*flags |= 0x800;
}

static void		ft_fill_size_type(uint64_t *flags, char **arg_type)
{
	if (**arg_type == 'h')
		*flags |= 0x2000;
	else if (**arg_type == 'h' && *(*(arg_type) + 1) == 'h')
	{
		*flags |= 0x4000;
		*arg_type = *(arg_type) + 1;
	}
	else if (**arg_type == 'l')
		*flags |= 0x8000;
	else if (**arg_type == 'l' && *(*(arg_type) + 1) == 'l')
	{
		*flags |= 0x10000;
		*arg_type = *(arg_type) + 1;
	}
	else if (**arg_type == 'j')
		*flags |= 0x20000;
	else if (**arg_type == 'z')
		*flags |= 0x40000;
	else if (**arg_type == 't')
		*flags |= 0x80000;
}

static void		ft_fill_spec(uint64_t *flags, char spec)
{
	if (spec == '#')
		*flags |= 0x100000;
	else if (spec == '0')
		*flags |= 0x200000;
	else if (spec == '-')
		*flags |= 0x400000;
	else if (spec == '+')
		*flags |= 0x800000;
	else if (spec == ' ')
		*flags |= 0x1000000;
	else if (spec == '.')
		*flags |= 0x2000000;
}

static void		ft_fill_width_prec(uint64_t *flags, char **str, char *toto)
{
	int		i;
	int		d;

	d = 1;
	if ((i = ft_atoi(*str)) > 255)
	{
		write(1, "prec/width trop grand, remis a max 255\n", 39);
		i = 255;
	}
	if ((((*flags >> 25) & 0x1) == 1))
		while (*(toto + d--) != '.')
		{
			if (*(toto + d) == '-' && (*flags |= (uint64_t)i << 27))
			{
				while (*(*str + 1) >= '0' && *(*str + 1) <= '9')
					*str += 1;
				return ;
			}
		}
	if ((((*flags >> 25) & 0x1) == 1))
		*flags |= (uint64_t)i << 35;
	else
		*flags |= (uint64_t)i << 27;
	while (*(*str + 1) >= '0' && *(*str + 1) <= '9')
		*str += 1;
}

void			ft_find_data_type(uint64_t *flags, char *str)
{
	if (!*str)
		ft_error(1);
	while (*str)
	{
		str++;
		if (*str == '#' || (*str == '0') || *str == '-' || *str == '+' ||\
			*str == ' ' || *str == '.')
			ft_fill_spec(flags, *str);
		if (*str > '0' && *str <= '9')
			ft_fill_width_prec(flags, &str, str);
		if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z' ||\
		*str == 't')
			ft_fill_size_type(flags, &str);
		if/* (*str == 's' || *str == 'S' || *str == 'p' || *str == 'd' ||\
		*str == 'i' || *str == 'D' || *str == 'o' || *str == 'O' ||\
		*str == 'u' || *str == 'U' || *str == 'x' || *str == 'X' ||\
		*str == 'c' || *str == 'C' || *str == '%')*/
			(ft_isalpha(*str) || *str == '%')
		{
			if (*str == '%')
				*flags += 0x1000;
			else
				ft_fill_data_type(flags, *str);
			break ;
		}
	}
	if (((*flags >> 22) & 1) && ((*flags >> 21) & 1))
		*flags &= 0xFFFFFFFFFDFFFFF;

}
