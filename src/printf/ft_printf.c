/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 21:14:34 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 23:14:46 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		ft_search_all(va_list ap, char **str)
{
	uint64_t	flags;
	int			i;
	char		*ans;
	char		*tata;

	flags = 0;
	i = 0;
	tata = ft_strchr(*str, '%');
	ft_find_data_type(&flags, tata);
	ans = ft_process_infos(ap, flags);
	*str = ft_strmod(*str, ans, tata, '%');
	free(ans);
}

static char		*ft_in_printf(va_list ap, const char *format, char *del)
{
	static int		len = 0;
	static char		*str = NULL;

	del = ft_strchr(format, '%');
	if (!*format)
		return (0);
	else if (!del && len == 0)
		str = ft_strdup(format);
	else if (!del && len > 0 && str != NULL && (del = ft_strjoin(str, format)))
	{
		free(str);
		str = del;
		return (str);
	}
	else if (del && del >= format && ++len > 0)
	{
		while (*del != '\0' && (!ft_isalpha(*del) || *del == 'l' ||\
		 	*del == 'h' || *del == 'j' || *del == 'z' || *del == 't'))
				del++;
		str = ft_strnew(++del - format);
		ft_strncpy(str, format, del - format);
		ft_search_all(ap, &str);
	//	str = ft_in_printf(ap, del, NULL);
	}
	return (str);
}

int			ft_printf(const char *format, ...)
{
	size_t		formlen;
	va_list		ap;
	char		*str;

	str = NULL;
	va_start(ap, format);
	str = ft_in_printf(ap, format, str);
	ft_putstr(str);
	formlen = ft_strlen(str);
	free(str);
	va_end(ap);
	return (formlen);
}
