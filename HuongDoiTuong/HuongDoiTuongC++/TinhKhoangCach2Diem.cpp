#include <iostream>
#include <math.h>
using namespace std;

class Diem
{
private:
	int x;
	int y;
public:
	void NhapDiem()
	{
		cout << endl << "Nhap vao x: ";
		cin >> this->x;

		cout  << "Nhap vao y: ";
		cin >> this->y;
	}
	Diem CongHaiDiem(Diem a)
	{
		Diem temp;
		temp.x = a.x + this->x;
		temp.y = a.y + this->y;
		return temp;
	}
	bool LaTamDiemO();
	void xuatDiem();
	float khoangCach(Diem a);
};


bool Diem::LaTamDiemO()
{
	if (this->x == 0 && this->y == 0)
		return true;
	return false;
}

void Diem::xuatDiem()
{
	cout << this->x<<' ';
	cout<< this->y;
}

float Diem::khoangCach(Diem a)
{
	int c = a.x - this->x;
	int d = a.y - this->y;
	int f = (c*c)+(d*d); 
	float khoangcach = sqrt((float)f);
	return khoangcach;
}
void main()
{
	//int a, b, c, d;
	//float e;
	//cin >> a >> b >> c >> d >> e;
	//cout << a << ' ' << b << endl << c;

	Diem diem1, diem2;
	diem1.NhapDiem();
	diem2.NhapDiem();
	
	bool t = diem1.LaTamDiemO();
	if (t == true)
		cout<< "\nDiem 1 la tam diem o"<<endl;
	else
		cout<<"\nDiem 1 khong phai la tam diem o\n";
	cout << "Cong hai diem lai la:\n";
	Diem diem3 = diem1.CongHaiDiem(diem2);
	diem3.xuatDiem();
	float y = diem1.khoangCach(diem2);
	cout<<"\n"<< y;
}