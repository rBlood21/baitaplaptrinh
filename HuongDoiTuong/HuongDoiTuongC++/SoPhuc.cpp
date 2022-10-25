#include <iostream>
#include <math.h>

using namespace std;

class SOPHUC
{
private:
	int pThuc;
	int pAo;
public:
	void nhapSoPhuc ();
	void xuatSoPhuc ();

	int getPhanThuc ();
	int getPhanAo ();

	//gán giá trị
	void setPhanThuc(int pThuc);

	float tinhModulde ();

	SOPHUC cong(SOPHUC b);

};

void SOPHUC::nhapSoPhuc ()
{
	cout << "Moi ban nhap vao:" << endl;
	cout << "\t+ Phan thuc: ";
	cin >> this->pThuc;
	cout << "\t+ Phan ao: ";
	cin >> this->pAo;
}

void SOPHUC::xuatSoPhuc ()
{
	cout << "So phuc la:" << endl;
	cout << "\t+ Phan thuc: " << this->pThuc<< endl;
	cout << "\t+ Phan ao: " << this->pAo <<endl;
}


int SOPHUC::getPhanThuc ()
{
	return this->pThuc;
}

int SOPHUC::getPhanAo ()
{
	return this->pAo;
}

void SOPHUC::setPhanThuc (int pThuc)
{
	this ->pThuc = pThuc;
}

float SOPHUC::tinhModulde()
{
	float t = sqrt ((float)(this->pThuc*this->pThuc + this->pAo*this->pAo));
	return t;
}

//SOPHUC  cong(SOPHUC a, SOPHUC b)
//{
//	SOPHUC tong;
//	tong.pThuc = a.pThuc + b.pThuc;
//	tong.pAo = b.pAo + b.pAo;
//
//	return tong;
//}

SOPHUC  SOPHUC::cong (SOPHUC b)
{
	SOPHUC tong;
	tong.pThuc = this->pThuc + b.pThuc;
	tong.pAo = this->pAo + b.pAo;
	return tong;
}


int main()
{
	SOPHUC a;
	a.nhapSoPhuc();
	a.xuatSoPhuc();

	int t = a.getPhanThuc();
	cout << "\nPhan thuc la: " << t << endl;
	int k = a.getPhanAo();
	cout << "Phan ao la: " << k << endl;

	a.setPhanThuc(5);
	cout << "\nSo phuc sau khi set phan thuc la: " << endl;
	a.xuatSoPhuc();

	float r = a.tinhModulde();
	cout << "\nTinh modulde la: " << r << endl;

	SOPHUC b;
	b.nhapSoPhuc();
	SOPHUC tong = a.cong(b);
	cout << "Cong hai so phuc la:\n";
	tong.xuatSoPhuc();
	//trừ, nhân, chia tương tự
	getchar();
}
