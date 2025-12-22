//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//
//#define ROW 20
//#define SEAT 5
//#define EMPTY 1
//#define FULL 0
//
//typedef struct seat_search {
//	int seat[SEAT];
//	int rest_seat;
//}SEAT_SEARCH;
//
//int* Input_information(int n);
//void Init_seat(SEAT_SEARCH seat_arrange[]);
//void Arrange_seat(SEAT_SEARCH seat_arrange[], int inf[], int n);
//void Print_results(SEAT_SEARCH seat_arrange[], char seat_name[], int inf[], int n);
//int main() {
//	int n; // 购买次数
//	int i; // 循环计数器
//	char seat_name[] = {'A','B','C','D','F'}; // 座位名称
//	SEAT_SEARCH seat_arrange[ROW];
//	int* inf = NULL; // 每次购票次数
//	Init_seat(seat_arrange);
//	scanf("%d", &n);
//	inf = Input_information(n);
//	if (inf == NULL) {
//		printf("No enough memory to allocate!");
//		exit(0);
//	}
//	for (i = 0; i < n; i++) {
//		scanf("%d", &inf[i]);
//	}
//	Arrange_seat(seat_arrange, inf, n);
//	Print_results(seat_arrange, seat_name, inf, n);
//	free(inf);
//	return 0;
//}
//
//int* Input_information(int n) {
//	int* p = NULL;
//	p = (int*)calloc(n, sizeof(int));
//	if (p == NULL) {
//		printf("No enough memory to alloate!");
//		exit(0);
//	}
//	return p;
//}
//
//void Init_seat(SEAT_SEARCH seat_arrange[]) {
//	int i;
//	int j;
//	for (i = 0; i < ROW; i++) {
//		for (j = 0; j < SEAT; j++) {
//			seat_arrange[i].seat[j] = 0;
//		}
//		seat_arrange[i].rest_seat = SEAT;
//	}
//}
//
//void Arrange_seat(SEAT_SEARCH seat_arrange[], int inf[], int n) {
//	int i;
//	for (i = 0; i < n; i++) {
//		int j;
//		if (inf[i] > 5) {
//			printf("Input wrong pieces!");
//			exit(0);
//		}
//		for (j = 0; j < ROW; j++) {
//			if (inf[i] <= seat_arrange[j].rest_seat) {
//				int k;
//				int where = SEAT - seat_arrange[j].rest_seat;
//				for (k = where; k < inf[i] + where; k++) {
//					seat_arrange[j].seat[k] = i + 1;
//				}
//				seat_arrange[j].rest_seat -= inf[i];
//				break;
//			}
//		}
//		if (j == ROW) {
//			int a;
//			int temp = inf[i];
//			for (a = 0; a < ROW; a++) {
//				
//				if (seat_arrange[a].rest_seat > 0) {
//					int b;
//					for (b = 0; b < SEAT; b++) {
//						if (seat_arrange[a].seat[b] == 0 && temp > 0) {
//							seat_arrange[a].seat[b] = i + 1;
//							temp--;
//						}
//					}
//				}
//
//				if (temp == 0) {
//					break;
//				}
//			}
//		}
//	}
//}
//
//void Print_results(SEAT_SEARCH seat_arrange[], char seat_name[],int inf[], int n) {
//	int i;
//	int j;
//	int k;
//	int record;
//	for (i = 1; i <= n; i++) {
//		record = 0;
//		for (j = 0; j < ROW; j++) {
//			for (k = 0; k < SEAT; k++) {
//				if (seat_arrange[j].seat[k] == i) {
//					record++;
//					if (record < inf[i - 1]) {
//						printf("%d%c ", j + 1, seat_name[k]);
//					}
//					else {
//						printf("%d%c", j + 1, seat_name[k]);
//					}
//				}
//			}
//		}
//		printf("\n");
//	}
//}