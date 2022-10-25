#include <stdio.h>
#include <conio.h>
int main()
{
	int f1=0, f2=1, f3, n;
	printf ("nhap vao mot so: ");
	scanf ("%d", &n);
	printf ("N so hang dau tien trong day Fibonacci la:\n ");
	printf ("%d %d ", f1, f2);
	for (int i = 2; i < n; i++)
	{
		f3 = f1 + f2;
		printf ("%d ", f3);
		f1 = f2;
		f2 = f3;
	}
	return 0;
}
