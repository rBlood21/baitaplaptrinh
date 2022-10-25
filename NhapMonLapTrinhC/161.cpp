#include <stdio.h>
#include <conio.h>

void kiemTraNhap(int &n)
{
	do
	{
		printf ("Nhap vao so luong phan tu mang phai lon hon 0: ");
		scanf ("%d", &n);
	}while(n < 0);
}
void nhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("a[%d] = ", i);
		scanf ("%d", &a[i]);
	}
}

int timDoan(int a[], int n, int x, int y)
{
	int mang = x;
	for (int i = 0; i < n; i++)
	{
		if ((a[i] >= x && a[i] <= y) || a[i] >= y && a[i] <= x)
		{
			mang = a[i];
			break;
		}
	}
	return mang;
}

int main()
{
	int a[100], n;
	int x, y;
	kiemTraNhap(n);
	nhapMang(a, n);
	scanf ("%d %d", &x, &y);
	int k = timDoan(a, n, x, y);
	if (k == x)
		printf (" khong co so nao nam trong doan x, y");
	else
		printf (" so nam trong doan x, y la: %d", k);
}
