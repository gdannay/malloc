#include <stdlib.h>
#include <stdio.h>

typedef struct test
{
	int		la;
	struct test	*next;
	int		taille;
}				test;

int	main()
{
	test	*ici;

	ici = (test *)malloc(sizeof(test));
	ici->la = 11;
	ici->next = NULL;
	ici->taille = 42;
	printf("CECI est un test %d %d\n", ici->la, ici->taille);
	*((int *)ici + 2) = 6;
	printf("CECI est un test %d %d\n", ici->la, ici->taille);
	printf("SIZE = %d\n", getpagesize());
}
