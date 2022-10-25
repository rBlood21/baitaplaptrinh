#include <stdio.h>
#include <conio.h>

// 137 tim mot vi tri ma tai do gia tri nho nhat trong mang so thuc.
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

int viTriNN(float a[], int n)
{
	int min = a[0];
	int vitri = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
			vitri = i;
		}
	}
		return vitri;
}

int main ()
{
	float a[100];
	int n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = viTriNN(a, n);
	printf ("Vi tri co gia tri nho nhat la: %d", k);
}
