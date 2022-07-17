#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int main(void)
{
	//ft_printf("test char my: %c\n", 'a');
	//ft_printf("test string my: %s\n", "this is my printf!!!");
	//ft_printf("test decimal my: %d\n", 9999);
	//ft_printf("test decimal my: %i\n", -9999);
	//ft_printf("test unsigned decimal my: %u\n", 948384949);
	//ft_printf("test unsigned decimal my: %u\n", -948384949);
	//printf("test unsigned decimal std: %u\n", -948384949);
	//ft_printf("test percent sign my: %%\n");
	// ft_printf("test hex lowercase my: %x\n", 3233423244u);
	// printf("test hex lowercase std: %x\n", 3233423244u);
	// ft_printf("test hex lowercase my: %x\n", 1764232445u);
	// printf("test hex lowercase std: %x\n", 1764232445u);
	//ft_printf("test hex uppercase my: %X\n", 34928739);
	//printf("test hex uppercase std: %X\n", 34928739);
	// printf("%d\n", 15 / 16);
	int a = 40;
	char *str = NULL;
	printf("test print address std: %p\n", str);
	ft_printf("test print address my: %p\n", str);
}
