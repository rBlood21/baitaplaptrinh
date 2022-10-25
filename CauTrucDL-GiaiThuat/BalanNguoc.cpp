#include <stack>
#include <queue>
#include <iostream>
#include <string>

using namespace std;

string getPhanTu(string &bieuThuc)
{
	int size = bieuThuc.size();
	string kqua;
	if(bieuThuc[0] == '(' || bieuThuc[0] == ')')
	{
		kqua.resize(1);//do kqua ban đầu chưa có gán giá trị gì
		kqua = bieuThuc[0];
		bieuThuc.erase(0, 1);
		return kqua;
	}

	if(bieuThuc[0] == '+' || bieuThuc[0] == '-' || bieuThuc[0] == '*' || bieuThuc[0] == '/')
	{
		kqua.resize(1);
		kqua = bieuThuc[0];
		bieuThuc.erase(0, 1);
		return kqua;
	}

	int i = 0;
	while(i < size)
	{
		if (bieuThuc[i] >= '0' && bieuThuc[i] <= '9'|| bieuThuc[i] =='.')
		{
			kqua.resize(i+1);
			kqua[i] = bieuThuc[i];
		}
		else
			break;
		i++;
	}
	bieuThuc.erase(0, i);
	return kqua;
}

void ChuanHoaChuoi(string& temp)
{
  for (int i = 0; i < temp.length(); i++)
  {
    if (temp[i] == ' ')
		temp = temp.erase(i, 1); // Xoá 1 kí tự khoảng trắng 
  }
}

int KiemTraPhanTu(string temp)
{
	if(temp == "+" || temp == "-" ||temp == "*" || temp == "/")
		return 1;
	else
	{
		if(temp == "(" || temp == ")")
			return -1;
		else
			return 0;
	}
}

int giaTri(string o)
{
	if(o == "*" || o == "/")
		return 2;
	if(o == "+" || o == "-")
		return 1;
}

void chuyenThanhBalanNguoc(string bieuThuc, stack<string> &mystack, queue<string> &myqueue)
{
	while(!bieuThuc.empty())
	{
		string temp = getPhanTu(bieuThuc);
		//cout << temp << endl;
		if(KiemTraPhanTu(temp) == 0)
			myqueue.push(temp);
		else
		{
			if(KiemTraPhanTu(temp) == 1)
			{
				while(!mystack.empty()) // Them de o duoi sai top khong loi khi mystack trong'
				{
					if((KiemTraPhanTu(mystack.top()) == 1) && (giaTri(mystack.top()) >= giaTri(temp)))
					{
						myqueue.push(mystack.top());
						mystack.pop();
					}
					else
						break;
				}
				mystack.push(temp);
			}
			else
			{
				if(temp == "(")
					mystack.push(temp);
				else
				{
					if(temp == ")")
					{
						while(!mystack.empty())
						{
							if (mystack.top() != "(")
							{
								myqueue.push(mystack.top());
								mystack.pop();
							}
							else
								break;
						}
						//if (!mystack.empty())
							mystack.pop(); // bỏ cái ngoặc đi luôn
					}
				}
			}
		}
	}

	while(!mystack.empty())
	{
		myqueue.push(mystack.top());
		mystack.pop();
	}
}

float tinh(string dau, float a, float b)
{
	if(dau == "+")
		return a + b;
	if(dau == "-")
		return a - b;
	if(dau == "*")
		return a * b;
	if(dau == "/")
		return a / b;
}


float KetQua(queue<string>myqueue, stack<float>mystack)
{
	float kq = 0;
	while(!myqueue.empty())
	{
		string tmp = myqueue.front();
		myqueue.pop();
		if(KiemTraPhanTu(tmp) == 0)
			mystack.push(stof(tmp));//chuyển string thành float
		else
		{
			//vì phép toán thì cần 2 toán hạng để thực hiện
			if(mystack.size() < 2)
			{
				cout << "Loi bieu thuc" << endl;
				return 0;
			}
			else
			{
				float num1 = mystack.top();
				mystack.pop();
				float num2 = mystack.top();
				mystack.pop();
				kq = tinh(tmp, num2, num1);
				mystack.push(kq);
			}
		}
	}
	return kq;
}

int main()
{
	string bieuThuc;
	cout << "Nhap vao bieu thuc: ";
	getline(cin, bieuThuc);
	cout << bieuThuc << endl;
	ChuanHoaChuoi(bieuThuc);

	//kiểm tra cắt mỗi đầu phần tử
	/*while(!bieuThuc.empty())
	{
		string tmp = getPhanTu(bieuThuc);
		cout << tmp << endl;
	}*/

	stack<string> mystack1;
	queue<string> myqueue;
	chuyenThanhBalanNguoc(bieuThuc, mystack1, myqueue);

	//kiểm tra hàm chuyenThanhBalanNguoc
	//while(!myqueue.empty())
	//{
	//	cout << myqueue.front() << " ";
	//	myqueue.pop();
	//}

	stack<float> mystack2;
	float kq = KetQua(myqueue, mystack2);
	cout << "\nKet qua la: " << kq;
	getchar();
	return 0;
}

