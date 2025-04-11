/*
ho ten: Nguyen Hoang Bao
mssv: 2001240034 - st6
*/
#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>

typedef char Itemtype;
struct StackNode
{
	Itemtype Info;
	StackNode *Next;
};

struct Stack
{
	StackNode *Top;
};

StackNode *createStackNode(Itemtype x)
{
	StackNode *p = new StackNode;
	if (!p)
	{
		printf("Khong du bo nho!");
		_getch();
		return NULL;
	}
	p->Info = x;
	p->Next = NULL;
	return p;
}

void initStack(Stack &s)
{
	s.Top = NULL;
}

int isEmpty(Stack s)
{
	if (s.Top == NULL)
		return 1;
	else
		return 0;
}

int push(Stack &s, StackNode *p)
{
	if (!p)
		return 0;
	if (isEmpty(s))
	{
		s.Top = p;
	}
	else
	{
		p->Next = s.Top;
		s.Top = p;
	}
	return 1;
}

int pop(Stack &s, Itemtype &x)
{
	if (isEmpty(s) == 1)
		return 0;
	StackNode *p = s.Top;
	s.Top = s.Top->Next;
	x = p->Info;
	delete p;
	return 1;
}

void DaoChuoi(char *str)
{
	Stack s;
	StackNode *p;
	initStack(s);
	int i = 0;
	while (str[i] != '\0')
	{
		p = createStackNode(str[i]);
		push(s, p);
		i++;
	}
	while (!isEmpty(s))
	{
		Itemtype ch;
		pop(s, ch);
		printf("%c", ch);
	}
}

int main()
{
	char *str;
	printf("\nNhap vao chuoi");
	gets(str);
	printf("\nChuoi sau khi dao");
	DaoChuoi(str);
}
