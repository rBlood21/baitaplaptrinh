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

int daoSo(int n)
{
	int sodao = 0;
	while (n > 0)
	{
		sodao = (sodao * 10) + (n % 10);
		n = n / 10;
	}
	return sodao;
}

int chuSoLe(int a[], int n)
{
	int mang = 0;
	for (int i = 0; i < n; i++)
	{
		if ((daoSo(a[i])%10)%2!=0)
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
	int k = chuSoLe(a, n);
	if (k == 0)
		printf ("khong co gia tri nao");
	else
		printf ("gia tri dau tien co chu so le la: %d", k);
}
