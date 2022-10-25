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

int layRaPTDuyNhat(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			return 1;
	}
	return 0;
}

void tachPTDuyNhat(int a[], int n, int b[], int &nb)
{
	nb = 0;
	for (int i = 0; i < n; i++)
	{
		if (layRaPTDuyNhat(b, nb, a[i]) == 0)
		{
			b[nb] = a[i];
			nb++;
		}
	}
}

int demTrung(int a[], int n, int x)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
			dem++;
	}
	return dem;
}

void demXuatHien(int a[], int n, int b[], int nb
{
	for (int i = 0; i < nb; i++)
	{
		int k = demTrung(a, n, b[i]);
		
		if (k == 1)
			printf ("\n%d", b[i]);
	}
}

int main()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int b[100], nb;
	tachPTDuyNhat(a, n, b, nb);
	demXuatHien(a, n, b, nb);
}
