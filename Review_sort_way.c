//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//
//int quickSort(int arr[], int low, int high);
//void partition(int arr[], int low, int high);
//void InsertSort(int arr[], int n);
//int main() {
//	int arr[10] = { 1, 5, 2, 7, 9, 3,  4, 10, 11, 8};
//	InsertSort(arr, 10);
//	for (int i = 0; i < 10; i++) {
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
//
//int quickSort(int arr[], int low, int high) {
//	int pivot = arr[low];
//	while (low < high && arr[high] >= pivot) {
//		high--;
//	}
//	arr[low] = arr[high];
//	while (low < high && arr[low] <= pivot) {
//		low++;
//	}
//	arr[high] = arr[low];
//	arr[low] = pivot;
//
//	return low;
//}
//
//void partition(int arr[], int low, int high) {
//	if (low < high) {
//		int part = quickSort(arr, low, high);
//
//		partition(arr, low, part);
//		partition(arr, part + 1, high);
//	}
//}
//
//void InsertSort(int arr[], int n) {
//	int i;
//	int j;
//	for (i = 1; i < n; i++) {
//		int record = arr[i];
//		for (j = i - 1; j >= 0 && record <= arr[j]; j--) {
//			arr[j + 1] = arr[j];
//		}
//		arr[j + 1] = record;
//	}
//}