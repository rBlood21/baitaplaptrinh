#include "CMyString.h"

int main()
{
	//test hàm sao chép từ 1 chuỗi char
	char *a = "thuy tien";
	CMyString b(a);
	cout << "\nb = " << b;

	//test hàm sao chép từ 1 class khác, sẵn test nhập xuất luôn
	CMyString c;
	cin >> c;
	cout << "\nc = " << c;
	CMyString d(c);
	cout << "\nd = " << d;

	//test hàm khởi tạo bằng 1 ký tự và số lần lập cho trước
	char t = 't';
	int k = 5;
	CMyString e(t, k);
	cout << "\ne = " << e;

	//test hàm cộng hai chuỗi 1 char* và 1 class
	CMyString f = a + c;
	cout << "\nCong hai chuoi lai la f = " << f;

	//test hàm kiểm tra hai chuỗi có giống nhau không theo lớp
	if (b == c)
		cout << "\nHai chuoi b va c giong nhau";
	else
		cout << "\nHai chuoi b va c khac nhau";

	//test hàm kiểm tra hai chuỗi có giống nhau không theo chuỗi ký tự char
	if(c == a)
		cout << "\nKieu char - Hai chuoi c va a giong nhau";
	else
		cout << "\nKieu char - Hai chuoi c va a khac nhau";

	//test hàm kiểm tra chuỗi 1 có lớn hơn chuỗi 2 hay không theo lớp?
	if(b > c)
		cout << "\nChuoi b dai hon chuoi c";
	else
		cout << "\nChuoi b khong dai hon chuoi c";

	// test hàm kiểm tra chuỗi 1 có lớn hơn chuỗi 2 hay không theo char
	if(c > b)
		cout << "\nChuoi c dai hon chuoi b";
	else
		cout << "\nChuoi c khong dai hon chuoi b";

	//test hàm toán tử a = a + b;
	b = b + c;
	cout << "\nb = " << b;

	// test hàm toán tử += class
	b += d;
	cout << "\nb = " << b;

	//test hàm toán tử += char
	c += a;
	cout << "\nc = " << c;

	//test hàm toán tử []
	int vitri;
	cout << "\nMoi nhap vao vi tri can tim: ";
	cin >> vitri;
	char kytu = b[vitri];
	if (kytu == -1)
		cout << "\nBan da nhap vi tri can tim khong hop le!" << endl;
	else
		cout << "\nKy tu tai vi tri do la: " << kytu << endl;

	//test hàm gán = theo class
	CMyString g;
	g = b;
	cout << "\ng = " << g;

	//test hàm gán = theo char
	g = a;
	cout << "\ng = " << g;

	//test hàm lấy độ dài
	int length = g.GetLength();
	cout << "\nDo dai chuoi la: " << length << endl;

	//test hàm kiểm tra chuỗi có rỗng không?
	CMyString testchuoirong = "";
	bool rong = testchuoirong.IsEmpty();
	if (rong == true)
		cout << "\nChuoi dang rong!";
	else
		cout << "\nChuoi khong rong!";

	//test hàm làm rỗng chuỗi
	g.Empty();
	cout << "\nChuoi sau khi lam rong la: " << g << endl;

	//test hàm GetAt
	int pos;
	cout << "\nMoi nhap vao vi tri can tim: ";
	cin >> pos;
	char kt = c.GetAt(pos);
	if (kt == -1)
		cout << "\nBan da nhap vi tri can tim khong hop le!" << endl;
	else
		cout << "\nKy tu tai vi tri do la: " << kt << endl;

	//test hàm gán 1 ký tự tại 1 vị trí
	c.SetAt(t, 4);
	cout << "\nc = " << c;
	CMyString str1;
	cin >> str1;
	CMyString str2;
	cin >> str2;

	//test hàm compare không phân biệt hoa thường
	int testCPNoCase = str1.CompareNoCase(str2);
	if (testCPNoCase == 0)
		cout << "\nHai chuoi bang nhau" << endl;
	else
		cout << "\nHai chuoi khac nhau" << endl;

	//test hàm compare có phân biệt hoa thường
	int testCP = str1.Compare(str2);
	if (testCP == 0)
		cout << "\nHai chuoi bang nhau" << endl;
	else
		cout << "\nHai chuoi khac nhau" << endl;
	
	//test hàm lấy chuỗi giữa 2 vị trí
	CMyString midstr = str1.Mid(2,5);
	cout << "\nChuoi tri giua hai vi tri la: " << midstr;

	//test hàm chèn chuỗi tại 1 ví trí
	CMyString chen = str2.Insert(4, str1);
	cout << "\nChen chuoi la: " << chen;

	//test hàm lấy bên trái
	CMyString leftstr = str2.Left(4);
	cout << "\nChuoi lay trai la: " << leftstr;

	//test hàm lấy bên phải
	CMyString rightstr = str2.Right(4);
	cout << "\nChuoi lay phai la: " << rightstr;

	//test make upper
	str2.MakeUpper();
	cout << "\nLam hoa chuoi: " << str2;

	//test hàm xoá khoảng trắng đầu
	CMyString xoa;
	cin >> xoa;
	xoa.TrimLeft();
	cout << "\nSau khi xoa dau la: " << xoa;

	//test hàm xoá trắng cuối
	xoa.TrimRight();
	cout << "\nSau khi xoa cuoi la: " << xoa;

	//test hàm Find 1 ký tự có trong chuỗi từ 1 ví trí xét duyệt, có phân biệt hoa thường
	int findchar = str2.Find('N', 3);
	if (findchar == -1)
		cout << "\nKhong tim thay!";
	else
		cout << "\nVi tri tim thay la: " << findchar;

	//test hàm Find chuỗi trong chuỗi dạng char*
	int chuoi = str1.Find(a, 2);
	if (chuoi == -1)
		cout << "\nKhong tim thay!";
	else
		cout << "\nVi tri tim thay la: " << chuoi;

	//test hàm Find chuỗi trong chuỗi dạng class
	int Cchuoi = str1.Find(str2, 2);
	if (Cchuoi == -1)
		cout << "\nKhong tim thay!";
	else
		cout << "\nVi tri tim thay la: " << chuoi;
	system("pause");
}