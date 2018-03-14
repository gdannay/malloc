#include "../includes/malloc.h"
#include <stdio.h>

int	main()
{
	show_alloc_mem();
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
	d[1] = 'c';
	d[2] = 'a';
	d[2] = 'a';
	d[2] = (char)230;
	e[0] = 'o';
	f[0] = '5';
	a[0] = '0';
	w[0] = 't';
	z[0] = 't';
	o[0] = 'y';
	q[0] = 'i';
	y[0] = 'j';
	f[10001] = 0;
	show_alloc_mem();
	ft_free(q);
	ft_free((char *)e + 1);
	ft_free(o);
	ft_free(w);
	ft_free((char *)a + 1);
	ft_free(e);
	printf("\n\n");
	show_alloc_mem();
	ft_realloc(e, 1005);
	printf("\n\n");
	show_alloc_mem();
	int i;
	i = 0;
	while (++i < 120)
	{
		o = (char *)ft_malloc(259);
	}
	printf("\n\n");
	show_alloc_mem();
}
