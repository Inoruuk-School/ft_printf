/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstrlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 17:17:22 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 20:07:05 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wstrlen(wchar_t *val)
{
    size_t  len;

    len = 0;
	if (!val)
		len = 6;
	else
	    while (*val)
	    {
	        len = len + ft_wcharlen(*val);
	        val++;
	    }
    return (len);
}
