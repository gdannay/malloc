#include "includes/malloc.h"

int	main()
{
	char *o = (char *)ft_malloc(259);
	char *q = (char *)ft_malloc(1024);
	char *c = (char *)ft_malloc(256);
	char *a = (char *)ft_malloc(25600);
	char *d = (char *)ft_malloc(3);
	char *e = (char *)ft_malloc(1000);
	char *y = (char *)ft_malloc(6);
	char *z = (char *)ft_malloc(1);
	char *f = (char *)ft_malloc(10000);
	char *w = (char *)ft_malloc(257);
	c[0] = 'i';
	c[1] = 'i';
	c[2] = 'l';
	c[254] = 'h';
	d[0] = 'i';
	e[0] = 'o';
	f[0] = '5';
	a[0] = '0';
	w[0] = 't';
	z[0] = 't';
	o[10 * getpagesize() + 1] = 'y';
	q[0] = 'i';
	y[0] = 'j';
	f[10001] = 0;
	printf("TAILLE: block %p\n", o);
	show_alloc_mem();
}
