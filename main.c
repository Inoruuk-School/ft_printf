/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: asiaux <asiaux@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/03/12 21:56:23 by asiaux       #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 01:49:31 by asiaux      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void testd()
{
	int i;
	int j;
	i = ft_printf("moi:%10d\n", 32);
	j = printf("eux:%10d\n", 32);
	printf("mine:%d ---- theirs:%d\n",i , j);


}
void testi()
{
	/*	ft_printf("moi:%- .5i", i);
		printf("i printf:%- .5i\n\n", i);
		ft_printf("moi:%-0 10.5D", i);
		printf("D printf:%-0 10.5D\n\n", i);
		ft_printf("moi:%-0 10.-5u", i);
		printf("u printf:%-0 10.5u\n\n", i);
		ft_printf("moi:%- 10.-5U", i);
		printf("U printf:%- 10.5U\n\n", i);
		ft_printf("moi:%#- 10.o", 0);
		printf("o printf:%#- 10.o\n", 0);
		ft_printf("moi:%- 10.5O", i);
		printf("O printf:%- 10.5O\n", i);
		ft_printf("moi:%- 10.5x", i);
		printf("x printf:%- 10.5x\n", i);
		ft_printf("moi:%- 10.5X", i);
		printf("X printf:%- 10.5X\n", i);
	*/
}



int main(void)
{
//	testd();
//	testi();
	wchar_t * toto= L"tééééto";
	ft_printf("moi:%1.6S\n", toto);
	printf("\ntoi:%1.6S\n", toto);
	return(0);
}
