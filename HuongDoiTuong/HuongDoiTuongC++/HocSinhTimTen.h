#pragma once
#include <iostream>
#include <string>

using namespace std;

class HocSinh
{
	string tenHS;
	float diemVan;
	float diemToan;
public:
	HocSinh();

	float tinhDTB();
	int findName(string b);
	~HocSinh();
};

float HocSinh::tinhDTB()
{
	float diem = (this->diemVan + this->diemToan)/2;
	return diem;
}

int HocSinh::findName(string name)
{
	string t1 = strupr((char*)this->tenHS.c_str());
	string t2  = strupr((char*)name.c_str());
	int index = t1.find(t2);
	return index;
}

