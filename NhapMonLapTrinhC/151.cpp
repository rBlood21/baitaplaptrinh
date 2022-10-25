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

int kiemtraSNT (int n)
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
int sntLN(int a[], int n)
{
	int flag = 0;
	int max;
	for (int i = 0; i < n; i++)
	{
		if (kiemtraSNT(a[i])==1)
		{
			if (flag == 0)
			{
				max = a[i];
				flag = 1;
			}	
			else
			{
				if (a[i] > max && kiemtraSNT(a[i])==1)
					max = a[i];
			}
		}
	}
	if (flag == 0)
		return 0;
	return max;
}
int main ()
{
	int a[100], n;
	kiemTraNhap(n);
	nhapMang(a, n);
	int k = sntLN(a, n);
	if (k == 0)
		printf ("\nMang khong co snt nao");
	else
		printf ("\nsnt lon nhat la: %d", k);
	return 0;
}
