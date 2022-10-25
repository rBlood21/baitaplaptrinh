#include <stdio.h>
#include <string.h>

int soTT = 200;

struct BenhNhan
{
	int stt;
	char hoTen[41];
	int tuoi;
};

typedef BenhNhan bn;
void nhap1BN(bn &a)
{
	a.stt = ++soTT;
	printf_s("\nTen BN: ");
	rewind(stdin);
	gets_s(a.hoTen);
	printf_s("\nTuoi: ");
	scanf_s("%d", &a.tuoi);
}

void xuat1BN(bn a)
{
	printf_s("\nTen BN: %s", a.hoTen);
	printf_s("\nSo thu tu: %d", a.stt);
	printf_s("\nTuoi: %d", a.tuoi);
}

struct Node
{
	bn info;
	struct Node * next;
};

typedef struct Node * Queue;

//chen vo
void EnQueue(Queue &q, bn x)
{
	if (q == NULL)
	{
		q = new Node;
		q->info = x;
		q->next = NULL;
	}
	else
	{
		Queue pTail = q;
		while (pTail->next != NULL)
			pTail = pTail->next;
		pTail->next = new Node;
		pTail->next->info = x;
		pTail->next->next = NULL;
	}
}

//lay ra
bn DeQueue(Queue &q)
{
	if (q == NULL)
	{
		return {-1,"",0};
	}
	Queue p = q;
	q = q->next;
	bn x = p->info;
	delete p;
	return x;
}

void Input(Queue &q)
{
	int n = 3;
	for (int i = 0; i < n; i++)
	{
		bn a;
		nhap1BN(a);
		EnQueue(q, a);
	}
}

void BenhNhanTiepTheo(Queue &q)
{
	bn x = DeQueue(q);
	printf_s("\nThong tin benh nhan tiep theo:\n");
	xuat1BN(x);
}

bn timKiemBN(Queue q, char ten[])
{
	while (q != NULL)
	{
		if (strcmp(q->info.hoTen, ten) == 0)
			return q->info;
		q = q->next;
	}
	return{0,"",0};
}

int main()
{
	Queue q = NULL;
	Input(q);
	bn a;
	printf_s("\nNhap thong tin benh nhan can them:\n");
	nhap1BN(a);
	printf_s("\nSo thu tu benh nhan vua them la: %d", a.stt);
	EnQueue(q, a);
	BenhNhanTiepTheo(q);
	printf("\nSo benh nhan chua duoc kham la: %d", soTT - q->info.stt + 1);
	printf_s("\nSo benh nhan da duoc kham la: %d", q->info.stt - 201);
	char ten[41];
	printf_s("\nNhap ten benh nhan can tim:");
	rewind(stdin);
	gets_s(ten);
	bn kq = timKiemBN(q, ten);
	if(strcmp(kq.hoTen,"") == 0)
		printf("\nKhong tim thay");
	else
	{
		printf_s("\nTim thay");
		xuat1BN(kq);
	}
	getchar();
}