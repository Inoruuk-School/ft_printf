/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_free.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/22 21:49:50 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/03/22 21:53:09 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char const *s1, char *str_free)
{
	char	*str;

	if (!s1 || !str_free)
		return ((char *)s1);
	if (!(str = ft_strnew(ft_strlen(s1) + ft_strlen(str_free))))
		return (NULL);
	ft_strcpy(str, s1);
	ft_strcat(str, str_free);
	free(str_free);
	return (str);
}
