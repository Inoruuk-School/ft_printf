/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 02:27:27 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/01/30 19:05:13 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*s2;

	s2 = (char *)s + ft_strlen(s);
	while (s2 >= s)
	{
		if (*s2 == c)
			return (s2);
		s2--;
	}
	return (0);
}
