#include <stdio.h>

//đề: đếm trong dãy có bao nhiêu cặp số cộng lại = M
//đây là tính luôn trường hợp là số âm và có số 0 trong dãy
int demTong(int a[], int n, int m)
{
	int dem = 0;
	for(int i = 0; i < n-1; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if(a[i] + a[j] == m)
				dem++;
		}
	}
	return dem;
}

int main()
{
	int a[100] = {8,3,5,4,1,7,20,30,25,18,16,29,15};
	int n = 14;
	int m = 19;
	int kq = demTong(a, n, m);
	printf("\nKet qua dem tong la: %d", kq);
	getchar();
}