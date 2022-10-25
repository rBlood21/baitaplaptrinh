#include <stdio.h>
#include <conio.h>
int KiemtraSoHoanThien(int k)
{
	int tong = 0;
	for (int i = 1; i < k; i++)
	{
		if (k % i == 0)
		{
			tong = tong + i;
		}
	}
	return tong;
}
int main()
{
	int n;
	printf (" Nhap vao mot so: ");
	scanf ("%d", &n);
	int kq = KiemtraSoHoanThien(n);
	if (kq == n)
		printf ("%d la so hoan thien", n);
	else
		printf ("%d khong la so hoan thien", n);
	return 0;
}


