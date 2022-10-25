#include <stdio.h>
#include <conio.h>
#include <string.h>

// xoa khoang trang thua trong chuoi

void xoa(char a[])
{
	int n = strlen(a);
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i + 1];
	}
}

void xoaVT(char a[], int x)
{
	int n = strlen(a);
	for (int i = x; i < n; i++)
	{
		a[i] = a[i + 1];
	}
}
int main()
{
	char a[50];
	printf("Nhap vao chuoi: ");
	gets_s(a);
	int n = strlen(a);
	//xoa khoang trang dau
	while (a[0] == ' ')
	{
		xoa(a);
	}
	// xoa khoang trang cuoi
	while (a[n - 1] == ' ')
	{
		a[n - 1] = a[n];
		n = strlen(a);
	}
	//xoa khoang trang giua
	if (a[0] != ' ')
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] == ' ' && a[i + 1] == ' ')
			{
				xoaVT(a, i);
				if (a[i] == ' ')// nếu trường hợp có nhiều hơn 1 khoảng trắng ở giữa
					i--;
			}
		}
	}
	printf_s("%s", a);
	getchar();
}