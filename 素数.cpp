#include<stdio.h>
int main()
{
	int a, b, c, i;
	scanf("%d", &a);
	int flag = 1;
	if (a <= 1)
	{
		flag = 0;
	}
	for (i = 2; i < a; i++)
	{
		if (a % i == 0)

			flag = 0;
	}
	if (flag)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
	return 0;
}
