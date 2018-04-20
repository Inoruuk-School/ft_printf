/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/26 14:08:30 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/08 15:37:55 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *var, size_t size)
{
	void	*tmp;

	if (!var)
		return (NULL);
	if(!(tmp = malloc(size)))
		return (NULL);
	ft_memcpy(tmp, var, size);
	free(var);
	return (tmp);
}
