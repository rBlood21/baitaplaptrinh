#include <stdio.h>
#include <conio.h>

// rut gon phan so, thuc chat la chia tu va mau cho uoc chung lon nhat cua hai so do.
struct fruction
{
	int tu;
	int mau;
};

void nhap(fruction &a)
{
	printf ("Nhap vao tu va mau cua mot phan so can rut gon:\n");
	scanf ("%d %d", &a.tu, &a.mau);
}

int ucln(int a, int b)
{
	int t;
	while (b != 0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	return a;
}

fruction rutGon(fruction a)
{
	fruction temp;
	int k = ucln(a.tu, a.mau);
	temp.tu = a.tu / k;
	temp.mau = a.mau / k;
	return temp;
}

int main()
{
	fruction a;
	nhap(a);
	int i = ucln(a.tu, a.mau);
	printf ("USCLN la: %d", i);
	fruction k = rutGon(a);
	printf ("\nPhan so sau khi rut gon la: %d / %d", k.tu, k.mau);
}
