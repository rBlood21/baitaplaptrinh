#include <stdio.h>
#include <string.h>

// dem cac tu trong chuoi
int main()
{
	char a[50];
	printf ("Nhap vao chuoi: ");
	gets_s(a);
	int n = strlen(a);
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if ((a[i] != ' ' && a[i+1] == ' ') || (a[i] != ' ' && a[i+1] == '\0'))
		{
				dem++;
		}
	}
	printf ("Co %d tu", dem);
	getchar();
}