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

int kiemTraSNT(int n)
{
	if (n < 2)
		return 0;
	else
	{
		int snt = 1;
		for (int i = 2; i < n; i++)
		{
			if (n % i == 0)
			{
				snt = 0;
				break;
			}
		}
		return snt;
	}
}

int max(int a[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max && kiemTraSNT(a[i]) == 1)
			max = a[i];
	}
	return max;
}

int main ()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = max(a, n);	
	if (k == 0)
		printf ("khong co");
	else
		printf ("snt nho nhat lon hon cac gia tri trong mang la: %d", k);
}
