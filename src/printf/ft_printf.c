/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/16 21:14:34 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/06/03 19:50:09 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int     ft_free_list(t_string *list)
{
	int         error;
	t_string    *buff;

	error = 0;
	while (list)
	{
		buff = list;
		list = list->next;
		if (buff->is_malloc)
			free(buff->content);
		if (buff->content_size == -1)
			error = 1;
		free(buff);
	}
	return (error);
}

static char 	*ft_create_buff(t_string *list, int *i)
{
	char 		*str;
	char		*ans;
	t_string	*head;
	int 		j;
	int         buff;

	head = list;
	j = 0;
	*i = 0;
	while (list && list->content_size != -1)
	{
		*i += list->content_size;
		list = list->next;
	}
	list = head;
	if (!(ans = ft_strnew(*i)))
		return (0);
	while (list && list->content_size != -1)
	{
		str = list->content;
		buff = list->content_size;
		while (buff-- > 0)
			ans[j++] = *str++;
		list = list->next;
	}
	return (ans);
}

static int		ft_search_all(va_list ap, char *str, t_string **mnext)
{
	uint64_t flags;
	char *isgud;

	flags = 0;
	isgud = ft_find_data_type(&flags, str);
	if (isgud) {
		flags |= 0x1;
		(*mnext)->next = p_pointer((wchar_t *) isgud, flags);
	} else
		(*mnext)->next = p_infos(ap, flags);
	if ((*mnext)->next->content_size == -1)
	{
		(*mnext)->content_size = -1;
		return (0);
	}
	*mnext = (*mnext)->next;
	return (1);
}

static int		ft_in_printf(va_list ap, const char *format, char *del,\
								t_string **mnext)
{
	if (!*format)
		return (0);
	return (ft_search_all(ap, del, mnext));
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_string	*string_list;
	t_string	*head;
	char		*str;
	int			i;

	if ((str = ft_strchr(format, '%')))
		string_list = ft_newlist((char *)format, str - format, 0);
	else
		string_list = ft_newlist((char *)format, ft_strlen(format), 0);
	head = string_list;
	va_start(ap, format);
	while (str)
	{
		i = 0;
		if (!ft_in_printf(ap, format, str, &string_list))
			break;
		format = ++str;
		while (format[i] != '\0' && (is_parse(format[i])))
			i++;
		if (!is_type(format[i]) && ft_isprint(format[i]))
			i = 0;
		format = format[i] != '\0' ? &format[i] + 1 : &format[i];
		if ((str = ft_strchr(format, '%')))
			string_list->next = ft_newlist((char *)format, str - format, 0);
		else
			string_list->next = ft_newlist((char *)format, ft_strlen(format), 0);
		string_list = string_list->next;
	}
	str = ft_create_buff(head, &i);
	write(1, str, i);
	va_end(ap);
	return (ft_free_list(head) ? -1 : i);
}