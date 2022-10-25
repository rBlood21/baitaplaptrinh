#include <stdio.h>
#include <conio.h>
int main()
{
	int n;
	float tong = 0;
	printf ("Nhap vao mot so: ");
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
			tong = 1;
		else
			tong = tong + 1.0/((i-1)*i);
	}
	printf ("%.1f", tong);
	return 0;
}
