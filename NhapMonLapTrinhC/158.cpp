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

float min(float a[], int n)
{
	float min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] < min)
			min = a[i];
	}
	return min;
}

float max(float a[], int n)
{
	float max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
	}
	return max;
}

int main ()
{
	float a[100];
	int n;
	kiemTraNhap(n);
	nhapMang(a, n);
	float k = min(a, n);
	float t = max(a, n);
	printf ("[%.1f , %.1f]", -t, t);
}
