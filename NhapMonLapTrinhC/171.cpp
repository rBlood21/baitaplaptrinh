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

int min(int a[], int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}
int timUCLN(int a[], int n)
{
	int t= min(a, n);
	for (int i = t; i >= 0; i--)
	{
		int dem = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j] % i == 0)
				dem += 1;
		}
		if (dem == n)
		{
			return i;
			break;
		}
	}
}

int main()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = timUCLN(a, n);
	printf ("%d", k);
}
