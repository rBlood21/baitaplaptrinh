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
int kiemtraSNT(int n)
{
	if (n < 2)
		return -1;
	else
	{
		int snt = 1;
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				snt = -1;
				break;
			}
		}
		return snt;
	}
}
int sntCC(int a[], int n)
{
	int snt = -1;
	for (int i = n-1; i >= 0; i--)
	{
		if (kiemtraSNT(a[i]) == 1)
		{
			snt = a[i];
			break;
		}
	}
	return snt;
}
int main ()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = sntCC(a, n);
	if (k == -1)
		printf ("\nMang khong co snt nao");
	else
		printf ("\nsnt cuoi cung la: %d", k);
	return 0;
}
