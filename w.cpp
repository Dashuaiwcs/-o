#include<stdio.h> 
#include<math.h>
void Fun(int x)
{
	int i,flag=1,k;
	if(x>1)
	{
		k=sqrt(x);
		for(i=2;i<=k;i++)
		{
			if(x%i==0)
			{
				flag=0;break;
			}
		}
		if(flag)
		printf("%d������\n",x);
		else
		printf("%d��������\n",x);
	}
	else
		printf("%d��������",x); 
}
int main()
{
	int a; 
	printf("������һ������\n");
	scanf("%d",&a);
	Fun(a);
	return 0;
}

