#include <stdio.h>

int main()
{
	int num, i, j;
	int sum = 0;
	printf("num : ");
	scanf("%d", &num);

	for(i = num, j = 1; j <= (num/2 + num % 2) && (i != j) ; i--, j++)
	{
		sum += (i + j);
		printf("%d + %d = %d\n", i, j, sum);
	}

	printf("sum : %d\n", sum);
}
