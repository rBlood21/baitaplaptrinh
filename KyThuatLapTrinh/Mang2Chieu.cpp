#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>

void ktraNhap(int &dong, int &cot)
{
	do
	{
		printf("Moi nhap so dong va so cot > 0: ");
		scanf("%d %d", &dong, &cot);
		if (dong <= 0 || cot < 0)
			printf("\nBan da nhap sai yeu cau, moi nhap lai");
	} while (dong <= 0 || cot <= 0);
}

void nhapMang2Chieu(int a[][100], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void xuatMang2Chieu(int a[][100], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			printf("%d  ", a[i][j]);
		}
		printf("\n");
	}
}

int tongDuongCheoChinh(int a[][100], int dong, int cot)
{
	for (int i = 0; i < dong; i++)
	{
		for (int j = 0; j < cot; j++)
		{
			if ()
		}
		printf("\n");
	}
}
int main()
{
	int a[100][100];
	int dong, cot;
	ktraNhap(dong, cot);
	nhapMang2Chieu(a, dong, cot);
	printf("\nMang sau khi nhap la:\n");
	xuatMang2Chieu(a, dong, cot);
	getchar();
}