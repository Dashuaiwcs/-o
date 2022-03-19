#include<stdio.h> 
int su(int n)
{
	int i;
	for(i=2;i<n;i++)
	{
		if(n%i==0)
		return 0;
	}
	return 1;//ÎªËØÊý 
}
int main()
{
	int a,b;
	b=su(a);
	return 0;
 } 
