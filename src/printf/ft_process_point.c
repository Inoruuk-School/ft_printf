/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_process_point.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/11 16:40:04 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 18:20:36 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
/*
static char		*ft_process_pt_width(char *ans, uint64_t flags)
{
	int		i;
	char	c[2];

	i = 0;
	if ((flags & 0x1) == 0x1 || (flags & 0x2) == 0x2)
		c[0] = (((flags >> 21) & 1) == 1 && !((flags >> 22) & 1)) ? '0' : ' ';
	else
		c[0] = ' ';
	c[1] = '\0';
	if (((flags >> 27) & 0xFF) > 0)
	{
		i = ((flags >> 27) & 0xFF) - ft_strlen(ans);
		i > 0 ? ans = ft_realloc(ans, i + ft_strlen(ans)) : (void)i;
		while ((((flags >> 22) & 0x1) == 1) && (i-- > 0))
			ans = ft_strcat(ans, c);
		while ((((flags >> 22) & 0x1) == 0) && (i-- > 0))
			if (!(ans = ft_strjoin_free(c, ans)))
				ft_error(2);
	}
	return (ans);
}

char			*ft_process_pt_prec(char *ans, uint64_t flags)
{
	int		i;

	i = -1;
	if (((flags & 0x1) == 1) && (((flags >> 35) & 0xFF) > 0))
		ans[((flags >> 35) & 0xFF)] = '\0';
	return (ans);
}

char			*ft_process_wcharstring(wchar_t *val, uint64_t flags)
{
	char	*ans;
	int		i;

	i = 0;
	ans = ft_wcharstr(val[0]);
	dprintf(1,"%S\n", val);
	while (*val++ != '\0')
		ans = ft_strjoin_free(ans, ft_wcharstr(*val));
	if (((flags >> 25) & 0x1) == 1)
	{
		i = (flags >> 35) & 0xFF;
		while ((ans[i] & 0x80) == 0x80 && (ans[i - 1] & 0x80) == 0x80 && i > 0)
			i--;
		ans[i] = '\0';
	}
	return (ans);
}
*/


/*
char			*ft_process_point(void *val, uint64_t flags)
{
	char	*ans;
	int		i;

	ans = NULL;
	i = (flags >> 35) & 0xFF;
	if ((flags & 0x4) == 0x4)
	{
		ans = ft_itoa_base((intmax_t)val, 16);
		if (((flags >> 35) & 0xFF) > 0 && (i -= ft_strlen(ans)))
			while (i-- > 0)
				ans = ft_strjoin_free("0", ans);
		ans = ft_process_pt_width(ft_strjoin_free("0x", ans), flags);
	}
	if ((flags & 0x1) == 1 && ((flags & 0x8000) != 0x8000))
	{
		if ((char *)val == NULL)
			ans = ft_strdup("(null)");
		else
			ans = ft_strdup((char *)val);
		ans = ft_process_pt_width(ft_process_pt_prec(ans, flags), flags);
	}
	if (((flags & 0x2) == 2) || ((flags & 0x1) == 1 && ((flags & 0x8000)\
			== 0x8000)))
		ans = ft_process_wcharstring((wchar_t *)val, flags);
	return (ans);
}
*/

char			*ft_process_wcharstring(char *ans, wchar_t *val, uint64_t flags)
{
	int		i;
	char	*tmp;

	i = ft_strlen(ans) + 1;
	tmp = NULL;
	while (*val != '\0')
	{
		tmp = ft_wcharstr(*val);
		ans = ft_strcat(ans, tmp);
		free(tmp);
		val++;
	}
	(void)flags;
	return (ans);
}

char		*ft_process_point(wchar_t *val, uint64_t flags, char *c, int width)
{
	char	*ans;
	int		prec;
	size_t	len;

	prec = (flags >> 35) & 0xFF;
	len = ft_wstrlen(val);
	width = prec > 0 ? width - prec : width - len;
	ans = ft_strnew(ft_calc_size(len, flags, (flags & 0xFFF)));
//	if ((flags & 0x1) == 1 && ((flags & 0x8000) != 0x8000))
//	{
		if (!((flags >> 22) & 1))
			ans = ft_process_width2(ans, c, width);
		if ((char *)val == NULL)
			ans = ft_strcat(ans, "(null)");
		else
//			ans = ft_strcat(ans, ((char *)val));
			ans = ft_process_wcharstring(ans, val, flags);
//		ans = ft_process_prec2(ans, ((flags >> 35) & 0xFF) + width, flags);
//		if (((flags >> 25) & 1) && !((flags >> 22) & 1))
//			ans[width + prec] = '\0';
//		else if (((flags >> 25) & 1) && ((flags >> 22) & 1))
//			ans[prec] = '\0';
//	}
	if ((flags >> 22) & 1)
		ans = ft_process_width2(ans, c, width);
	return (ans);
}
