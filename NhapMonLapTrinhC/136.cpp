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
int soChanCC(int a[], int n)
{
	int mang = -1;
	for (int i = n-1; i >= 0; i--)
	{
		if (a[i] %2 == 0)
		{
			mang = a[i];
			break;
		}
	}
	return mang;
}

int main ()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = soChanCC(a, n);
	if (k == -1)
		printf ("\nMang khong co gia tri chan nao");
	else
		printf ("\n Gia tri chan cuoi cung la: %d", k);
	return 0;
}
