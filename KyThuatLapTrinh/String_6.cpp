#include <stdio.h>
#include <string.h>
 
// Nhap vao mot chuoi, xuat ra cac tu tren cac dong lien tiep
int main()
{
	char a[50];
	printf("Nhap vao chuoi: ");
	gets_s(a);
	int n = strlen(a);
	for (int i = 0; i < n; i++)
	{
		if (a[i] != ' ')
		{
			if (a[i + 1] == ' ')
				printf("%c\n", a[i]);
			else
				printf("%c", a[i]);
		}
	}
	getchar();
}