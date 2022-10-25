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
void nhapMang(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("a[%d] = ", i);
		scanf ("%f", &a[i]);
	}
}
float soDuongCC(float a[], int n)
{
	float mang = -1;
	for (int i = n-1; i >= 0; i--)
	{
		if (a[i] > 0)
		{
			mang = a[i];
			break;
		}
	}
	return mang;
}

int main()
{
	float a[100];
	int n;
	kiemTraNhap(n);
	nhapMang(a, n);
	float k = soDuongCC(a, n);
	if (k == -1)
		printf ("\nMang khong co so duong nao");
	else
		printf ("\nSo duong cuoi cung la: %.1f", k);
	return 0;
}
