#include <stdio.h>
#include <conio.h>

void kiemTraNhap(int &n)
{
	do
	{
		printf ("Nhap vao so luong phan tu mang phai lon hon hoac bang 2: ");
		scanf ("%d", &n);
	}while(n < 2);
}
void nhapMang(float a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("a[%d] = ", i);
		scanf ("%f", &a[i]);
	}
}

void ganNhauNhat(float a[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i] || ((a[j] - a[i]) < 0.001))
			{
				printf ("\n%.1f %.1f", a[j], a[i]);
			}
			else
			{
				if (a[i] < a[j] || (a[i] - a[j]) < 0.001)
					printf ("\n%.1f %.1f", a[i], a[j]);
			}
		}
	}
}

int main()
{
	float a[100];
	int n;
	kiemTraNhap(n);
	nhapMang(a, n);
	ganNhauNhat(a, n);
}
