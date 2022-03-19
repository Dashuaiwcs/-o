#include<stdio.h>

int SU(int a)

{

int  i;

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

return 1;

}

else

{

return 0;

}


}

int main()

{

int q=0,s=0;

q = SU(s);

if (q == 1)

printf("YES");

else

printf("NO");

}
