// sap xep mang phan so tang dan, neu 2 phan so bang nhau thi xet theo mau so
#include <stdio.h>

struct SapXep
{
	int tu;
	int mau;
};

void nhap(SapXep a[], int &n)
{
	printf_s("Nhap vao so luong phan tu cua mang: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf_s("Nhap vao tu va mau so cua a[%d] =\n", i);
		scanf_s("%d %d", &a[i].tu, &a[i].mau);
	}
}

void sapXep(SapXep a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			SapXep pstruoc = a[i];
			SapXep pssau = a[j];
			int temp1 = pstruoc.tu * pssau.mau;
			int temp2 = pstruoc.mau * pssau.tu;
			if (temp1 > temp2)
			{
				//doi
				SapXep d = a[i];
				a[i] = a[j];
				a[j] = d;
			}
			else
			{
				if (temp1 == temp2)
				{
					if (pstruoc.mau > pssau.mau)
					{
						SapXep d = a[i];
						a[i] = a[j];
						a[j] = d;
					}
				}
			}
		}
	}
}

void xuat(SapXep a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf_s("%d/%d   ", a[i].tu, a[i].mau);
	}
}

int main()
{
	SapXep a[100];
	int n;
	nhap(a, n);
	sapXep(a, n);
	xuat(a, n);
	getchar();
}