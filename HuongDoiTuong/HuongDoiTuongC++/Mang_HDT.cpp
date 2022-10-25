#include <iostream>
#include <vector>
using namespace std;

class MANG
{
private:
	int a[1000];
	int n;
public:
	void nhapMang();
	void xuatMang();
	int viTri();
	bool timPT();
	void sapXep();
};

void MANG::nhapMang()
{
	cout << "Moi nhap n: ";
	cin >> this->n;
	for (int i = 0; i < n; i++)
	{
		cout << "a["<< i <<"] = ";
		cin >> a[i];
	}
}

void MANG::xuatMang()
{
	for (int i = 0; i < this->n; i++)
	{
		cout << a[i] << " ";
	}
}


//mấy cái tìm nên cho người dùng nhập ở hàm main, để khi viết câu truyền dữ liệu cho dễ
int MANG::viTri()
{
	int vt;
	cout << "\nNhap vao vi tri can lay: ";
	cin >> vt;
	for (int i = 0; i < this->n; i++)
	{
		if (vt == i)
			return a[i];
	}
}

bool MANG::timPT()
{
	int ele;
	cout << "\nMoi nhap gia tri can tim: ";
	cin >> ele;
	for (int i = 0; i < this->n; i++)
	{
		if (ele == a[i])
			return true;
	}
	return false;
}

// sắp xếp kiểu Selection Sort
void MANG::sapXep()
{
	for (int i = 0; i < this->n-1; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (a[j] < a[min])
				min = j;
		}
		if (min != i)
		{
			int t = a[min];
			a[min] = a[i];
			a[i] = t;
		}
	}
}

int main()
{
	MANG a;
	a.nhapMang();
	cout << "Mang sau khi nhap la:\n";
	a.xuatMang();
	int vt = a.viTri();
	cout << "\nGia tri la: " << vt;
	bool t = a.timPT();
	if (t == true)
		cout << "\nSo can tim co nam trong mang\n";
	else
		cout << "\nSo can tim khong nam trong mang\n";
	cout << "\nMang sau khi sap xep tang dan la:\n";
	a.sapXep();
	a.xuatMang();
	getchar();
}