//_CTR_SUCURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100

void nhapn(int &n)
{
	do
	{
		printf_s("\nMoi nhap so luong phan tu lon hon 0: ");
		scanf_s("%d", &n);
		if (n <= 0 || n > 100)
			printf("\nSo luong phan tu khong hop le!");
	} while (n <= 0 || n > 100);
	
}

void nhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf_s("a[%d] = ", i);
		scanf_s("%d", &a[i]);
	}
}

void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf_s("%4d", a[i]);
	}
}

int LinarSearch(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			return i;
	}
	return -1;
}

int BinarySearch(int a[], int n, int x)
{
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			return mid;
		if (a[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main()
{
	int a[MAX];
	int n;
	nhapn(n);
	nhapMang(a, n);
	xuatMang(a, n);
	int x;
	printf_s("\nNhap vao gia tri can tim: ");
	scanf_s("%d", &x);
	int kq1 = LinarSearch(a, n, x);
	if (kq1 == -1)
		printf_s("\nkhong tim thay!");
	else
		printf_s("\nVi tri tim thay la: %d", kq1);

	int kq2 = BinarySearch(a, n, x);
	if (kq2 == -1)
		printf_s("\nkhong tim thay!");
	else
		printf_s("\nVi tri tim thay la: %d", kq2);
	getchar();
}