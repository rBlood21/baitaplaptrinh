#include <iostream>
using namespace std;

class CMyString
{
private:
	char *myString;
public:
	CMyString();
	CMyString(const CMyString &a);
	CMyString(const char* a);
	// Khởi tạo từ một kí tự, và số lần lặp
	CMyString(char a, int iLength);
	
	//virtual ~CMyString();
	
	//cộng 2 chuỗi lại, 1 chuỗi kiểu char và 1 class
	friend CMyString operator + (char* a, CMyString &b);
	friend istream& operator >> (istream &in, CMyString &b);
	friend ostream& operator << (ostream &out, CMyString &b);

	// so sánh 2 chuỗi có giống nhau hay không
	bool operator == (const CMyString &a);
	bool operator == (const char *a);

	//so sánh chuỗi 1 có lớn hơn chuỗi 2 hay không
	bool operator >(const CMyString &a);
	bool operator >(const char *a);

	//cái hàm bé hơn  nó y chang hàm > chỉ sửa lại dấu < mà thoi nên k code á nha, tự code đêy....
	//bool operator <(const CMyString&);
	//bool operator <(const char*);

	CMyString operator +(const CMyString &a);
	CMyString operator +(const char *a);

	CMyString& operator +=(const CMyString &a);
	CMyString& operator +=(const char *a);

	char operator [](const int &a) const;

	CMyString& operator =(const CMyString &a);
	CMyString& operator =(const char *a);

	// Lấy độ dài của chuổi
	int GetLength() const;

	// Kiểm tra chuỗi có rổng ko
	bool IsEmpty() const;

	// Làm rổng
	void Empty();

	// Lấy phần tử tại vị trí
	char GetAt(const int &a) const;

	// Gán phần tử tại vị trí
	void SetAt(const char &b, const int &a);

	// So sánh phân biệt hoa thường
	int Compare(const CMyString &a);

	// So sánh ko phân biệt hoa thường
	int CompareNoCase(const CMyString &a);

	// Chèn chuổi vào vị trí
	CMyString Insert(int startIndex, CMyString a);

	// Lấy chuổi giữa x và y
	CMyString Mid(int x, int y) const;

	// Lấy chuổi trái
	CMyString Left(int left) const;

	// Lấy chuổi phải
	CMyString Right(int right) const;

	void MakeUpper();
	void MakeLower();

	//Xoá trắng đầu
	void TrimLeft();
	// Xoá trắng sau
	void TrimRight();

	//tìm 1 ký tự char trong có trong mảng hay không từ 1 ví trí xét duyệt
	int Find(char a, int iFirst) const;

	//tìm chuỗi trong chuỗi từ 1 vị trí xét duyệt
	int Find(char *a, int iFirst) const; 

	int Find(CMyString a, int iFirst) const; //iFirst - vi tri bat dau tim kiem

	//int ReverseFind(char);
	//int ReverseFind(char*);
	//int ReverseFind(CMyString);
};

