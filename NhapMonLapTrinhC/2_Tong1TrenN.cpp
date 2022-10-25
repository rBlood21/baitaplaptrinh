#include <stdio.h>
#include <conio.h>
int main()
{
	float n, tong = 0;
	printf ("Nhap vao mot so: ");
	scanf ("%f", &n);
	for (int i = 1; i <= n; i++)
	{
		tong = tong + 1.0/i;// hoac co the ep kieu float cho i (float)i
	}
	printf ("%.1f", tong);
	return 0;
}
