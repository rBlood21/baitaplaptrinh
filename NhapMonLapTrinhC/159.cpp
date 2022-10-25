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

float lonHon2003(float a[], int n)
{
	float mang = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 2003)
		{
			mang = a[i];
			break;
		}
	}
	return mang;
}

int main()
{
	float a[100];
	int n;
	kiemTraNhap(n);
	nhapMang(a, n);
	float t = lonHon2003(a, n);
	if (t == 0)
		printf ("mang khong co so nao lon hon 2003");
	else
		printf ("so dau tien lon hon 2003 la : %.1f",t);
}
