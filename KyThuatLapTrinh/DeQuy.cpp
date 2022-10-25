#include <stdio.h>

int GiaiThua(int n)
{
	if (n == 0)
		return 1;
	else
	{
		int temp = GiaiThua(n - 1) * n;
		printf("%d\n", GiaiThua(n - 1) * n);

		return temp;
	}
}

int main()
{
	int a = 5;
	int b = 10;
	int k = GiaiThua(a);
	printf("%d", k);
	getchar();
}