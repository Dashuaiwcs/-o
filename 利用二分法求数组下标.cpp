#include<stdio.h>
//���ö��ַ��������±� 
int erfen(int arr[],int k,int sz)//arr��������ָ�룬���ص�������ĸ��ַ
{
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (right + left) / 2;//�м�Ԫ�ص��±꣬������ں������棬��������Ļ�������
		if (arr[mid] < k)
		{
			left = mid + 1;
		
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
			
		}
		else
			return mid;//��ʾ�ҵ����±�
	}
	return 0;
}
int main()
{
	int arr[10] = { 1,3,5,6,11,15,7,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);//���鳤�ȣ�������ܷ��ں������棬��Ϊ����ֻ�ǰ���������ĸ��ַ���ں�������
	int k;
	scanf_s("%d", &k);
	int ret =erfen(arr, k,sz);
	if (ret == -1)
	{
		printf("û���ҵ��±�");
	}
	else
		printf("�±�Ϊ%d", ret);
	return 0;
}
