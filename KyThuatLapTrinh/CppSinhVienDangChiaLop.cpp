#include "Head.h"

int main()
{

	SINHVIEN a[100];
	int n = 0;
	int chon;
	printf("Moi nhap danh sach sinh vien truoc khi thuc hien lenh:\n");
	nhapSV(a, n);
	do
	{
		printf("\n++++*****************************************************************++++");
		printf("\n++++\t\t1.Xuat ra tat ca sinh vien                           ++++");
		printf("\n++++\t\t2.Tim nhung sinh vien co diem trung binh cao nhat    ++++");
		printf("\n++++\t\t3.Tim kiem sinh vien qua nhap ma so sinh vien        ++++");
		printf("\n++++\t\t4.Tim kiem sinh vien qua nhap ten sinh vien          ++++");
		printf("\n++++\t\t5.Tim kiem sinh vien qua nhap lop                    ++++");
		printf("\n++++\t\t6.Tim kiem sinh vien khong co nguoi than             ++++");
		printf("\n++++\t\t7.Thoat khoi chuong trinh                            ++++");
		printf("\n++++*****************************************************************++++");
		printf("\n\t\tMoi ban chon: ");
		scanf("%d", &chon);
		system("cls");
		switch (chon)
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
		_getch();
		system("cls");
	} while (chon != 7);
}
