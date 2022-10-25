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
int giaTriDuongDT(int a[], int n)
{
	int mang = -1;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0)
		{
			mang = a[i];
//			break;
		}
	}
//	if (mang == -1)
//		return -1;
//	else
//		return mang;
		
	return mang;
}

int main ()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = giaTriDuongDT(a, n);
	if (k == -1)
		printf ("\nMang khong co gia tri duong nao");
	else
		printf ("\nGia tri duong dau tien la: %d", k);
	return 0;
}
