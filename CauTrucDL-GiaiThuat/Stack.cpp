#include<stdio.h>

struct Node
{
	int info;
	struct Node * next;
};

typedef struct Node * Stack;
void push(Stack &s, int x)
{
	Stack p = new Node;
	p->info = x;
	p->next = s;
	s = p;
}

int pop(Stack &s)
{
	if (s == NULL)
	{
		printf("\nDanh sach dang rong");
		return -1;
	}
	Stack p = s;
	s = s->next;
	int x = p->info;
	delete p;
	return x;
}

void DoiSangNhiPhan(int n, Stack &s)
{
	while (n > 0)
	{
		int du = n % 2;
		push(s, du);
		n = n / 2;
	}
}

//cái này sai r?i, chua hoàn ch?nh, ch? m?i d?i 0 thành 1, 1 thành 0 thoi chua c?ng 1
void DoiSangNhiPhanAm(int n, Stack &s)
{
	if (n < 0)
	{
		n = n*(-1);
		while (n > 0)
		{
			int du = n % 2;
			if (du == 0) du = du + 1;
			else if (du == 1) du = du - 1;
			push(s, du);
			n = n / 2;
		}
	}
}

void xuat(Stack s)
{
	int x = 0;
	while ((x = pop(s)) != -1)
	{
		printf("%d", x);
	}
}

int main()
{
	Stack s = NULL;
	int n;
	printf_s("\nNhap vao so luong phan tu: ");
	scanf_s("%d", &n);
	DoiSangNhiPhanAm(n, s);
	printf_s("\n%d doi sang nhi phan la: ", n);
	xuat(s);
	printf_s("\n");
	getchar();
}