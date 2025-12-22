#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

void merge(int arr[], int temp[], int left, int mid, int right);
void mergeSort(int arr[], int temp[], int left, int right);
int main() {
	int n, m;
	int** score = NULL;
	int* temp_1 = NULL;
	float* temp_2 = NULL;
	float* ave_score = NULL;
	scanf("%d%d", &n, &m);
	// �����鲢�����е���ʱ����
	temp_1 = (int*)calloc(m, sizeof(int));
	if (temp_1 == NULL) {
		printf("No enough memory to allocate!");
		exit(0);
	}
	temp_2 = (float*)calloc(n, sizeof(float));
	if (temp_2 == NULL) {
		printf("No enough memory to allocate!");
		exit(0);
	}
	// �������ƽ���ֵ�����
	ave_score = (float*)calloc(n, sizeof(float));
	if (ave_score == NULL) {
		printf("No enough memory to allocate!");
		exit(0);
	}
	// ����n*m�Ķ�ά����
	score = (int**)calloc(n, sizeof(int*));
	if (score == NULL) {
		printf("No enough memory to allocate!");
		exit(0);
	}
	for (int i = 0; i < n; i++) {
		score[i] = (int*)calloc(m, sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &score[i][j]);
		}
	}
	// ��ÿλѧ�������ֽ��й鲢����
	for (int i = 0; i < n; i++) {
		mergeSort(score[i], temp_1, 0, m - 1);
	}
	// ����ƽ����
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for(int j=1;j<m-1;j++){
			sum += score[i][j];
		}
		ave_score[i] = sum / (m - 2);
	}
	mergeSort(ave_score, temp_2, 0, n - 1);
	printf("%.2f", ave_score[n - 1]);
	return 0;
}

void merge(int arr[], int temp[], int left, int mid, int right) {
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (arr[i] < arr[j]) {
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

	for (i = left; i <= right; i++) {
		arr[i] = temp[i];
	}
}

void mergeSort(int arr[], int temp[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;

		mergeSort(arr, temp, left, mid);
		mergeSort(arr, temp, mid + 1, right);
		merge(arr, temp, left, mid, right);
	}
}
