#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;



class MANG
{
private:
	int *a;
	int n;
public:
	
	MANG();

	//hàm dựng có tham số n, cac phan tu = 0
	MANG(int n);
	// Ham dung voi mang int[] va sluong phan tu
	MANG(const int *arr, int n);

	//hàm sao chép cú pháp nhất định phải có dấu &
	//nếu k có, hàm sao chép với toán tử bình thường vẫn gán = được do C++ hổ trợ
	//nhưng đối với con trỏ sẽ bị sai. vd: có hs2 sao chép từ hs1, nếu k có hàm sao chép
	//thì sau đó hs1 có thay đổi gì hs2 sẽ bị thay đổi theo k còn là giá trị như ban đầu
	//nên ta cần hàm sao chép. Để sau đó hs1 có thay đổi ntn thì hs2 cũng copy giá trị của hs1 lúc ban đầu nó chưa thay đổi.
	MANG(const MANG &p);

	//toán tử gán
	void MANG::operator=(const MANG &b);

	//toán tử mảng, truyền vào vị trí, trả về giá trị tại vị trí đó
	int MANG::operator[](int index);

	//toán tử ép kiểu
	operator int*() const;

	friend ostream &operator <<(ostream &out, MANG &b);

	friend istream &operator >>(istream &in, MANG &b);

	~MANG();
};

