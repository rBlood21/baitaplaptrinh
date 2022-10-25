#include "HeadPhanSo.h"

void nhap(PHANSO a[], int &n)
{
	printf("Nhap vao so luong phan tu cua mang lon hon 0: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		do
		{
			printf("Tu: ");
			scanf("%d", &a[i].tu);
			printf("Mau: ");
			scanf("%d", &a[i].mau);
			if (a[i].mau == 0)
				printf_s("Xin nhap mau so khac 0\n");
		} while (a[i].mau == 0);
		printf("\n");
	}
}

void xuat(PHANSO a[], int n)
{
	printf("Xuat mang:\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d/%d  ", a[i].tu, a[i].mau);
	}
}

int ucln(int a, int b)
{
	int r;
	while (b != 0)
	{
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

PHANSO rutGonPS(PHANSO a)
{
	int k = ucln(a.tu, a.mau);
	PHANSO temp;
	temp.tu = a.tu / k;
	temp.mau = a.mau / k;
	return temp;
}

PHANSO congPhanSo(PHANSO a[], int n)
{
	PHANSO tong;
	tong.tu = a[0].tu;
	tong.mau = a[0].mau;
	for (int i = 1; i < n; i++)
	{
		tong.tu = (tong.tu * a[i].mau) + (tong.mau * a[i].tu);
		tong.mau = tong.mau * a[i].mau;
	}
	return rutGonPS(tong);
}

PHANSO tichPhanSo(PHANSO a[], int n)
{
	PHANSO tich;
	tich.tu = a[0].tu;
	tich.mau = a[0].mau;
	for (int i = 1; i < n; i++)
	{
		tich.tu = tich.tu * a[i].tu;
		tich.mau = tich.mau * a[i].mau;
	}
	return rutGonPS(tich);
}

PHANSO maxPS(PHANSO a[], int n)
{
	PHANSO max = a[0];
	float temp = (float)a[0].tu / a[0].mau;
	for (int i = 0; i < n; i++)
	{
		float k = (float)a[i].tu / a[i].mau;
		if (k > temp)
		{
			temp = k;
			max = a[i];
		}
	}
	return max;
}

PHANSO minPS(PHANSO a[], int n)
{
	PHANSO min = a[0];
	float temp = (float)a[0].tu / a[0].mau;
	for (int i = 0; i < n; i++)
	{
		float k = (float)a[0].tu / a[0].mau;
		if (k < temp)
		{
			temp = k;
			min = a[i];
		}
	}
	return min;
}

void distanceMax(PHANSO a[], int n)
{
	PHANSO k1 = maxPS(a, n);
	PHANSO k2 = minPS(a, n);
	PHANSO temp;
	temp.tu = abs((k1.tu * k2.mau) - (k1.mau * k2.tu));
	temp.mau = abs(k1.mau * k2.mau);
	temp = rutGonPS(temp);
	printf("\nHai so co khoang cach xa nhat la: %d/%d  va  %d/%d", k1.tu, k1.mau, k2.tu, k2.mau);
	printf("\nKhoang cach la: %d/%d", temp.tu, temp.mau);
}