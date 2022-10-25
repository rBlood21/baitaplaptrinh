#include <stdio.h>
#include <conio.h>

// 138 tim mot vi tri chan dau tien trong mang so nguyen.
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
int kiemtraSHT(int n)
{
	int tong = 0;
	for (int i = 1; i < n; i++)
	{
		if (n % i == 0)
			tong = tong + i;
	}
	if (tong == n)
		return 1;
	return 0;
}
int viTriHTCC(int a[], int n)
{
	int vitri = -1;
	//printf ("%d ", n);
	for (int i = n-1; i >= 0; i--)
	{
		//printf ("%d ", a[i]);
		if (kiemtraSHT(a[i]) == 1)
		{
			vitri = i;
			break;
		}
	}
	if (vitri == -1)
		return -1;
	else
		return vitri;
}

int main ()
{
	int a[100];
	int n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = viTriHTCC(a, n);
	if (k == -1)
		printf ("Mang khong co gia tri nao");
	else
		printf ("Vi tri so hoan thien cuoi cung trong mang la: %d", k);
}
