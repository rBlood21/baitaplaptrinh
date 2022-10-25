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
int viTriChanDT(int a[], int n)
{
	int vitri = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] %2 == 0)
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
	int k = viTriChanDT(a, n);
	if (k == -1)
		printf ("Mang khong co gia tri nao");
	else
		printf ("Vi tri chan dau tien trong mang la: %d", k);
}
