#include <iostream>
using namespace std;

class PHANSO
{
private:
	int tu;
	int mau;
public:
	void nhapPhanSo();
	void xuatPhanSo();
	PHANSO rutGonPhanSo();
	PHANSO congHaiPhanSo(PHANSO b);
};

void PHANSO::nhapPhanSo()
{
	do
	{
		cout << "Nhap vao tu va mau cua phan so ( mau so phai khac 0):\n";
		cout << "\t+Tu: ";
		cin >> this->tu;
		cout << "\t+Mau: ";
		cin >> this->mau;
	} while (this->mau == 0);
}

void PHANSO::xuatPhanSo()
{
	cout << this->tu << "/" << this->mau << endl;
}

int ucln(int a, int b)
{
	int t;
	a = abs(a);
	b = abs(b);
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	if (a == 0)
		return b;
	else
		return a;
}

PHANSO PHANSO::rutGonPhanSo()
{
	PHANSO temp;
	int k = ucln(this->tu, this->mau);
	temp.tu = this->tu / k;
	temp.mau = this->mau / k;
	return temp;
}

PHANSO PHANSO::congHaiPhanSo(PHANSO b)
{
	PHANSO temp;
	// không dùng con trỏ this, ghi trực tiếp tu, mau
	// gọi hàm rút gọn lại thì chính nó = nó nhân cho hàm rút gọn
	temp.tu = (this->tu * b.mau) + (this->mau * b.tu);
	temp.mau = this->mau * b.mau;
	temp = temp.rutGonPhanSo();
	return temp;
}


int main()
{
	PHANSO a;
	a.nhapPhanSo();
	cout << "\nPhan so sau khi nhap la: ";
	a.xuatPhanSo();
	cout << "\nPhan so sau khi rut gon la: ";
	PHANSO t = a.rutGonPhanSo();
	t.xuatPhanSo();
	PHANSO b;
	b.nhapPhanSo();
	PHANSO q = a.congHaiPhanSo(b);
	cout << "\nCong hai phan so la: ";
	q.xuatPhanSo();
	getchar();
}