#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//1.kiem tra mang co tinh doi xung hay khong?
void nhapMang(int *a, int n)
{
	for(int i = 0; i < n; i++)
	{
		printf ("a[%d] = ", i);
		scanf ("%d", a+i);
	}
}

void xuatMang(int *a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf ("%d  ", a[i]);
	}
}

int kiemTraDoiXung(int *a, int n)
{
	for (int i = 0; i < n/2; i++)
	{
		if (a[i] != a[n-i-1])
			return 0;
	}
	return 1;
}
// Tim vi tri con so lon nhat va la so chan trong mang.
int viTriMax(int *a, int n)
{
	int vitri = -1;
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0 && a[i] > max)
		{
			max = a[i];
			vitri = i;
		}
	}
	return vitri;
}

//2. Tach nhung so chan sang mang khac
int* tachMangChan(int *a, int n, int &m)
{
	m = 0;
	int *b = NULL;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
		{	
			b = (int *)realloc(b, (m + 1) * sizeof(int));
			*(b + m) = a[i];
			m++;
		}
	}
	return b;
}

void add(int *a, int &n, int vitri, int phantu)
{
	//Phai them o nho trươc khi tang phần tử lên
	realloc(a, (n+1) * sizeof(int));
	for (int i = n; i >= vitri; i--)
	{
		a[i] = a[i-1];
	}
	a[vitri] = phantu;
	n++;
}

void xoa(int *a, int &n, int x)
{
	//Sau khi bớt đi rồi thì cấp phát lại 
	for (int i = x; i < n; i++)
	{
		a[i] = a[i+1];
	}
	n--;
	realloc(a, n * sizeof(int));
}

int main()
{
	int n;
	printf ("Moi nhap vao n: ");
	scanf ("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	nhapMang(a, n);
	int k = kiemTraDoiXung(a, n);
	if (k == 0)
		printf ("\nMang khong doi xung\n");
	else
		printf ("\nMang doi xung\n");
	int *b;
	int m;
	b = tachMangChan(a, n, m);
	if (b == NULL)
		printf ("\nMang khong co so nao chan");
	else
		xuatMang(b, m);
	int e = viTriMax(a, n);
	if (e == -1)
		printf ("\nMang khong co so chan nao");
	else
		printf ("\nVi tri co gia tri lon nhat chan trong mang la: %d", e);
	int vitri, phantu;
	printf ("\nMoi nhap vi tri them: ");
	scanf ("%d", &vitri);
	printf ("\nMoi nhap so muon them: ");
	scanf ("%d", &phantu);
	add(a, n, vitri, phantu);
	xuatMang(a, n);
	int x;
	printf ("\nNhap vao vi tri can xoa: ");
	scanf ("%d", &x);
	xoa(a, n, x);
	xuatMang(a, n);
	free(b);
	free(a);
	getch();
}