#include <stdio.h>
#include <conio.h>
int KiemtraSoHoanChinh(int k)
{
	int tong = 1;
	for (int i = 1; i < k; i++)
	{
		if (k % i == 0)
		{
			tong = tong * i;
		}
	}
	return tong;
}
int main()
{
	int n;
	printf (" Nhap vao mot so: ");
	scanf ("%d", &n);
	int kq = KiemtraSoHoanChinh(n);
	if (kq == n)
		printf ("%d la so hoan chinh", n);
	else
		printf ("%d khong la so hoan chinh", n);
	return 0;
}


