#include <stdio.h>
#include <conio.h>
#include <math.h>

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

float soXaXNhat(float a[], int n, int x)
{
	float kc_max = abs(x - a[0]);
	float giaTri = a[0];
	float vitri = 0;
	for (int i = 1; i < n; i++)
	{
		if (abs(x - a[i]) > kc_max)
		{
			kc_max = abs(x - a[i]);	
			giaTri = a[i];
			vitri = i;
		}	
	}
	return giaTri;
}

int main()
{
	float a[100]; 
	int n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int x;
	scanf ("%d", &x);
	float k = soXaXNhat(a, n, x);
	printf ("so xa X nhat trong mang la: %.1f", k);
}
