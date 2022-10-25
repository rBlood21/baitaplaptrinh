#include "MANG.h"

//bài này đã từng bị 1 cái lỗi ngớ ngẫn là chổ new int thì để ngoặc tròn, và kết quả là k nhập được gì, ngồi mấy tiếng đồng hồ dò đầu bức tóc
//và không phải mình tìm ra mà là ng ấy tìm ra dùm

//hàm dựng mặc định
MANG::MANG()
{
	this->a = NULL;
	this->n = 0;
}

//hàm dựng có tham số
//gan cac phan tu = 0
MANG::MANG(int n)
{
	this->n = n;
	this->a = new int[n];
	for (int i = 0; i < this->n; i++)
		this->a[i] = 0;
}

//ham dựng có tham số
MANG::MANG(const int *arr, int n)
{
	this->n = n;
	this->a = new int[this->n];
	for (int i = 0; i < this->n; i++)
		this->a[i] = arr[i];
}

//hàm dựng sao chép
MANG::MANG(const MANG &p)
{
	this->n = p.n;
	this->a = new int[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->a[i] = p.a[i];
	}
}

//toán tử gán bằng
void MANG::operator=(const MANG &b)
{
	this->n = b.n;
	this->a = new int[this->n];
	for (int i = 0; i < this->n; i++)
	{
		this->a[i] = b.a[i];
	}
}

//toán tử mảng là ng ta truyền vào vị trí trả về giá trị tại vị trí đó
int MANG::operator[](int index)
{
	return (this->a[index]);
}


//toán tử ép kiểu
//chưa test, không biết đúng sai sao luôn, k hiểu....
MANG::operator int*() const
{
	return this->a;
}

istream &operator >>(istream &in, MANG &b)
{
	do
	{
		cout << "Moi nhap so luong phan tu mang: ";
		in >> b.n;
		if (b.n <= 0)
			cout << "\nXin nhap so luong phan tu lon hon 0!";
	}while(b.n <= 0);
	b.a = new int[b.n];
	for(int i = 0; i < b.n; i++)
	{
		cout << "a["<<i<<"] = ";
		in >> b.a[i];
	}
	return in;
}

//dùng hàm này để khi ng ta muốn in kiểu cout << t <<end;
ostream &operator <<(ostream &out, MANG &b)
{
	for (int i = 0; i < b.n; i++)
	{
		out << b.a[i] << " ";
	}
	return out;
}

//Hàm huỷ, dùng để huỷ con trỏ
MANG::~MANG()
{
}
