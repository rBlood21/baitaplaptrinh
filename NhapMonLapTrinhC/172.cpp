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

int max(int a[], int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

int dem(int a[], int n, int x)
{
	int dem = 0;
	for (int i = 0; i< n; i++)
	{
		if (x % a[i] == 0)
			dem++;
	}
	return dem;
}
int timBCNN(int a[], int n)
{
	int t = max(a, n);
	while(dem(a, n, t) != n)
	{
		t++;
	}
	return t;
}

int main()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = timBCNN(a, n);
	printf ("BCNN cua mang la: %d", k);
	getch();
}
