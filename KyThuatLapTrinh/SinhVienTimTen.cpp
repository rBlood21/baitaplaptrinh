#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

struct SINHVIEN
{
	char hoTen[100];
	char ngayThangNamSinh[50];
	char lop[20];
	char mssv[20];
	float diemTB;
	unsigned int nguoiThan;
};

void nhap(SINHVIEN &a)
{
	printf("\n\t+ Ho va Ten: ");
	fflush(stdin);
	gets(a.hoTen);

	printf("\n\t+ Ngay Thang Nam Sinh: ");
	fflush(stdin);
	gets(a.ngayThangNamSinh);

	printf("\n\t+ Lop: ");
	fflush(stdin);
	scanf("%s", a.lop);

	printf("\n\t+ MSSV: ");
	fflush(stdin);
	scanf("%s", a.mssv);

	printf("\n\t+ Diem trung binh: ");
	scanf("%f", &a.diemTB);

	printf("\n\t+ So luong nguoi than: ");
	scanf("%d", &a.nguoiThan);
}

void nhapSV(SINHVIEN a[], int &n)
{
	printf("\nMoi nhap vao so luong sinh vien: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("\nSinh vien thu %d: ", i + 1);
		nhap(a[i]);
	}
}

void xuat(SINHVIEN a)
{
	printf(" \n\tHo va Ten: ");
	printf("%s", a.hoTen);

	printf("\n\tNgay Thang Nam Sinh: ");
	printf("%s", a.ngayThangNamSinh);

	printf(" \n\tLop: ");
	printf("%s", a.lop);

	printf("\n\tMSSV: ");
	printf("%s", a.mssv);

	printf("\n\tDiem trung binh: ");
	printf("%.1f", a.diemTB);

	printf("\n\tSo luong nguoi than: ");
	printf("%d", a.nguoiThan);
	printf ("\n");
}

void xuatSV(SINHVIEN a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nSinh vien thu %d: ", i + 1);
		xuat(a[i]);
	}
}

void maxTB(SINHVIEN a[], int n)
{
	SINHVIEN max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i].diemTB > max.diemTB)
			max = a[i];
	}

	for (int j = 0; j < n; j++)
	{
		if (max.diemTB - a[j].diemTB < 0.0001)
			xuat(a[j]);
	}
}

void testStudentcode(SINHVIEN a[], int n)
{
	int k = 0;
	char ktms[20];
	printf("\nMoi nhap MSSV can tim: ");
	fflush(stdin);
	scanf("%s", ktms);

	for (int i = 0; i < n; i++)
	{
		if (strcmp(ktms, a[i].mssv) == 0)// so sanh co in hoa thuong
		{
			xuat(a[i]);
		}
	}
	if (k == 0)
		printf ("\nMa so sinh vien ban can tim khong co trong danh sach");
}

void getName(char hovaTen[], char temp[])
{
	int n = strlen(hovaTen);
	int ntemp = 0;
	if (hovaTen[n-1] != ' ')
	{
		for (int i = n-1; i >= 0; i--)
		{
			if (hovaTen[i] == ' ')
			{
				for (int j = i+1; j < n; j++)
				{
					temp[ntemp] = hovaTen[j];
					ntemp++;
				}
				temp[ntemp] = '\0';
			}
		}
	}
}
void testStudentName(SINHVIEN a[], int n)
{
	int k = 0;
	char ktten[100];
	printf("\nMoi nhap Ten Sinh Vien can tim: ");
	fflush(stdin);
	gets(ktten);
	for (int i = 0; i < n; i++)
	{
		char ten[100];// hung cai ten da cat
		getName(a[i].hoTen, ten);
		if (stricmp(ktten, ten) == 0)// so sanh khong in hoa thuong
		{
			xuat(a[i]);
			k = 1;
		}
	}
	if (k == 0)
		printf ("\nTen ban can tim khong co trong danh sach");
}

void testClass(SINHVIEN a[], int n)
{
	int k = 0;
	char ktlop[20];
	printf("\nMoi nhap Lop: ");
	fflush(stdin);
	scanf("%s", ktlop);
	for (int i = 0; i < n; i++)
	{
		if (strcmp(ktlop, a[i].lop) == 0)
		{
			xuat(a[i]);
		}
	}
	if (k == 0)
		printf ("\nLop ban can tim khong co trong danh sach");
}

void ktNguoiThan(SINHVIEN a[], int n)
{
	int k = 0;
	printf ("\nSinh vien khong co nguoi than la:\n");
	for (int i = 0; i < n; i++)
	{
		if (a[i].nguoiThan == 0)
		{
			k = 1;
			xuat(a[i]);
		}
	}
	if (k == 0)
		printf ("Khong co sinh vien nao");
}

int main()
{
	
	SINHVIEN a[100];
	int n = 0;
	int chon;
	printf ("Moi nhap danh sach sinh vien truoc khi thuc hien lenh:\n");
	nhapSV(a, n);
	do
	{
		printf ("\n++++*****************************************************************++++");
		printf ("\n++++\t\t1.Xuat ra tat ca sinh vien                           ++++");
		printf ("\n++++\t\t2.Tim nhung sinh vien co diem trung binh cao nhat    ++++");
		printf ("\n++++\t\t3.Tim kiem sinh vien qua nhap ma so sinh vien        ++++");
		printf ("\n++++\t\t4.Tim kiem sinh vien qua nhap ten sinh vien          ++++");
		printf ("\n++++\t\t5.Tim kiem sinh vien qua nhap lop                    ++++");
		printf ("\n++++\t\t6.Tim kiem sinh vien khong co nguoi than             ++++");
		printf ("\n++++\t\t7.Thoat khoi chuong trinh                            ++++");
		printf ("\n++++*****************************************************************++++");
		printf ("\n\t\tMoi ban chon: ");
		scanf("%d", &chon);
		system("cls");
		switch(chon)
		{
			case 1: 
				xuatSV(a, n);
				break;
			case 2:
				maxTB(a, n);
				break;
			case 3:
				testStudentcode(a, n);
				break;
			case 4:
				testStudentName(a, n);
				break;
			case 5:
				testClass(a, n);
				break;
			case 6:
				ktNguoiThan(a, n);
				break;	
		}
		getch();
		system("cls");
	}while(chon != 7);
}

