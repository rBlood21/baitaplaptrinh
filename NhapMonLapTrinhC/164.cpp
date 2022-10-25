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

int kiemtraSoGanh(int n)
{
	int sogoc = n;
	int sodao = 0;
	if (n > 10)
	{
		while (n > 0)
		{
			sodao = (sodao * 10) + (n % 10);
			n = n / 10;
		}
		if (sodao == sogoc)
			return 1;
		return 0;
	}
	else
	return 0;
}

int soGanh(int a[], int n)
{
	int mang = 0;
	for (int i = 0; i < n; i++)
	{
		if (kiemtraSoGanh(a[i])==1)
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
	int k = soGanh(a, n);
	if (k == 0)
		printf ("khong co so ganh nao");
	else
		printf ("so ganh dau tien la: %d", k);
}
