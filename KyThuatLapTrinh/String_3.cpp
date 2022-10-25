#include <stdio.h>
#include <string.h>

// Nhap vao mot chuoi, xoa het cac ki tu khoang trang trong chuoi
void xoa(char a[], int x)
{
	int n = strlen(a);
	for (int i = x; i < n; i++)
	{
		a[i] = a[i+1];
	}
}
int main()
{
	char a[50];
	printf ("Nhap vao chuoi: ");
	gets_s(a);
	int n = strlen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] == ' ')
		{
			xoa(a,i);
			if (a[i] == ' ')
				i = i - 1;
		}
	}
	puts(a);
	getchar();
}