#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void menu()
{
	printf("*******************************************\n");
	printf("*****  1.add            2.del         *****\n");
	printf("*****  3.search         4.modify      *****\n");
	printf("*****  5.sort           6,print       *****\n");
	printf("*****          0,exit                 *****\n");
	printf("*******************************************\n");
}

enum Option
{
	exit,
	add,
	del,
	search,
	modify,
	sort,
	print
};

int main()
{
	int input = 0;
	Contact con;//通讯录
	//初始化
	InitContact(&con);
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			AddContact(&con);
			break;
		case del:
			DelContact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case sort:
			break;
		case print:
			PrintContact(&con);
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	printf("退出通讯录\n");
	return 0;
}