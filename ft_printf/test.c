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
	ft_printf("test hex lowercase my: %x\n", 1735929054u);
	printf("test hex lowercase std: %x\n", 1735929054u);
	//ft_printf("test hex uppercase my: %X\n", 34928739);
	//printf("test hex uppercase std: %X\n", 34928739);
}
