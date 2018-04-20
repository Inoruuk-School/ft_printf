/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa_base.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/20 19:43:17 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 00:13:20 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void		aux(intmax_t n, int b, char *ans, int *p)
{
	char	base[] = "0123456789ABCDEF";
	int		i;

	if (n <= -b || b <= n)
		aux(n / b, b, ans, p);
	i = (n % b) < 0 ? -(n % b) : (n % b);
	ans[(*p)++] = base[i];
}

char			*ft_uitoa_base(uintmax_t value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
					|| !(ans = (char *)malloc(sizeof(char) * 64)))
		return (NULL);
	p = 0;
	aux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}

char			*ft_itoa_base(intmax_t value, int base)
{
	char	*ans;
	int		p;

	if (base < 2 || 16 < base
		|| !(ans = (char *)malloc(sizeof(char) * 64)))
		return (NULL);
	p = 0;
	if (base == 10 && value < 0)
		ans[p++] = '-';
	aux(value, base, ans, &p);
	ans[p] = '\0';
	return (ans);
}
