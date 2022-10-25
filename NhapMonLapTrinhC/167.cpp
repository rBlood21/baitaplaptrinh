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

int kiemTraToanSoLe(int n)
{
	int temp = 1;
	int t;
	while(n != 0)
	{
		t = n % 10;
		if (t % 2 == 0)
		{
			temp = 0;
			break;
		}
		else
			n = n / 10;
	}
	return temp;
}

int max(int a[], int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max && kiemTraToanSoLe(a[i]) == 1)
			max = a[i];
	}
	return max;
}

int main()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = max(a, n);
	if (k == 0)
		printf ("mang khong co so nao hop yeu cau");
	else
		printf ("so lon nhat trong mang va toan so le la: %d", k);
}


