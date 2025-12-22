#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
int main() {
	int arr[] = { 2,3,28,9,8,10 };
	quickSort(arr, 0, 5);
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}

int partition(int arr[], int low, int high) {
	int pivot = arr[low];

	while (low < high && arr[high] >= pivot) {
		high--;
	}
	arr[low] = arr[high];

	while (low < high && arr[low] <= pivot) {
		low++;
	}
	arr[high] = arr[low];
	arr[low] = pivot;
}

void quickSort(int arr[], int low, int high) {
	int pi = partition(arr, low, high);

	if (low < high) {
		quickSort(arr, low, pi);
		quickSort(arr, pi + 1, high);
	}
}


