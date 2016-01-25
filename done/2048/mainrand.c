#include <stdio.h>

int main ()
{
	printf ("First number: %d\n", rand() % 7 + 1);
	srand (time(NULL));
	printf ("Random number: %d\n", rand() % 7 + 1);
	srand (1);
	printf ("Again the first number: %d\n", rand() % 7 + 1);

	return 0;
}
