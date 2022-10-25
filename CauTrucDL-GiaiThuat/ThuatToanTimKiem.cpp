#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

//Tìm kiếm tuần tự
int LinearSearch(int a[], int n, int x)
{
	int index = -1;
	for(int i = 0; i < n; i++)
		if(a[i] == x)
		{
			index = i;
			break;
		}
	return index;
}

//Tìm kiếm nhị phân
int BinarySearch(int a[], int l, int r, int x)
{
	if(r >= l)
	{
		int mid = l + (r - l)/2;
		if (a[mid] == x)
			return mid;
		else 
		{
			if (a[mid] > x)
				return BinarySearch(a, l, mid-1, x);
			else
				return BinarySearch(a, mid+1, r, x);
		}
	}
	return -1;
}


void main()
{
	//srand (time(NULL));
	int arr[100000];
	int n;
	cout << " Nhap vao n: ";
	cin >> n;
	int i = 0;
	while (i < n)
	{
		//int value = 1 + rand() % 10;
		cin >> arr[i];
		i++;
	}
	int x;
	cout << " Nhap vao x: ";
	cin >> x;
	//int index = LinearSearch(arr, n, x);
	int index = BinarySearch(arr, 0, n-1, x);
	cout << " Index " << x << " :" << index << endl;
	getchar();
}