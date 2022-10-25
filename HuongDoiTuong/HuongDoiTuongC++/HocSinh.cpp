#include <iostream>
#include <string.h>
using namespace std;

class HOCSINH
{
private:
	char hoTen[100]; 
	float diemVan;
	float diemToan;
public:
	void nhapHocSinh();
	void xuatHocSinh();
	char* getHovaTen();
	float getdVan();
	float getdToan();
	void setTenHocSinh(char* hoTen);
	void setDiemVan(float diemVan);
	void setDiemToan(float diemToan);
	float tinhDiemTB();
	void xepLoai();
};

void HOCSINH::nhapHocSinh()
{
	cout << "Moi ban nhap ten hoc sinh:" << endl;
	fflush(stdin);
	gets(hoTen);
	cout << "Moi nhap diem van: ";
	cin >> this->diemVan;
	cout << "Moi nhap diem toan: ";
	cin >> this->diemToan;
}

void HOCSINH::xuatHocSinh()
{
	cout << "Ten hoc sinh:";
	puts(hoTen);
	cout << "Diem van: ";
	cout << this->diemVan;
	cout << "\nDiem toan: ";
	cout << this->diemToan << endl;
}

char* HOCSINH::getHovaTen ()
{
	return this->hoTen;
}

float HOCSINH::getdVan()
{
	return this->diemVan;
}

float HOCSINH::getdToan()
{
	return this->diemToan;
}

void HOCSINH::setTenHocSinh(char* hoTen)
{
	strcpy(this->hoTen, hoTen);
}

void HOCSINH::setDiemVan(float diemVan)
{
	this ->diemVan = diemVan;
}

void HOCSINH::setDiemToan(float diemToan)
{
	this ->diemToan = diemToan;
}

float HOCSINH::tinhDiemTB()
{
	float kq;
	kq = (this->diemVan + this->diemToan)/2;
	return kq;
}

void HOCSINH::xepLoai()
{
	float t = tinhDiemTB();
	if (t > 8.0 || (8.0-t) < 0.0001)
		cout << "Gioi\n";
	else
	{
		if ((t > 7.0 && t < 8.0) || (7.0-t)<0.001)
			cout << "Kha\n";
		else
		{
			if ((t > 5.0 && t < 7.0) || (5.0-t)<0.001)
				cout << "Trung binh\n";
			else
				cout << "Yeu\n";
		}
	}
}

int main()
{
	HOCSINH a;
	a.nhapHocSinh();
	a.xuatHocSinh();
	char* t = a.getHovaTen();
	cout <<"\nThong tin sau khi get la:\n"<< t << endl;
	float b = a.getdVan();
	cout << b << endl;
	float c = a.getdToan();
	cout << c << endl;
	a.setTenHocSinh("Duong khin");
	float diemVan = 7.8;
	float diemToan = 9.2;
	a.setDiemVan(diemVan);
	a.setDiemToan(diemToan);
	cout << "\nSau khi gan la:\n";
	a.xuatHocSinh();
	float q = a.tinhDiemTB();
	cout << "\nDiem trung binh la: " << q << endl;
	cout << "Xep loai: ";
	a.xepLoai();
	getchar();
}
