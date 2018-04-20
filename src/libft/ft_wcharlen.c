/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wcharlen.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 20:00:02 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 20:00:21 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_wcharlen(const wchar_t c)
{
	size_t ans;

	ans = 0;
	if (c <= 0x7F)
		return (ans + 1);
	else if (c <= 0x7FF)
		return (ans + 2);
	else if (c <= 0xFFFF)
		return (ans + 3);
	else if (c <= 0x10FFFF)
		return (ans + 4);
	return (ans);
}
