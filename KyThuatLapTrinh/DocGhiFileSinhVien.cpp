//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct SINHVIEN
{
	char hoTen[100];
	unsigned int namSinh;
	char lop[20];
	char mssv[20];
	float diemTB;
	unsigned int nguoiThan;
};

void nhap(SINHVIEN &a)
{
	printf(" \n\t+ Ho va Ten: ");
	fflush(stdin);
	gets(a.hoTen);

	printf("\n\t+ Nam sinh: ");
	fflush(stdin);
	scanf("%d", &a.namSinh);

	printf(" \n\t+ Lop: ");
	fflush(stdin);
	scanf("%s", &a.lop);

	printf("\n\t+ MSSV: ");
	fflush(stdin);
	scanf("%s", &a.mssv);

	printf("\n\t+ Diem trung binh: ");
	scanf("%f", &a.diemTB);

	printf("\n\t+ So luong nguoi than: ");
	scanf("%d", &a.nguoiThan);
}

void xuat(SINHVIEN a)
{
	printf(" \n\tHo va Ten: ");
	printf("%s", a.hoTen);

	printf("\n\tNam sinh: ");
	printf("%d", a.namSinh);

	printf(" \n\tLop: ");
	printf("%s", a.lop);

	printf("\n\tMSSV: ");
	printf("%s", a.mssv);

	printf("\n\tDiem trung binh: ");
	printf("%.1f", a.diemTB);

	printf("\n\tSo luong nguoi than: ");
	printf("%d", a.nguoiThan);
}

void loadFile(SINHVIEN a[], int &n, FILE* doctaptin)
{
	fscanf (doctaptin, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fgets(a[i].hoTen, 100, doctaptin);
		fscanf(doctaptin, "%d\n", &a[i].namSinh);
		fgets(a[i].lop, 20, doctaptin);
		fgets(a[i].mssv, 20, doctaptin);
		fscanf(doctaptin, "%f\n", &a[i].diemTB);
		fscanf(doctaptin, "%d\n", &a[i].nguoiThan);
	}
}

void writeFile(SINHVIEN a[], int &n, FILE* ghitaptin)
{
	fprintf(ghitaptin, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(ghitaptin,"%s\n", a[i].hoTen);
		fprintf(ghitaptin, "%d\n", a[i].namSinh);
		fprintf(ghitaptin, "%s\n", a[i].lop);
		fprintf(ghitaptin, "%s\n", a[i].mssv);
		fprintf(ghitaptin, "%.1f\n", a[i].diemTB);
		fprintf(ghitaptin, "%d\n", a[i].nguoiThan);
	}
}

int main()
{
	SINHVIEN a[1000];
	int n;
	FILE* doctaptin = fopen("DocvaGhiFile_1.txt", "r");
	if (doctaptin != NULL)
	{
		fscanf(doctaptin, "%d\n", &n);
		loadFile(a, n, doctaptin);
		fclose(doctaptin);
	}
	else
	{
		printf ("File khong ton tai, moi nhap vao danh sach sinh vien:\n");
		printf("Nhap vao so luong sinh vien: ");
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			printf("Sinh vien thu %d", i+1);
			nhap(a[i]);
		}
	}
	int chon;
	do
	{
		printf ("\n\t1.Xuat toan bo sinh vien");
		printf ("\n\t2.Thoat khoi chuong trinh va luu lai");
		printf ("\n\t3.Thoat khoi chuong trinh va khong luu");
		printf ("\n\tNhap vao lua chon: ");
		scanf ("%d", &chon);
		system("cls");
		switch(chon)
		{
			case 1:
				for(int i = 0; i < n; i++)
				{
					xuat(a[i]);
				}
				break;
			case 2:
				FILE* ghitaptin = fopen("DocvaGhiFile_1.txt", "w");
				writeFile(a, n, ghitaptin);
				fclose(ghitaptin);
				break;
		}
	}while(chon != 3 && chon != 2);
	getchar();
}
