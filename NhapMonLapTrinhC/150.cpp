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
int soAmDT(int a[], int n)
{
	int soam = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			soam = a[i];
			break;
		}
	}
	return soam;
}
int soamLN(int a[], int n)
{
	int max = soAmDT(a, n);
	if (max == 0)
		return 0;
	else
	{
		for (int i = 0; i < n; i++)
		{
			if(a[i] > max && a[i] < 0)
			{
				max = a[i];
			}
		}
		return max;
	}
}
int main ()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = soamLN(a, n);
	if (k == 0)
		printf ("\nMang khong co so am nao");
	else
		printf ("\nso am lon nhat la: %d", k);
	return 0;
}
