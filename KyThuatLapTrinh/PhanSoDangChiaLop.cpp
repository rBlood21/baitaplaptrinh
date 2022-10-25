#include "HeadPhanSo.h"

int main()
{
	PHANSO a[100];
	int n;
	printf("Moi ban nhap mang\n");
	nhap(a, n);
	int option;
	do
	{
		printf("\n\n\t\t\t\t**********************************************************\n");
		printf("\t\t\t\t*  Moi ban lua chon:                                     *\n");
		printf("\t\t\t\t*    1. Xuat mang phan so.                               *\n");
		printf("\t\t\t\t*    2. Cong cac phan so.                                *\n");
		printf("\t\t\t\t*    3. Tich cac phan so.                                *\n");
		printf("\t\t\t\t*    4. Tim max va min cua mang phan so.                 *\n");
		printf("\t\t\t\t*    5. Tim hai so co khoang cach xa nhat trong mang.    *\n");
		printf("\t\t\t\t*    6. Exit.                                            *\n");
		printf("\t\t\t\t**********************************************************\n");
		printf("\t\t\t\tLua chon: ");
		scanf("%d", &option);
		system("cls");
		switch (option)
		{
		case 1:
			xuat(a, n);
			break;
		case 2:
			PHANSO k = congPhanSo(a, n);
			printf("\nTong cac phan so trong mang la: %d/%d", k.tu, k.mau);
			break;
		case 3:
			PHANSO t = tichPhanSo(a, n);
			printf("\nTich cac phan so trong mang la: %d/%d", t.tu, t.mau);
			break;
		case 4:
			PHANSO x = maxPS(a, n);
			printf("\nPhan so lon nhat trong mang la: %d/%d", x.tu, x.mau);
			PHANSO y = minPS(a, n);
			printf("\nPhan so nho nhat trong mang la: %d/%d", y.tu, y.mau);
			break;
		case 5:
			distanceMax(a, n);
			break;
		}
		_getch();
	} while (option != 6);
	getchar();
}