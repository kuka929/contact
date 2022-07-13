#define _CRT_SECURE_NO_WARNINGS 1

#include"contact.h"

void InitContact(Contact* pc)
{
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(Contact* pc)
{
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[pc->sz].age);//scanf输入，忘记取地址，结果指针不是空指针
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tale);
	printf("请输入住址:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("添加成功\n");
}

void PrintContact(const Contact* pc)
{
	//打印标题
	int i = 0;
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-20s\n", "名字", "性别", "年龄", "电话", "住址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5s\t%-5d\t%-15s\t%-20s\n",
			pc->data[i].name,
			pc->data[i].sex,
			pc->data[i].age,
			pc->data[i].tale,
			pc->data[i].addr);
	}
}

static int FindByName(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;//找不到
}

void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("快醒醒，你没有联系人\n");
		return;
	}
	//有/没有
	printf("请输入要删除人的名字:>");
	scanf("%s", name);
	//查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
		return;
	}
	int i = 0;
	for (i = pos; i <= pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("删除成功\n");
}

void SearchContact(const Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("快醒醒，你没有联系人\n");
		return;
	}
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	//查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-20s\n", "名字", "性别", "年龄", "电话", "住址");
	printf("%-10s\t%-5s\t%-5d\t%-15s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].sex,
			pc->data[pos].age,
			pc->data[pos].tale,
			pc->data[pos].addr);
}

void ModifyContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("快醒醒，你没有联系人\n");
		return;
	}
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	//查找
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
		return;
	}
	else
	{
		printf("请输入姓名:>");
		scanf("%s", pc->data[pos].name);
		printf("请输入性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入年龄:>");
		scanf("%d", &pc->data[pos].age);
		printf("请输入电话:>");
		scanf("%s", pc->data[pos].tale);
		printf("请输入住址:>");
		scanf("%s", pc->data[pos].addr);
		printf("修改成功\n");
	}
}