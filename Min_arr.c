//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//#include<ctype.h>
//#define M 1000
//#define N 100
//void Sort(int arr[N], int n);
//int main() {
//	char str[M];
//	int arr[N];
//	int i = 0;
//	int record = 0;
//	int len = 0;
//	scanf("%s", str);
//	while (str[i] != '\0') {
//		if (isdigit(str[i])) {
//			arr[record] = str[i] - '0';
//			record++;
//		}
//		i++;
//	}
//	len = record;
//	Sort(arr, len);
//	i = 0;
//	while (arr[i] == 0) {
//		i++;
//	}
//	if (i == 0) {
//		int j = 0;
//		for (j = 0; j < len; j++) {
//			printf("%d", arr[j]);
//		}
//	}
//	else {
//		int j = 0;
//		printf("%d", arr[i]);
//		for (j = 0; j < i; j++) {
//			printf("%d", arr[j]);
//		}
//		for (j = i + 1; j < len; j++) {
//			printf("%d", arr[j]);
//		}
//	}
//	return 0;
//}
//
//void Sort(int arr[N], int n) {
//	int i = 0, j = 0, k = 0;
//	int min;
//	for (i = 0; i < n; i++) {
//		k = i;
//		min = arr[i];
//		for (j = i; j < n - 1; j++) {
//			if (min > arr[j + 1]) {
//				k = j + 1;
//				min = arr[j + 1];
//			}
//		}
//		if (k != i) {
//			int temp;
//			temp = arr[k];
//			arr[k] = arr[i];
//			arr[i] = temp;
//		}
//	}
//}