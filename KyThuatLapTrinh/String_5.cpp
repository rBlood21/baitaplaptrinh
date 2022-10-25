#include <stdio.h>
#include <string.h>


int main()
{
	char a[50];  
	printf ("Nhap vao chuoi: ");
	gets_s(a);
	int n = strlen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] != ' ')
			printf ("%c\n",a[i]);
	}
	getchar();
}