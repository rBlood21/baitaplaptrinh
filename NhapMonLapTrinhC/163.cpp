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
void nhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("a[%d] = ", i);
		scanf ("%d", &a[i]);
	}
}

int kiemtraSCP(int n)
{
	int t = (int)sqrt(n);
	if (t * t == n)
		return 1;
	return 0;
}

int scpDT(int a[], int n)
{
	int mang = 0;
	for (int i = 0; i < n; i++)
	{
		if (kiemtraSCP(a[i])==1)
		{
			mang = a[i];
			break;
		}	
	}
	return mang;
}

int main()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = scpDT(a, n);
	if (k == 0)
		printf ("khong co scp nao");
	else
		printf ("scp dau tien la: %d", k);
}
