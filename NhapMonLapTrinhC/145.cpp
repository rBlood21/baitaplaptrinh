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
int kiemtraSHT(int n)
{
	int tong = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
		{
			tong = tong + i;
		}
	}
	if (tong == n)
		return 1;
	return -1;
}
int shtDT(int a[], int n)
{
	int sht = -1;
	for (int i = 0; i < n; i++)
	{
		if (kiemtraSHT(a[i]) == 1)
		{
			sht = a[i];
			break;
		}
	}
	return sht;
}
int main ()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = shtDT(a, n);
	if (k == -1)
		printf ("\nMang khong co sht nao");
	else
		printf ("\nsht dau tien la: %d", k);
	return 0;
}
