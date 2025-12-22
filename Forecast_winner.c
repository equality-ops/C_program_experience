//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//
//#define false 0
//#define true 1
//
//int Forecast(int* arr, int n, int round, int point1, int point2);
//int main() {
//	int n;
//	int i = 0;
//	int result = -1;
//	int round = 1;
//	int point1 = 0;
//	int point2 = 0;
//	int* arr = NULL;
//	scanf("%d", &n);
//	arr = (int*)calloc(n, sizeof(int));
//	if (arr == NULL) {
//		printf("No enough memory to allocate!");
//		exit(0);
//	}
//	for (i = 0; i < n; i++) {
//		scanf("%d", &arr[i]);
//	}
//	result = Forecast(arr, n, round, point1, point2);
//	if (result == true) {
//		printf("true");
//	}
//	else if (result == false) {
//		printf("false");
//	}
//	free(arr);
//	return 0;
//}
//
//int Forecast(int* arr, int n, int round, int point1, int point2){
//	if (n == 1) {
//		if (round == 1) {
//			point1 += arr[0];
//		}
//		else if (round == 2) {
//			point2 += arr[0];
//		}
//		if (point1 >= point2) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	int record_max = 0;
//	if (round == 1) {
//		if (arr[0] >= arr[n - 1]) {
//			record_max = arr[0];
//			n = Delete_element(arr, n, 0);
//			point1 += record_max;
//			Forecast(arr, n, 2, point1, point2);
//		}
//		else {
//			record_max = arr[n - 1];
//			n = Delete_element(arr, n, n - 1);
//			point1 += record_max;
//			Forecast(arr, n, 2, point1, point2);
//		}
//	}
//	else if (round == 2) {
//		if (arr[0] >= arr[n - 1]) {
//			record_max = arr[0];
//			n = Delete_element(arr, n, 0);
//			point2 += record_max;
//			Forecast(arr, n, 1, point1, point2);
//		}
//		else {
//			record_max = arr[n - 1];
//			n = Delete_element(arr, n, n - 1);
//			point2 += record_max;
//			Forecast(arr, n, 1, point1, point2);
//		}
//	}
//}
//
//int Delete_element(int* arr, int n, int target) {
//	if (target == 0) {
//		int i = 0;
//		for (i = 0; i < n - 1; i++) {
//			arr[i] = arr[i + 1];
//		}
//		return n - 1;
//	}
//	else if (target == n - 1) {
//		return n - 1;
//	}
//	else {
//		printf("Wrong target!");
//		exit(0);
//	}
//}