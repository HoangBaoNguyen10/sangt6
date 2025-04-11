#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <conio.h>

typedef struct Item {
    int SoDia, Nguon, Dich;
} Itemtype;

struct StackNode {
    Itemtype Info;
    StackNode *Next;
};

struct Stack {
    StackNode *Top;
};

// Function to create a new stack node
StackNode* createStackNode(Itemtype x) {
    StackNode *p = new StackNode;
    if (!p) {
        printf("Khong du bo nho!");
        _getch();
        return NULL;
    }
    p->Info = x;
    p->Next = NULL;
    return p;
}

// Function to initialize the stack
void initStack(Stack &s) {
    s.Top = NULL;
}

// Check if the stack is empty
int isEmpty(Stack s) {
    return s.Top == NULL;
}

// Push a new node onto the stack
int push(Stack &s, StackNode *p) {
    if (!p) return 0;
    if (isEmpty(s)) {
        s.Top = p;
    } else {
        p->Next = s.Top;
        s.Top = p;
    }
    return 1;
}

// Pop the top node from the stack
int pop(Stack &s, Itemtype &x) {
    if (isEmpty(s)) return 0;
    StackNode *p = s.Top;
    s.Top = s.Top->Next;
    x = p->Info;
    delete p;
    return 1;
}

// Function to create an Itemtype object with SoDia, Nguon, and Dich
Itemtype saoChepStackNode(int SoDia, int Nguon, int Dich) {
    Itemtype temp;
    temp.SoDia = SoDia;
    temp.Nguon = Nguon;
    temp.Dich = Dich;
    return temp;
}

// Function to solve the Tower of Hanoi using stack
void stack_HaNoiTower(int n, int A, int B, int C) {
    int solan = 0;
    Itemtype x, y;
    StackNode *p;
    Stack s;
    initStack(s);

    y = saoChepStackNode(n, A, C);
    p = createStackNode(y);
    push(s, p);

    while (!isEmpty(s)) {
        pop(s, x);
        if (x.SoDia == 1) {
            printf("\nLan %2d: Chuyen tu cot %d den cot %d", ++solan, x.Nguon, x.Dich);
        } else {
            int temp = 6 - (x.Nguon + x.Dich);
            y = saoChepStackNode(x.SoDia - 1, temp, x.Dich);
            p = createStackNode(y);
            push(s, p);

            y = saoChepStackNode(1, x.Nguon, x.Dich);
            p = createStackNode(y);
            push(s, p);

            y = saoChepStackNode(x.SoDia - 1, x.Nguon, temp);
            p = createStackNode(y);
            push(s, p);
        }
    }
}

// Main function
int main() {
    int n, A, B, C;

    // Input values for n, A, B, and C
    printf("Nhap so dia (n): ");
    scanf("%d", &n);
    printf("Nhap cot nguon (A): ");
    scanf("%d", &A);
    printf("Nhap cot trung gian (B): ");
    scanf("%d", &B);
    printf("Nhap cot dich (C): ");
    scanf("%d", &C);

    // Solve the Tower of Hanoi problem
    stack_HaNoiTower(n, A, B, C);

    return 0;
}
