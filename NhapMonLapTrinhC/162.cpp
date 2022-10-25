#include <stdio.h>
#include <conio.h>
#include <math.h>

// tim 1 vi tri ma tai do gia tri cua no bang tich 2 gia tri lan can cua no trong mang so thuc.
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

float vitriLanCan(float a[], int n)
{
	int vitri = -1;
	for (int i = 1; i < n-1; i++)
	{
		float temp = a[i+1] * a[i-1];
		if (abs(a[i] - temp)  < 0.001)
		{
			vitri = i;
			break;
		}
	}
	return vitri;
}

int main()
{
	float a[100];
	int n;
	kiemTraNhap(n);
	nhapMang(a, n);
	float k = vitriLanCan(a, n);
	if (k == -1)
		printf (" khong co vi tri nao");
	else
		printf (" vi tri la: %.1f", k);
}
