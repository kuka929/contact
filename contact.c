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
		printf("ͨѶ¼�������޷����\n");
		return;
	}
	printf("����������:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("�������Ա�:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("����������:>");
	scanf("%d", &pc->data[pc->sz].age);//scanf���룬����ȡ��ַ�����ָ�벻�ǿ�ָ��
	printf("������绰:>");
	scanf("%s", pc->data[pc->sz].tale);
	printf("������סַ:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("��ӳɹ�\n");
}

void PrintContact(const Contact* pc)
{
	//��ӡ����
	int i = 0;
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
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
	return -1;//�Ҳ���
}

void DelContact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("�����ѣ���û����ϵ��\n");
		return;
	}
	//��/û��
	printf("������Ҫɾ���˵�����:>");
	scanf("%s", name);
	//����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
		return;
	}
	int i = 0;
	for (i = pos; i <= pc->sz-1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->sz--;
	printf("ɾ���ɹ�\n");
}

void SearchContact(const Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	if (pc->sz == 0)
	{
		printf("�����ѣ���û����ϵ��\n");
		return;
	}
	printf("������Ҫ�����˵�����:>");
	scanf("%s", name);
	//����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
		return;
	}
	printf("%-10s\t%-5s\t%-5s\t%-15s\t%-20s\n", "����", "�Ա�", "����", "�绰", "סַ");
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
		printf("�����ѣ���û����ϵ��\n");
		return;
	}
	printf("������Ҫ�޸��˵�����:>");
	scanf("%s", name);
	//����
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("���޴���\n");
		return;
	}
	else
	{
		printf("����������:>");
		scanf("%s", pc->data[pos].name);
		printf("�������Ա�:>");
		scanf("%s", pc->data[pos].sex);
		printf("����������:>");
		scanf("%d", &pc->data[pos].age);
		printf("������绰:>");
		scanf("%s", pc->data[pos].tale);
		printf("������סַ:>");
		scanf("%s", pc->data[pos].addr);
		printf("�޸ĳɹ�\n");
	}
}