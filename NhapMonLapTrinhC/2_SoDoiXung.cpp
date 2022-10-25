#include <stdio.h>
#include <conio.h>
int KiemtraSoDoiXung(int n)
{
	int sodao = 0;
	while (n > 0)
	{
		sodao = (sodao * 10) + (n % 10);
		n = n / 10;
	}
	return sodao;
}
int KiemtraNhap(int &n)
{
	do
	{
		printf ("Nhap so duong lon hon 0: ");
		scanf ("%d", &n);
	}while(n <= 0);
}
int main()
{
	int n;
	KiemtraNhap(n);
	int sogoc = n;
	int kq = KiemtraSoDoiXung(n);
	if (kq == sogoc)
		printf ("%d la so doi xung", n);
	else
		printf ("%d khong la so doi xung", n);
	return 0;
}
