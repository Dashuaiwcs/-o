#include<stdio.h>
//利用二分法求数组下标 
int erfen(int arr[],int k,int sz)//arr本质上是指针，返回的是首字母地址
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (right + left) / 2;//中间元素的下标，必须放在函数里面，放在外面的话不可以
		if (arr[mid] < k)
		{
			left = mid + 1;
		
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
			
		}
		else
			return mid;//表示找到了下标
	}
	return 0;
}
int main()
{
	int arr[10] = { 1,3,5,6,11,15,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);//数组长度，这个不能放在函数里面，因为仅仅只是把数组首字母地址放在函数里面
	int k;
	scanf_s("%d", &k);
	int ret =erfen(arr, k,sz);
	if (ret == -1)
	{
		printf("没有找到下标");
	}
	else
		printf("下标为%d", ret);
	return 0;
}
