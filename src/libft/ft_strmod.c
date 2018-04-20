/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmod.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/07 22:53:43 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/14 20:37:14 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmod(char *src, const char *sw, const char *del, char delim)
{
	char	*res;
	char	*str;
	int		intdelim;

	res = (char *)malloc(ft_strlen(src) + ft_strlen(sw) - ft_strlen(del));
	str = ft_strchr(src, delim);
	intdelim = (str - src);
	res = ft_strncpy(res, src, intdelim);
	res = ft_strcat(res, sw);
	if (!ft_strncmp(str, del, ft_strlen(del)))
		str += ft_strlen(del);
	res = ft_strcat(res, str);
	free(src);
	return (res);
}
