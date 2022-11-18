// C++ Implementation of the Quick Sort Algorithm.
#include <bits/stdc++.h>
#include<time.h>
using namespace std;



int partition_r(int arr[], int low, int high)
{

    int pivot = arr[high]; 

    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++) 
    {

        if (arr[j] <= pivot) {

            i++; 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

int partition_rr(int arr[], int low, int high)
{

    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(arr[random], arr[high]);
  
    return partition_r(arr, low, high);
}
  

void quickSort_r(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition_r(arr, low, high);
        quickSort_r(arr, low, pi - 1);
        quickSort_r(arr, pi + 1, high);
    }
}





int partition_d(int arr[], int start, int end)
{
	int pivot = arr[start];
	int count = 0;
	for (int i = start + 1; i <= end; i++) {
		if (arr[i] <= pivot)
			count++;
	}

	int pivotIndex = start + count;
	swap(arr[pivotIndex], arr[start]);

	int i = start, j = end;

	while (i < pivotIndex && j > pivotIndex) {

		while (arr[i] <= pivot) {
			i++;
		}

		while (arr[j] > pivot) {
			j--;
		}

		if (i < pivotIndex && j > pivotIndex) {
			swap(arr[i++], arr[j--]);
		}
	}

	return pivotIndex;
}

void quickSort_d(int arr[], int start, int end)
{


	if (start >= end)
		return;
	int p = partition_d(arr, start, end);
	quickSort_d(arr, start, p - 1);
	quickSort_d(arr, p + 1, end);
}

int main()
{

	int arr[] = { 7, 4, 7, 3, 2, 1 };
	int n = 6;

	quickSort_r(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}
