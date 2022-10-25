#include <stdio.h>
#include <iostream>
#include "MANG.h"

int main()
{
	MANG a(10);
	//cout << a << endl;
	int mang[5]  = {0, 1, 2 ,3, 4};
	
	MANG b(mang, 5);
	//cout << b << endl;

	MANG f;
	cin >> f;
	cout << f << endl;
	//ta k thể dùng hàm copy để sao chép thằng f qua thằng a được
	//nên ta cần toán tử gán = để làm, nó sẽ thay đổi theo kích thước thằng phía sau.
	a = f;
	cout << a << endl;

	//tìm vị trí ng dùng nhập vào
	int p;
	cout << "Moi nhap vi tri can tim: ";
	cin >> p;
	cout <<"\n" << a[p] << endl;

	system("pause");
}