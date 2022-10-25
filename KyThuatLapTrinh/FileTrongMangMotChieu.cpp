#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


void nhapMang(int a[], int &n)
{
	printf("Nhap vao so luong phan tu: ");
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		printf("  + a[%d] = ", i);
		scanf("%d", &a[i]);
	}
}

void xuatMang(int a[], int n)
{
	printf("Mang can xuat: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%d   ", a[i]);
	}
	printf("\n");
}

void loadFile(int a[], int &n, FILE * file)
{
	fscanf(file, "%d", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(file, "%d", &a[i]);
	}
}

void writeFile(int a[], int n, FILE * file)
{
	fprintf(file, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(file, "%d ", a[i]);
	}
}

int main()
{
	// Ta co mang~ luu tru~ cho ca chương trình.
	int a[1000];
	int n;

	// Khi chuong trinh bat dau
	// Kiem tra xem file lưu trữ có tồn tại chưa
	// Mở file ở dạng đọc, để ktra xem file có tồn tại hay không.
	FILE * file_in = fopen("file_save.txt", "r");
	if(file_in == NULL)
	{
		// File không tồn tại. Nên cho người dùng nhập thông tin cho mảng.
		printf("File chua ton tai\n");
		nhapMang(a, n);
	}
	else
	{
		// File tồn tại nên load dữ liệu dưới file lên. Lưu vào mảng a và n.
		printf("File ton tai\n");
		loadFile(a, n, file_in);
		fclose(file_in);
	}


	// Sau khi có thông tin mảng, cho người dùng thao tác: xuất, tìm max, tìm min, thêm, bớt, tìm SV...
	// VD Xuất mảng
	int luaChon;
	do
	{
		printf("Nhap vao cac lua chon: \n");
		printf("  1 Xuat mang\n");
		printf("  0 Thoat, luu file\n");
		printf("Nhap vao lua chon: ");
		scanf("%d", &luaChon);
		switch(luaChon)
		{
			case 1:
				xuatMang(a, n);
				break;
		}
	}
	while(luaChon != 0);
	

	// Sau khi thao tác kết thúc thì lưu lại data

	FILE * file_out = fopen("file_save.txt", "w");
	writeFile(a, n, file_out);
	fclose(file_out);


}
