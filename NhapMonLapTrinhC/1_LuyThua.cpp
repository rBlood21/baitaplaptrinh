#include <stdio.h>
#include <conio.h>
int main()
{
	int n, luythua = 1, tong = 0;
	printf ("Nhap vao mot so: ");
	scanf ("%d", &n);
	for (int i = 0; i <= n; i++)
	{
		luythua = i*i*i;
		tong = tong + luythua;
	}
	printf ("%d", tong);
	return 0;
}
