#include <stdio.h>
#include <conio.h>

void kiemTraNhap(int &n)
{
	do
	{
		printf_s("Nhap vao so luong phan tu mang phai lon hon 0: ");
		scanf_s("%d", &n);
	} while (n < 0);
}
void nhapMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf_s("a[%d] = ", i);
		scanf_s("%d", &a[i]);
	}
}

void inRaTrungvaSoLan(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		int dem = 0;
		// i va j phai chạy từ 0 nếu không sẽ sai, thử trường hợp số trùng đứng đầu trong mảng sẽ thấy
		for (int j = 0; j < n; j++) 
		{
			if (a[i] == a[j])
			{
				if (i <= j)
				{
					dem++;
				}
				else
				{
					break; 
				}
			}
		}
		if (dem > 1)
		{
			printf("\nGia tri %d co tan suat xuat hien la %d", a[i], dem);
		}
	}
}

int main()
{
	int a[100];
	int n;
	kiemTraNhap(n);
	nhapMang(a, n);
	inRaTrungvaSoLan(a, n);
	getchar();
}