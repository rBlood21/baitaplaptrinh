//Danh sách liên kết
#include <stdio.h>

struct Node
{
	int info;
	struct Node * next;
};

typedef Node * NodePt;

NodePt CreateNode(int x)
{
	NodePt p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}

void AddTail(NodePt &phead, int x)
{
	NodePt p = CreateNode(x);
	if(phead == NULL)
		phead = p;
	else
	{
		NodePt pTail = phead;
		while(pTail->next != NULL)
			pTail = pTail->next;
		pTail->next = p;
	}
}

void Input(NodePt &phead)
{
	int n;
	printf("\nNhap vao so luong phan tu: ");
	scanf_s("%d", &n);
	int x;
	for(int i = 0; i < n; i++)
	{
		printf("a[%d] = ", i);
		scanf_s("%d", &x);
		AddTail(phead, x);
	}
}

void ShowList(NodePt phead)
{
	NodePt p = phead;
	if(p == NULL)
		printf("\nMang rong!");
	else
	{
		while(p != NULL)
		{
			printf("%4d", p->info);
			p = p->next;
		}
	}
}

int TimMax(NodePt phead)
{
	int max = phead->info;
	NodePt p = phead;
	while(p != NULL)
	{
		if(p->info > max)
			max = p->info;
		p = p->next;
	}
	return max;
}

int TimMin(NodePt phead)
{
	int min = phead->info;
	NodePt p = phead;

	while(p != NULL)
	{
		if(p->info < min)
			min = p->info;
		p = p->next;
	}
	return min;
}

void Swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}

void SapXep(NodePt phead)
{
	for(NodePt p = phead; p->next != NULL; p = p->next)
	{
		for(NodePt q = p->next; q != NULL; q = q->next)
		{
			if(p->info > q->info)
				Swap(p->info, q->info);
		}
	}
}

void DeleteFirst(NodePt &phead)
{
	NodePt p;
	p = phead;
	phead = phead->next;
	delete p;
}

void DeleteAfter(NodePt p)
{
	NodePt q;
	if(p == NULL || p->next == NULL)
		printf("\nKhong the xoa!");
	else
	{
		q = p->next;
		p->next = q->next;
		delete q;
	}
}

//xoa 1 gia tri
void Delete_X(NodePt &phead, int x)
{
	if(phead->info == x)
		DeleteFirst(phead);
	else
	{
		NodePt p = phead;
		while(p->next != NULL)
		{
			if(p->next->info == x)
				DeleteAfter(p);
			p = p->next;
		}	
	}
}

//xóa tất cả các giá trị là X
void Delete_All_X(NodePt &phead, int x)
{
	while(phead->info == x)
		DeleteFirst(phead);
	for(NodePt p = phead; p->next != NULL;)
	{
			if(p->next->info == x)
				DeleteAfter(p);
			else
				p = p->next;
	}
}

bool KiemTraSNT(int x)
{
	if(x < 2)
		return false;
	for(int i = 2; i < x; i++)
	{
		if(x % i == 0)
			return false;
	}
	return true;
}

//xóa tất cả các giá trị là số nguyên tố
void Delete_All_SNT(NodePt &phead)
{
	while(KiemTraSNT(phead->info) == true)
		DeleteFirst(phead);
	for(NodePt p = phead; p->next != NULL;)
	{
			if(KiemTraSNT(p->next->info) == true)
				DeleteAfter(p);
			else
				p = p->next;
	}
}

int main()
{
	NodePt phead = NULL;
	Input(phead);
	ShowList(phead);
	int max = TimMax(phead);
	printf("\nSo lon nhat trong mang la: %d", max);
	int min = TimMin(phead);
	printf("\nSo nho nhat trong mang la: %d", min);
	/*printf("\nMang sau khi sap xep la:\n");
	SapXep(phead);
	ShowList(phead);*/
	int x;
	printf("\nNhap vao gia tri can xoa: ");
	scanf("%d", &x);
	Delete_X(phead, x);
	printf("\nSau khi xoa cac so x la:\n");
	ShowList(phead);
	Delete_All_X(phead, 1);
	printf("\nSau khi xoa cac so 1 la:\n");
	ShowList(phead);
	Delete_All_SNT(phead);
	printf("\nSau khi xoa cac so nguyen to la:\n");
	ShowList(phead);
	getchar();
}