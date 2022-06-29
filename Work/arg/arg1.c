#include <stdio.h>
int main()
{
	int a = 10;
	int sum = 0;

	for	(int i = 1; i <= a; i++)
	{
		sum += i;
	}

	printf(" 합 : %d\n",sum);

	return 0;
}
