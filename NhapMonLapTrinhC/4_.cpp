#include <stdio.h>
#include <conio.h>
int main()
{
	/*int n, temp, tong;
	temp = 1;
	tong = 0;
	printf ("Nhap vao mot so: ");
	scanf ("%d", &n);
	for (int i = 1; i <=n; i++)
	{
			temp = temp * i;
			tong = tong + temp;
	}
	printf ("%d", tong);
	return 0;
	*/
	int n, tong;
	tong = 0;
	printf ("Nhap vao mot so: ");
	scanf ("%d", &n);
	for (int i = 1; i <=n; i++)
	{
		int temp = 1;
		for (int j = 1; j <= i; j++)
		{
			temp = temp * j;
		}
		tong  = tong + temp;
	}
	printf ("%d", tong);
	return 0;
}
