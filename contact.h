#pragma once

#include<stdio.h>
#include<string.h>

#define MAX_NAME 10
#define MAX_SEX 5
#define MAX_TALE 12
#define MAX_ADDR 30

#define MAX 1000

typedef struct PeoInfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char tale[MAX_TALE];
	char addr[MAX_ADDR];
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;//当前通讯录里面有多少人
}Contact;

void InitContact(Contact* pc);

void AddContact(Contact* pc);

void PrintContact(const Contact* pc);

void DelContact(Contact* pc);

void SearchContact(const Contact* pc);

void ModifyContact(Contact* pc);