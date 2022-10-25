#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX 100

struct Sach
{
	int maSach;
	char tenSach[50];
	float giaSach;
};


void nhapn(int &n)
{
	do
	{
		printf_s("\nMoi nhap so luong phan tu lon hon 0: ");
		scanf_s("%d", &n);
		if (n <= 0 || n > 100)
			printf_s("\nSo luong phan tu khong hop le!");
	} while (n <= 0 || n > 100);

}

void nhap1Sach(Sach &a)
{
	
		printf_s("\nMa sach: ");
		scanf_s("%d", &a.maSach);
		rewind(stdin);
		printf_s("\nten sach: ");
		gets_s(a.tenSach);
		printf_s("\nGia sach: ");
		scanf_s("%f", &a.giaSach);
}

void xuat1Sach(Sach a)
{
	printf_s("\nMa sach: %d", a.maSach);
	printf_s("\nTen sach: ");
	puts(a.tenSach);
	printf_s("Gia sach: %.2f", a.giaSach);
}

void nhapMang(Sach a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf_s("\nCuon sach thu: %d", i+1);
		nhap1Sach(a[i]);
	}
}

void xuatMang(Sach a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf_s("\nCuon sach thu: %d", i + 1);
		xuat1Sach(a[i]);
	}
}

int LinarSearch(Sach a[], int n, int ma)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i].maSach == ma)
			return i;
	}
	return -1;
}

int BinarySearch(Sach a[], int n, int ma)
{
	int left = 0;
	int right = n - 1;
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid].maSach == ma)
			return mid;
		if (a[mid].maSach < ma)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

void xuatSachTenY(Sach a[], int n, char Y[])
{
	for (int i = 0; i < n; i++)
	{
		int kq = strcmp(a[i].tenSach, Y);
		if (kq == 0)
			xuat1Sach(a[i]);
	}
}

float maxGiaSach(Sach a[], int n)
{
	float max = a[0].giaSach;
	for (int i = 1; i < n; i++)
	{
		if (a[i].giaSach > max)
			max = a[i].giaSach;
	}
	return max;
}

void xuatSachGiaCao(Sach a[], int n)
{
	float max = maxGiaSach(a, n);
	for (int i = 0; i < n; i++)
	{
		if (a[i].giaSach == max)
			xuat1Sach(a[i]);
	}	
}

int datLinhCanh(Sach a[], int n, int x)
{
	a[n].maSach = x;
	for (int i = 0;; i++)
	{
		if (a[i].maSach == x)
			return i;
	}
	return -1;
}

int main()
{
	Sach a[MAX];
	int n;
	nhapn(n);
	nhapMang(a, n);
	int x;
	int kq1, kq2;
	char Y[MAX];
	int chon;
	system("cls");
	do
	{
		system("cls");
		printf_s("\n\t\t=============================MENU==================");
		printf_s("\n\t\t\t\t0.Xuat mang");
		printf_s("\n\t\t\t\t1.Tim kiem theo ma sach");
		printf_s("\n\t\t\t\t2.Tim kiem theo ten sach");
		printf_s("\n\t\t\t\t3.Tim sach co gia cao nhat");
		printf_s("\n\t\t===========================******=================");
		
		printf("\n\nNhap vao su lua chon: ");
		scanf_s("%d", &chon);
		switch (chon)
		{
		case 0:
			xuatMang(a, n);
			getchar();
			break;
		case 1:
			
			printf_s("\nNhap vao ma sach can tim: ");
			scanf_s("%d", &x);
			kq1 = LinarSearch(a, n, x);
			if (kq1 == -1)
				printf_s("\nkhong tim thay!");
			else
				printf_s("\nVi tri tim thay cuon sach la: %d", kq1);

			/*kq2 = BinarySearch(a, n, x);
			if (kq2 == -1)
				printf_s("\nkhong tim thay!");
			else
				printf_s("\nVi tri tim thay cuon sach la: %d", kq2);*/
			getchar();
			break;
		case 2:
			
			printf("\nNhap vao ten sach can tim: ");
			rewind(stdin);
			gets_s(Y);
			xuatSachTenY(a, n, Y);
			getchar();
			break;
		case 3:
			printf_s("\nSach co gia cao nhat la:\n");
			xuatSachGiaCao(a, n);
			getchar();
			break;
		}
		getchar();
	} while (chon != 0);
}