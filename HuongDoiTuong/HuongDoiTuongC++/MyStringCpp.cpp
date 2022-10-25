#include "CMyString.h"


CMyString::CMyString()
{
	this->myString = NULL;
}

//sao chép từ cái class khác cũng như class này
CMyString::CMyString(const CMyString &a)
{
	// *this = CMyString(a.myString);
	int size = strlen(a.myString);
	this->myString = new char[size];
	for (int i = 0; i < size; i++)
		this->myString[i] = a.myString[i];
	this->myString[size] = '\0';
}

//sao chép từ một mảng kiểu char
CMyString::CMyString(const char* a)
{
	int size = strlen(a);
	this->myString = new char[size];
	for (int i = 0; i < size; i++)
		this->myString[i] = a[i];
	this->myString[size] = '\0';
}

// Khởi tạo từ một kí tự, và số lần lặp
CMyString::CMyString(char a, int iLength)
{
	this->myString = new char[iLength];
	for (int i = 0; i < iLength; i++)
		this->myString[i] = a;
	this->myString[iLength] = '\0';
}

//cộng hay chuỗi lại với nhau
CMyString operator + (char* a, CMyString &b)
{
	
	int n = strlen(a);
	int m = strlen(b.myString);
	CMyString t;
	t.myString = new char [m+n+1];
	for (int i = 0; i < n; i++)
	{
		t.myString[i] = a[i];
	}
	for(int i = 0; i < m; i++)
	{
		t.myString[i+n] = b.myString[i];
	}
	t.myString[m+n] = '\0';
	return t;
}

istream& operator >> (istream &in, CMyString &b)
{
	int n;
	cout << "\nMoi nhap do dai chuoi: ";
	cin >> n;
	b = new char [n+1];
	cout << "Moi nhap chuoi: ";
	fflush (stdin);
	gets(b.myString);
	return in;
}

ostream& operator << (ostream &out, CMyString &b)
{
	puts(b.myString);
	return out;
}

//so sánh 2 chuỗi có giống nhau hay k?
bool CMyString::operator == (const CMyString &a)
{
	int n = strlen(this->myString);
	int m = strlen(a.myString);
	if (m > n)
		return 0;
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(this->myString[i] != a.myString[i])
				return 0;
		}
		return 1;
	}
}

bool CMyString::operator == (const char *a)
{
	int n = strlen(this->myString);
	int m = strlen(a);
	if (m > n || m < n)
		return false;
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(this->myString[i] != a[i])
				return false;
		}
		return true ;
	}
}

//so sánh chuỗi 1 có lớn hơn chuỗi 2 hay k?
bool CMyString::operator > (const CMyString &a)
{
	int n = strlen(this->myString);
	int m = strlen(a.myString);
	if (n > m)
		return true;
	return false;
}

bool CMyString::operator > (const char *a)
{
	int n = strlen(this->myString);
	int m = strlen(a);
	if (n > m)
		return true;
	return false;
}

//cái < nó y chang hàm > chỉ sửa lại dấu < mà thoi nên k code á nha, tự code đêy....

CMyString CMyString::operator +(const CMyString &a)
{
	int n = strlen(a.myString);
	int m = strlen(this->myString);
	CMyString t;
	t.myString = new char [m+n+1];
	for (int i = 0; i < m; i++)
	{
		t.myString[i] = this->myString[i];
	}
	for(int i = 0; i < n; i++)
	{
		t.myString[i+m] = a.myString[i];

	}
	t.myString[m+n] = '\0';
	return t;
}

CMyString CMyString::operator +(const char *a)
{
	int n = strlen(a);
	int m = strlen(this->myString);
	CMyString t;
	t.myString = new char [m+n+1];
	for (int i = 0; i < m; i++)
	{
		t.myString[i] = this->myString[i];
	}
	for(int i = 0; i < n; i++)
	{
		t.myString[i+m] = a[i];

	}
	t.myString[m+n] = '\0';
	return t;
}

CMyString&  CMyString::operator += (const CMyString &a)
{
	CMyString tam;
	tam = *this;
	int n = strlen(a.myString);
	int m = strlen(this->myString);
	this->myString = new char [m+n+1];
	*this = tam + a.myString;
	return *this;
}

CMyString& CMyString::operator +=(const char *a)
{
	CMyString tam;
	tam = *this;
	int n = strlen(a);
	int m = strlen(this->myString);
	this->myString = new char [m+n+1];
	*this = tam + a;
	return *this;
}

char CMyString::operator [](const int &a) const
{
	int m = strlen(this->myString);
	if (a < 0 || a > m)
		return -1;
	else
	{
		return this->myString[a];
	}
}

CMyString& CMyString::operator = (const CMyString &a)
{
	int n = strlen(a.myString);
	this->myString = new char[n + 1];
    for(int i = 0; i < n; i ++)
    {
		this->myString[i] = a.myString[i];
    }
    this->myString[n] = NULL;
    return *this;
}

CMyString& CMyString::operator = (const char *a)
{
	int n = strlen(a);
	this->myString = new char[n + 1];
    for(int i = 0; i < n; i ++)
    {
		this->myString[i] = a[i];
    }
    this->myString[n] = NULL;
    return *this;
}

int CMyString::GetLength() const
{
	int i = 0;
	while(this->myString[i] != '\0')
	{
		i++;
	}
	return i;
}

bool CMyString::IsEmpty() const
{
	if(this->myString[0] == NULL)
		return true;
	return false;
}

void CMyString::Empty()
{
	//delete this->myString;
	this->myString = new char[1];
	this->myString[0] = NULL;
}

char CMyString::GetAt(const int &a) const
{
	int m = strlen(this->myString);
	if (a < 0 || a > m)
		return -1;
	else
	{
		for (int i = 0; i < m; i++)
		{
			if (i == a)
				return this->myString[i];
		}
	}
}

void CMyString::SetAt(const char &b, const int &a)
{
	int m = strlen(this->myString);
	if (a < 0 || a > m)
		cout << "\nVi tri gan khong hop le!";
	else
	{
		for (int i = 0; i < m; i++)
		{
			if (i == a)
			{
				this->myString[i] = b;
				break;
			}
		}
	}
}

//Không phân biệt hoa thường
int CMyString::CompareNoCase(const CMyString &a)
{
	//phải dùng hàm strcpy, nếu k giá trị con trỏ ban đầu sẽ bị thay đổi theo
	int n = strlen(this->myString);
	int m = strlen(a.myString);
	char * b;
	b = new char [n+1];
	strcpy(b, this->myString);
	char * c;
	c = new char [m+1];
	strcpy(c, a.myString);
	if (n != m)
		return -1;
	else
	{
		b = strlwr(b);
		c = strlwr(c);
		for(int i = 0; i < n; i++)
		{
			if(b[i] != c[i])
				return -1;
		}
		return 0;
	}
}

//có phân biệt hoa thường
int CMyString::Compare(const CMyString &a)
{
	int n = strlen(this->myString);
	int m = strlen(a.myString);
	if (n != m)
		return -1;
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(this->myString[i] != a.myString[i])
				return -1;
		}
		return 0;
	}
}

//hàm lấy chuỗi giữa 2 vị trí x và y
CMyString CMyString::Mid(int x, int y) const
{
	int n = (y-x);
	CMyString q = new char [n+1];
	for (int i = 0; i <= n; i++)
	{
		q.myString[i] = this->myString[x+i];
	}
	q.myString[n+1] = '\0';
	return q;
}

CMyString CMyString::Insert(int startIndex, CMyString a)
{
	int n = strlen(this->myString);
	int m = strlen(a.myString);
	CMyString chen = new char [m+n+1];
	int i;
	for(i = 0; i < startIndex; i++)
		chen.myString[i] = this->myString[i];
	for(i = startIndex; i < startIndex+m; i++)
		chen.myString[i] = a[i-startIndex];
	for(i = startIndex+m; i<n+m; i++)
		chen.myString[i] = this->myString[i-m];
	chen.myString [m+n] = '\0';
	return chen;
}

CMyString CMyString::Left(int left) const
{
	int n = left;
	CMyString q = new char [n+1];
	for (int i = 0; i < n; i++)
	{
		q.myString[i] = this->myString[i];
	}
	q.myString[n] = '\0';
	return q;
}

CMyString CMyString::Right(int right) const
{
	int n = right;
	CMyString q = new char [n+1];
	for (int i = 0; i < n; i++)
	{
		q.myString[i] = this->myString[i+right];
	}
	q.myString[n] = '\0';
	return q;
}

void CMyString::MakeUpper()
{
	strupr(this->myString);
}

void CMyString::MakeLower()
{
	strlwr(this->myString);
}

void xoa(char* a)
{
	int n = strlen(a);
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i+1];
	}
}

void CMyString::TrimLeft()
{
	while(this->myString[0] == ' ')
	{
		xoa(this->myString);
	}
}

void CMyString::TrimRight()
{
	int n = strlen(this->myString);
	while(this->myString[n-1] == '*')
	{
		this->myString[n-1] = this->myString[n];
		n = strlen(this->myString);
	}
}

int CMyString::Find(char a, int iFirst)const
{
	int n = strlen(this->myString);
	for (int i = iFirst; i < n; i++)
	{
		if(this->myString[i] == a)
			return i;
	}
	return -1;
}

//tìm chuỗi a có trong this hay k, theo thuật toán BruttForce
int CMyString::Find(char *a, int iFirst) const
{
	int m = strlen(a);
	int n = strlen(this->myString);
	if (m > n)
		return -1;
	else
	{
		for (int i = iFirst; i < n; i++)
		{
			int j = iFirst;
			while(j < m)
			{
				if (a[i+j] == this->myString[j])
					j++;
				else
					break;
			}
			if (j == n)
				return i;
		}
	}
	
	return -1;
}

int CMyString::Find(CMyString a, int iFirst) const
{
	int m = strlen(a.myString);
	int n = strlen(this->myString);
	if (m > n)
		return -1;
	else
	{
		for (int i = iFirst; i < n; i++)
		{
			int j = iFirst;
			while(j < m)
			{
				if (a[i+j] == this->myString[j])
					j++;
				else
					break;
			}
			if (j == n)
				return i;
		}
	}
	
	return -1;
}