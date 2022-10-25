#include <stdio.h>
#include <string.h>

int main()
{
	char a[50];
	printf("Nhap vao chuoi: ");
	gets_s(a);
	int n = strlen(a);
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] != ' ')
		{
			if (a[i + 1] == ' ')
			{
				printf("%c\n", a[i]);
				break;
			}
			else
				printf("%c", a[i]);
		}
	}
	int index = -1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (a[i] != ' ')
		{
			if (a[i - 1] == ' ')
			{
				index = i;
				break;
			}
		}
	}
	for (int j = index; j < n; j++)
	{
		if (a[j] == ' ')
			break;
		else
			printf("%c", a[j]);
	}
	getchar();
}

