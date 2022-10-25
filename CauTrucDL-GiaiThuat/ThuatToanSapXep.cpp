#include <iostream>
using namespace std;
#define MAX 100

void nhapMang(int a[], int &n)
{
	cout << "Moi nhap n: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

void xuatMang(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

//void SelectionSort(int a[], int n)
//{
//	for (int i = 0; i < n-1; i++)
//	{
//		int min = i;
//		for (int j = i+1; j < n; j++)
//		{
//			if (a[j] < a[min])
//				min = j;
//		}
////phải có dòng này để đở tốn 1 lần lập nếu có 2 số giống nhau
//		if (min != i)
//		{
//			int t = a[min];
//			a[min] = a[i];
//			a[i] = t;
//		}
//	}
//}

//Insertion Sort sắp theo kiểu so sánh từng cặp, ra thằng nào nhỏ hơn rồi duyệt ngược lại mảng tìm vị trí thích hợp chèn vào 
//void InsertionSort (int a[] , int n) 
//{
//    for( int i = 1; i < n; i++ ) 
//	{  
//		int temp = a[i];  
//		int j = i-1;		
//      while(j >= 0 && temp < a[j]) 
//		{
//			a[j+1] = a[j];   
//			j--;
//		}
//		a[j+1] = temp;
//	}
//}


//void BubbleSort(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = n-1; j > i; j--)
//		{
//			if (a[j] < a[j-1])
//			{
//				int t = a[j-1];
//				a[j-1] = a[j];
//				a[j] = t;
//			}
//		}
//	}
//}

//ShellSort áp dụng mảng có kích thước trung bình
//void ShellSort(int a[], int n)
//
//{
//    int gap, i, j, temp;
//    for (gap = n/2; gap > 0; gap /= 2)
//	{
//      for (i = gap; i < n; i++)
//	  {
//       for (j=i-gap; j>=0 && a[j]>a[j+gap]; j-=gap) 
//	   {
//			temp = a[j];
//
//			a[j] = a[j+gap];
//
//			a[j+gap] = temp;
//        }
//	  }
//	}
//}

////Cách 1 của Merge Sort
//void merge(int a[], int left, int mid, int right)
//{
//	int d = 0;
//	int c1, c2;
//	int tempArray[1000];
//	for (d = left, c1 = left, c2 = mid + 1; (c1 <= mid) && (c2 <= right); d++)
//	{
//		if (a[c1] < a[c2])
//		{
//			tempArray[d] = a[c1];
//			c1++;
//		}
//		else
//		{
//			tempArray[d] = a[c2];
//			c2++;
//		}
//	}
//	for (; c1 <= mid; c1++, d++)
//		tempArray[d] = a[c1];
//	for (; c2 <= right; c2++, d++)
//		tempArray[d] = a[c2];
//	for (d = left; d <= right; d++)
//		a[d] = tempArray[d];
//}

//Cách 2 của Merge Sort
//void merge (int a[], int left, int mid, int right)
//{
//	int i = left;
//	int j = mid + 1;
//	int k = 0;
//	int n = right - left + 1;
//	int temp[1000];
//	while((i <= mid) && (j <= right))
//	{
//		if (a[i] < a[j])
//		{
//			temp[k] = a[i];
//			k++;
//			i++;
//		}
//		else
//		{
//			temp[k] = a[j];
//			k++;
//			j++;
//		}
//	}
//	while(i <= mid)
//	{
//		temp[k] = a[i];
//		k++;
//		i++;
//	}
//	while(j <= right)
//	{
//		temp[k] = a[j];
//		k++;
//		j++;
//	}
//	i = left;
//	for (k = 0; k < n; k++)
//	{
//		a[i] = temp[k];
//		i++;
//	}
//}

//void MergeSort(int a[], int left, int right)
//{
//	if (left < right)
//	{
//		int mid = (left + right)/2;
//		MergeSort(a, left, mid);
//		MergeSort(a, mid + 1, right);
//		merge(a, left, mid, right);
//	}
//}


//QuickSort
// Take Left (first) Index of the array and Right (last) Index of the array
void quickSort(int Data[], int l , int r)
{
	// If the first index less or equal than the last index
	if (l <= r)
	{
		// Create a Key/Pivot Element
		int key = Data[(l+r)/2];
 
		// Create temp Variables to loop through array
		int i = l;
		int j = r;
 
		while (i <= j)
		{
			while (Data[i] < key)
				i++;
			while (Data[j] > key)
				j--;
 
			if (i <= j)
			{
				swap(Data[i], Data[j]);
				i++;
				j--;
			}
		}
		// Recursion to the smaller partition in the array after sorted above
		// Reference Giải Thuật Đệ Quy :: STDIO.VN
		if (l < j)
			quickSort(Data, l, j);
		if (r > i)
			quickSort(Data, i, r);
	}
}

int main()
{
	int a[MAX];
	int n;
	nhapMang(a, n);
	//SelectionSort(a, n);
	//InsertionSort(a, n);
	//BubbleSort(a, n);
	//ShellSort(a, n);
	//MergeSort(a, 0, n-1);
	quickSort(a, 0, n-1);
	cout << "Mang sau khi sap xep la:\n";
	xuatMang(a, n);
	getchar();
}