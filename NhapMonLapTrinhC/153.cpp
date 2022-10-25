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
void nhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("a[%d] = ", i);
		scanf ("%d", &a[i]);
	}
}
int soChanDT(int a[], int n)
{
	int mang = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] %2 == 0)
		{
			mang = a[i];
			break;
		}
	}
	return mang;
}

int sochanNN(int a[], int n)
{
	int min = soChanDT(a, n);
	if (min == 0)
		return 0;
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (a[i] < min && a[i] % 2 ==0)
				min = a[i];
		}
		return min;
	}
}
int main ()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = sochanNN(a, n);
	if (k == 0)
		printf ("\nMang khong co gia tri chan nao");
	else
		printf ("\nGia tri chan nho nhat la: %d", k);
	return 0;
}
