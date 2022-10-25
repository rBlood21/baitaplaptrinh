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

float lonHonTru1(float a[], int n)
{
	float mang = 0;
	for (int i = n-1; i >= 0; i--)
	{
		if (a[i] < 0 && a[i] > -1)
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
	float t = lonHonTru1(a, n);
	if (t == 0)
		printf ("mang khong co so nao lon hon -1");
	else
		printf ("so am cuoi cung lon hon -1 la : %.1f",t);
}
