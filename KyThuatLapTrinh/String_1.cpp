#include <stdio.h>
#include <string.h>

// In hoa chu cai dau tien cua moi tu

void inHoaDau(char a[])
{
	int n = strlen(a);
	if(a[0] != ' ')
	{
		a[0] = a[0] - 32;
	}
	for (int i = 0; i < n-1; i++)
	{
		if (a[i] == ' ' && a[i+1] != ' ')
		{
			if (a[i+1] >= 'a' && a[i+1] <= 'z')
				a[i+1] = a[i+1] - 32;
		}
	}
}



int main()
{
	char a[500];
	printf ("Nhap vao chuoi: ");
	gets_s(a);
	inHoaDau(a);
	printf ("In hoa dau: %s\n", a);
	getchar();
}

