#pragma warning(disable:4996)
#include<stdio.h>
#define N 100
struct Stu
{
	char xh[11];
	char xm[12];
	char xb[11];
	int age;
	int banji;
	double cj[4 + 2];
};

typedef struct Stu S;
S s[N];

int n = 0;

//1、添加学生信息
void addStudent()
{
	if (n >= N)
	{
		printf("已满，无法添加");
		return;
	}
	else
	{
		//输入学号
		printf("请输入学号：");
		scanf("%s", s[n].xh);
		//输入姓名
		printf("请输入姓名：");
		scanf("%s", s[n].xm);
		//输入性别
		printf("请输入性别：");
		scanf("%s", s[n].xb);
		//输入年龄
		printf("请输入年龄：");
		scanf("%d", &s[n].age);
		//输入班级
		printf("请输入班级：");
		scanf("%d", &s[n].banji);
		//输入四个成绩
		printf("依次输入四个成绩：");
		scanf("%lf%lf%lf%lf", &s[n].cj[0], &s[n].cj[1], &s[n].cj[2], &s[n].cj[3]);

		s[n].cj[4] = s[n].cj[0] + s[n].cj[1] + s[n].cj[2] + s[n].cj[3];

		s[n].cj[5] = s[n].cj[4] / 4;

		n++;

		printf("添加学生信息成功！\n");

	}
	system("pause");
	system("cls");
}


//菜单
void showMenu()
{
	printf("*****************************\n");
	printf("*****  1、添加学生信息  *****\n");
	printf("*****  2、显示学生信息  *****\n");
	printf("*****  3、修改学生信息  *****\n");
	printf("*****  4、查找学生信息  *****\n");
	printf("*****  5、求平均分      *****\n");
	printf("*****  6、求最高分最低分*****\n");
	printf("*****  7、对总成绩排序  *****\n");
	printf("*****  8、删除学生信息  *****\n");
	printf("*****  9、退出         *****\n");
	printf("*****  10、清空学生信息  *****\n");
	printf("*****************************\n");
}

//输出
void output()
{
	int i, j;
	printf("\n   学号       姓名    性别    年龄    班级   成绩1     成绩2     成绩3     成绩4     总分     平均分\n");
	for (i = 0; i < n; i++)
	{
		printf("%-11s", s[i].xh);
		printf("%7s", s[i].xm);
		printf("%7s", s[i].xb);
		printf("%8d", s[i].age);
		printf("%7d", s[i].banji);
		for (j = 0; j < 6; j++)
			printf("%10.2lf", s[i].cj[j]);
		printf("\n");
	}
	system("pause");
	system("cls");
}

//3、修改学生信息
void modify()
{
	int flag, age, num, i;
	char number[100], sex[10];
	float score1, score2, score3, score4;
	char s1[100];
	int banji;
	printf("请输入需要修改的学生姓名：\n");
	getchar();
	gets(s1);
	while (1)
	{
		flag = 0;
		for (i = 0; i < n; i++)
		{
			if (strcmp(s1, s[i].xm) == 0)
			{
				flag = 1;
				printf("***************************************************\n");
				printf("*----1.修改学号--------  -  -----2.修改性别-------*\n");
				printf("*----3.修改年龄--------  -  -----4.修改班级-------*\n");
				printf("*----5.修改成绩1-------  -  -----6.修改成绩2------*\n");
				printf("*----7.修改成绩3-------  -  -----8.修改成绩4------*\n");
				printf("*-------------------9.退出本菜单------------------*\n");
				printf("***************************************************\n\n");
				printf("请输入菜单编号：\n");
				scanf("%d", &num);
				switch (num)
				{
				case 1:
					printf("请输入新学号：\n");
					getchar();
					gets(number);
					strcpy(s[i].xh, number);
					break;
				case 2:
					printf("请输入性别：\n");
					getchar();
					gets(sex);
					strcpy(s[i].xb, sex);
					break;
				case 3:
					printf("请输入年龄：\n");
					scanf("%d", &age);
					s[i].age = age;
					break;
				case 4:
					printf("请输入班级：\n");
					scanf("%d", &banji);
					s[i].banji = banji;
					break;
				case 5:
					printf("请输入成绩1：\n");
					scanf("%f", &score1);
					s[i].cj[0] = score1;
					break;
				case 6:
					printf("请输入成绩2：\n");
					scanf("%f", &score2);
					s[i].cj[1] = score2;
					break;
				case 7:
					printf("请输入成绩3：\n");
					scanf("%f", &score3);
					s[i].cj[2] = score3;
					break;
				case 8:
					printf("请输入成绩4：\n");
					scanf("%f", &score4);
					s[i].cj[3] = score4;
					break;
				case 9:return;
				default:printf("请输入1--8之间的数字！\n");
				}
				if (num > 0 && num < 8)
					printf("修改成功！\n");
				break;
			}
		}
		if (flag == 0)
		{
			printf("未找到该学生，请重新输入学生姓名：\n");
			gets(s1);
		}
		s[i].cj[4] = s[i].cj[0] + s[i].cj[1] + s[i].cj[2] + s[i].cj[3];

		s[i].cj[5] = s[i].cj[4] / 4;
	}
	system("pause");
	system("cls");
}

//4、查找学生信息
void search()
{
	int number, flag, i;
	char s1[100];
	printf("*****************************\n");
	printf("**-------1.按学号查询------**\n");
	printf("**-------2.按姓名查询------**\n");
	printf("**-------3.退出本菜单------**\n");
	printf("*****************************\n");
	while (1)
	{
		flag = 0;
		printf("请输入要执行的操作序号：\n");
		scanf("%d", &number);
		switch (number)
		{
		case 1:
			printf("请输入需要查找学生的学号：\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
			{
				if (strcmp(s[i].xh, s1) == 0)
				{
					flag = 1;
					printf("\n   学号       姓名    性别    年龄    班级   成绩1     成绩2     成绩3     成绩4     总分     平均分\n");
					printf("%-11s%7s%7s%8d%7d%10.2lf%10.2lf%10.2lf%10.2lf\n", s[i].xh, s[i].xm, s[i].xb, s[i].age, s[i].banji, s[i].cj[0], s[i].cj[1], s[i].cj[2], s[i].cj[3], s[i].cj[4], s[i].cj[5]);
				}
			}break;
		case 2:
			printf("请输入需要查找学生的姓名：\n");
			scanf("%s", s1);
			for (i = 0; i < n; i++)
			{
				if (strcmp(s[i].xm, s1) == 0)
				{
					flag = 1;
					printf("\n   学号       姓名    性别    年龄    班级   成绩1     成绩2     成绩3     成绩4     总分     平均分\n");
					printf("%-11s%7s%7s%8d%7d%10.2lf%10.2lf%10.2lf%10.2lf\n", s[i].xh, s[i].xm, s[i].xb, s[i].age, s[i].banji, s[i].cj[0], s[i].cj[1], s[i].cj[2], s[i].cj[3], s[i].cj[4], s[i].cj[5]);
				}
			}break;
		case 3:return;
		default:printf("请在1--3之间输入！\n");
		}
		if (flag == 0)
			printf("找不到该学生，请重新输入！\n");
	}
}
//5求平均分
void pinjun()
{
	int i, j;
	double one=0, two=0, three=0, four=0, five=0;
	for (i = 0; i < n; i++)
	{
		one = one + s[i].cj[0];
		two=two+ s[i].cj[1];
		three=three+s[i].cj[2];
		four=four+ s[i].cj[3];
		five=five+ s[i].cj[4];
	}
	printf("\n     成绩1平均分     成绩2平均分     成绩3平均分     成绩4平均分     总分平均分");
	printf("\n%10.2lf     %10.2lf      %10.2lf      %10.2lf      %10.2lf",one/n,two/n,three/n,four/n,five/n);

}



//6求最高分最低分

void zuizhi()
{
	int i, j;
	S p = { "0","0","0",0,0,0,0,0,0,0,0, };
	double temp;
	for (i = 0; i < n - 1; i++)
	{

		for (j = 0; j < n - 1 - i; j++)
		{
			if (s[j].cj[4] < s[j + 1].cj[4])
			{

				p = s[j];
				s[j] = s[j + 1];
				s[j + 1] = p;
			}
		}
	}
	j = 0;
	printf("\n   学号       姓名    性别    年龄    班级   成绩1     成绩2     成绩3     成绩4     总分     平均分\n");
	
		printf("%-11s", s[0].xh);
		printf("%7s", s[0].xm);
		printf("%7s", s[0].xb);
		printf("%8d", s[0].age);
		printf("%7d", s[0].banji);
		for (j = 0; j < 6; j++)
			printf("%10.2lf", s[0].cj[j]);
		printf("\n");
		printf("%-11s", s[n-1].xh);
		printf("%7s", s[n - 1].xm);
		printf("%7s", s[n - 1].xb);
		printf("%8d", s[n - 1].age);
		printf("%7d", s[n - 1].banji);
		for (j = 0; j < 6; j++)
			printf("%10.2lf", s[n - 1].cj[j]);
		printf("\n");
	
	system("pause");
	system("cls");
	printf("\n");
	return 0;
}

//7对总成绩排序
void paixu()
{
	int i, j ;
	S p = { "0","0","0",0,0,0,0,0,0,0,0, };
	double temp;
	for (i = 0; i < n - 1; i++)
	{
	
		for (j = 0; j < n - 1 - i; j++)
		{
			if (s[j].cj[4] < s[j + 1].cj[4])
			{

				p = s[j];
				s[j] = s[j + 1];
				s[j + 1] = p;
			}
		}
	}
	j = 0;
	printf("\n   学号       姓名    性别    年龄    班级   成绩1     成绩2     成绩3     成绩4     总分     平均分\n");
	for (i = 0; i < n; i++)
	{
		printf("%-11s", s[i].xh);
		printf("%7s", s[i].xm);
		printf("%7s", s[i].xb);
		printf("%8d", s[i].age);
		printf("%7d", s[i].banji);
		for (j = 0; j < 6; j++)
			printf("%10.2lf", s[i].cj[j]);
		printf("\n");
	}
	system("pause");
	system("cls");
	printf("\n");
	return 0;
}

//8、删除学生信息
void dlt()
{
	int flag, i, j;
	char s1[100];
	printf("请输入要删除学生的姓名：\n");
	getchar();
	gets(s1);
	flag = 0;
	for (i = 0; i < n; i++)
	{
		if (strcmp(s[i].xm, s1) == 0)
		{
			flag = 1;
			for (j = i; j < n - 1; j++)
			{
				s[j] = s[j + 1];
			}
		}
		if (flag == 1) break;
	}
	if (flag == 0) printf("未找到该学生！\n");
	if (flag == 1)
	{
		printf("删除成功！\n");
		n--;
	}
	system("pause");
	system("cls");
}
//10清空学生信息
void cleanstudent()
{
	n = 0;
	printf("您已清空通讯录\n");
	system("pause");
	system("cls");
}

int main()
{
	S abs;
	int select = 0;

	while (1)
	{
		showMenu();
		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			addStudent();
			break;
		case 2:
			output();
			break;
		case 3:
			modify();
			break;
		case 4:
			search();
			break;
		case 5:
			pinjun();
			break;
		case 6:
			zuizhi();
			break;
		case 7:
			paixu();
			break;
		case 8:
			dlt();
			break;
		case 9:
			printf("欢迎再次使用！\n");
			break;
		case 10:
			cleanstudent();
			break;
		dafault:
			break;
		}
	}

	return 0;
}