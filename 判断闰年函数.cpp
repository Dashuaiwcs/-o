#include<stdio.h>
//ÅĞ¶ÏÈòÄê 
int run(int n)
{
	if(n%4==0&&n%400!=0||(n%400==0))
	return 1;//ÎªÈòÄê
	else
	return 0;
}
int main()
{
	int a,b;
	b=run(a);
	return 0;
 } 
