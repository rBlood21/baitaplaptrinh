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
float vitriALN (float a[], int n)
{
	float flag = 0;
	float max;
	float vitri = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < 0)
		{
			if (flag == 0)
			{
				max = a[i];
				flag = 1;
				vitri = i;
			}
			else
			{
				if (a[i] > max && a[i] < 0)
				{
					max = a[i];
					vitri = i;
				}
			}
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
	float t = vitriALN(a, n);
	if (t == -1)
		printf ("mang khong co so am nao");
	else
		printf ("Vi tri so am lon nhat trong mang la: %.1f", t);
	return 0;
}
