#include <stdio.h>
#include <conio.h>
#include <math.h>

void kiemTraNhap(int &n)
{
	do
	{
		printf ("Nhap vao so luong phan tu mang phai lon hon hoac bang 2: ");
		scanf ("%d", &n);
	}while(n < 2);
}
void nhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("a[%d] = ", i);
		scanf ("%d", &a[i]);
	}
}

void ganNhauNhat(int a[], int n, int &x, int &y)
{
	x = a[0];
	y = a[1];
	int min = abs(a[1] - a[0]);
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (abs(a[j] - a[i]) < min)
			{
				min = abs(a[j] - a[i]);
				x = a[i];
				y = a[j];
			}
		}
	}
}

int main()
{
	int a[100], n, x, y;
	kiemTraNhap(n);
	nhapMang(a, n);
	ganNhauNhat(a, n);
	printf ("%d %d", x, y);
}
