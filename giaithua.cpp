/*
ho ten: Nguyen Hoang Bao
mssv: 2001240034 - st6
*/
#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <conio.h>

typedef int Itemtype;
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

int GiaiThua(int n)
{
	Itemtype x;
	int kq = 1;
	StackNode *p;
	Stack s;
	initStack(s);
	while (n > 0)
	{
		p = createStackNode(n);
		push(s, p);
		n--;
	}
	while (!isEmpty(s))
	{
		pop(s, x);
		kq *= x;
	}
	return kq;
}

int main()
{
	int n;
	printf("Nhap vao n:");
	scanf("%d", &n);
	printf("Giai thua cua n la: %d", GiaiThua(n));
	return 0;
}
