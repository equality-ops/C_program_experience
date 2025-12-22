#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[], int temp[], int n, int left, int right);
void MergeSort(int arr[], int temp[],int n, int left, int mid, int right);
int main() {
	int n;
	int* arr = NULL;
	int* temp = NULL;
	scanf("%d", &n);
	arr = (int*)calloc(n, sizeof(int));
	temp = (int*)calloc(n, sizeof(int));
	if (arr == NULL) {
		printf("No enough memory to allocate!");
		exit(0);
	}
	if (temp == NULL) {
		printf("No enough memory to allocate!");
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	Merge(arr, temp, n, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	free(arr);
	free(temp);
	return 0;
}

void MergeSort(int arr[], int temp[], int n, int left, int mid, int right) {
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp[k] = arr[i++];
		}
		else {
			temp[k] = arr[j++];
		}
		k++;
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= right) {
		temp[k++] = arr[j++];
	}

	for (i = 0; i <= right; i++) {
		arr[i] = temp[i];
	}
}

void Merge(int arr[], int temp[], int n, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		Merge(arr, temp, n, left, mid);
		Merge(arr, temp, n, mid + 1, right);
		MergeSort(arr, temp, n, left, mid, right);
	}
}