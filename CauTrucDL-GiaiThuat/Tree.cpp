#include<stdio.h>

struct Node
{
	int info;
	struct Node * left;
	struct Node * right;
};

typedef Node * Tree;

Tree CreateNode(int x)
{
	Tree p = new Node;
	p->info = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}

void Insert(Tree &t, int x)
{
	if(t != NULL)
	{
		// co phan tu bi trung thì phan tu do se khong duoc them vao cay.
		if(x == t->info)
			return ;
		if(x < t->info)
			Insert(t->left, x);
		if(x > t->info)
			Insert(t->right, x);
	}
	else
	{
		t = CreateNode(x);
	}
}

void Input(Tree &t)
{
	//nguoi dung tu nhap vao
	int n;
	printf("\nMoi nhap so luong phan tu mang: ");
	scanf_s("%d", &n);
	for(int i = 0; i < n; i++)
	{
		int x;
		printf("\nphan tu thu %d: ", i);
		scanf_s("%d", &x);
		Insert(t, x);
	}
	//mang co dinh
	/*int n = 12;
	int a[] = {11,7,5,1,6,8,10,9,18,12,13,19};
	for(int i = 0; i < n; i++)
	{
		Insert(t, a[i]);
	}*/
}

//tương tự viết 5 cái dạng xuất còn lại: LRN, NLR, NRL, RNL, RLN
void Show_LNR(Tree t)
{
	if(t != NULL)
	{
		Show_LNR(t->right);
		printf("%4d", t->info);
		Show_LNR(t->left);	
	}
}

//duyệt cây theo mức
void LNR(Tree t, int k, int muc)
{
	if(t != NULL)
	{
		if(k == muc)
			LNR(t->left, k, muc);
		else
		{
			printf("%4d", t->info);
			LNR(t->right, k, muc);
		}
	}
}

//chèn 1 Node vào thêm cây
void AddNode(Tree &t, int x)
{
	Insert(t, x);
}

//tính chiều cao của cây, có nghĩa là bao nhiêu mức
//bỏ nút gốc ra, so 2 bên trái phải nhành nào dài hơn(nhiều mức hơn) thì lấy + 1 của nút gốc vào là xong
int Max(int a, int b)
{
	//nếu a > b return a, ngược lại return b
	return (a > b) ? a: b;//toán tử 3 ngôi
}

int HighTree(Tree t)
{
	if(t == NULL)
		return 0;
	return Max(HighTree(t->left), HighTree(t->right)) + 1;
}

//tìm kiếm
int Search_X(Tree t, int x)
{
	if(t != NULL)
	{
		if(t->info == x)
			return 1;
		if(t->info > x)
			//chú ý phải có return cho lời gọi lại hàm đệ quy
			return Search_X(t->left, x);
		return Search_X(t->right, x);
	}
	return 0;
}

//đếm số node của cây
int CountNode(Tree t)
{
	if(t == NULL)
		return 0;
	return CountNode(t->left)+CountNode(t->right)+1;
}

//đếm số nút lá của cây, nút lá là nút không có con
int CountLeafNode(Tree t)
{
	if(t == NULL)
		return 0;
	if(t->left == NULL && t->right == NULL)
		return 1;
	return CountLeafNode(t->left)+CountLeafNode(t->right);
}

//đếm số nút có 2 con
int CountTwoChildNode(Tree t)
{
	if(t == NULL)
		return 0;
	if(t->left != NULL && t->right != NULL)
		return CountTwoChildNode(t->left)+CountTwoChildNode(t->right)+1;
	return CountTwoChildNode(t->left)+CountTwoChildNode(t->right);
}

//Đếm số nút nhỏ hơn giá trị cho trước
int CountNodeSmaller_K(Tree t, int k)
{
	if(t == NULL)
		return 0;
	if(t->info < k)
		return CountNodeSmaller_K(t->left, k)+CountNodeSmaller_K(t->right, k)+1;
	return CountNodeSmaller_K(t->left, k)+CountNodeSmaller_K(t->right, k);
}

//Đếm số nút lon hơn giá trị cho trước
int CountNodeLarger_K(Tree t, int k)
{
	if(t == NULL)
		return 0;
	if(t->info > k)
		return CountNodeLarger_K(t->right, k)+CountNodeLarger_K(t->left, k)+1;
	return CountNodeLarger_K(t->right, k)+CountNodeLarger_K(t->left, k);
}

//đếm số nút cân bằng: nút cân bằng là nút có nhánh cây bên trái = độ cao của nhánh cây bên phải
int CountBalanceNode(Tree t)
{
	if(t == NULL)
		return 0;
	int l = HighTree(t->left);
	int r = HighTree(t->right);
	if(l > 0 && l == r)
		return CountBalanceNode(t->left)+CountBalanceNode(t->right)+1;
	return CountBalanceNode(t->left)+CountBalanceNode(t->right);
}

//tìm max trong cây
//lớn nhất nên chỉ duyệt về bên phải thoi, đến cuối cây nhánh bên phải là max
int MaxNode(Tree t)
{
	//duyet cho den cay con ben phai = NULL thi dung
	while(t->right != NULL)
		t = t->right;
	return t->info;
}

//tim muc cua gia tri lon nhat
int LevelMaxNode(Tree t)
{
	int muc = 0;
	while(t != NULL)
	{
		muc++;
		t = t->right;
	}
	return muc;
}

//tìm phần tử thế mạng
void TimPhanTuTheMang(Tree &p, Tree &q)
{
	if(q->left != NULL)
		TimPhanTuTheMang(p, q->left);
	else
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
}

//xoá 1 nút
void XoaNode(Tree &t, int x)
{
	if(t == NULL)
		return;
	if(t->info > x)
		XoaNode(t->left, x);
	else
	{
		if(t->info < x)
			XoaNode(t->right, x);
		else
		{
		//===========xử lý xoá 1 nút k có nút con và nút có 1 nút con=============
			Tree p = t;
			if(t->left == NULL)
				t = t->right;
			else
			{
				if(t->right == NULL)
					t = t->left;
		//========================================================================
				else
				{
					//xử lý xoá nút có 2 nút con, trái nhất của cây con phải
					//trái nhất của phải or phải nhất của trái
					TimPhanTuTheMang(p, t->right);
				}
			}
			delete(p);
		}
	}
}


//tìm tất cả đường đi đến nút có độ dài là ví dụ 4
void TimDuongDi(Tree t, int k, int muc, int a[])
{
	if(t != NULL && k < muc)
	{
		a[k] = t->info;
		if(k+1 == muc)
		{
			int i = 0;
			while(i < muc)
				printf("%4d", a[i++]);
			printf("\n");
		}
		TimDuongDi(t->left, k+1, muc, a);
		TimDuongDi(t->right, k+1, muc, a);
	}
}


int main()
{
	Tree t = NULL;
	Input(t);
	Show_LNR(t);
	printf("\nDuyet theo muc la:\n");
	int muc = 2;
	LNR(t, 0, muc);
	int x;
	printf("\nMoi nhap gia tri can chen: ");
	scanf_s("%d", &x);
	AddNode(t,x);
	Show_LNR(t);
	int high = HighTree(t);
	printf("\nChieu cao cua cay la: %d", high);
	int gt;
	printf("\nNhap vao gia tri can tim: ");
	scanf_s("%d", &gt);
	int kq = Search_X(t, gt);
	if(kq == 0)
		printf("\nKhong tim thay!");
	else
		printf("\nDa tim thay gia tri: %d", gt);
	int dem = CountNode(t);
	printf("\nSo Node cua cay la: %d", dem);
	int nut_la = CountLeafNode(t);
	printf("\nSo nut la cua cay la: %d", nut_la);
	int nut2con = CountTwoChildNode(t);
	printf("\nSo nut co 2 con cua cay la: %d", nut2con);
	int k;
	printf("\nNhap vao gia tri can tim nut nho hon no: ");
	scanf_s("%d", &k);
	int kq2 = CountNodeSmaller_K(t, k);
	printf("\nSo nut nho hon %d la: %d", k, kq2);
	int q;
	printf("\nNhap vao gia tri can tim nut lon hon no: ");
	scanf_s("%d", &q);
	int kq3 = CountNodeLarger_K(t, q);
	printf("\nSo nut lon hon %d la: %d", q, kq3);
	int kq4 = CountBalanceNode(t);
	printf("\nSo nut can bang la: %d", kq4);
	int kq5 = MaxNode(t);
	printf("\nSo lon nhat la: %d", kq5);
	int mucMax = LevelMaxNode(t);
	printf("\nMuc cua gia tri lon nhat trong cay la: %d", mucMax);
	int xoa;
	printf("\nNhap vao gia tri can xoa: ");
	scanf_s("%d", &xoa);
	XoaNode(t,xoa);
	Show_LNR(t);
	int a[100];
	printf("\nDuong di den muc 4 la:\n");
	TimDuongDi(t, 0, 4, a);
	getchar();
}
