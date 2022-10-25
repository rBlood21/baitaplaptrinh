#include <stdio.h>
#include <conio.h>
int main()
{
	int f1=0, f2=1, f3, n;
	printf ("nhap vao mot so: ");
	scanf ("%d", &n);
	if (n==1)
		printf ("so hang thu %d trong day Fibonacci la 0", n);
	if (n==2)
		printf ("so hang thu %d trong day Fibonacci la 1", n);
	else
	{
		for (int i = 2; i < n; i++)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		printf ("so hang thu %d trong day Fibonacci la: %d", n, f3);
	}
	return 0;
}
