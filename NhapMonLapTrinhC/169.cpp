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

int soLeDT(int a[], int n)
{
	int sole = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 != 0)
		{
			sole = a[i];
		}
	}
	return sole;
}

int soLeNN(int a[], int n)
{
	int min = soLeDT(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min && a[i] % 2 != 0)
			min = a[i];
	}
	return min;
}

int max(int a[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max && a[i] % 2 == 0)
			max = a[i];
	}
	return max;
}

int main ()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = soLeNN(a, n);
	int t = max(a, n);
	if (t < k)
		printf ("So chan lon nhat trong mang nho hon tat ca cac so le la: %d", t);
	else
		printf ("khong co");	
}
