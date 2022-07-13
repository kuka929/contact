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
	Contact con;//ͨѶ¼
	//��ʼ��
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
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
			printf("ѡ�����������ѡ��\n");
			break;
		}
	} while (input);
	printf("�˳�ͨѶ¼\n");
	return 0;
}