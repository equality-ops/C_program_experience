//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#define N 5
//
//typedef struct ASCII{
//	char c;
//	int code;
//}ASCII_CODE;
//
//int main() {
//	FILE* fp;
//	ASCII_CODE ascii[N];
//	if ((fp = fopen("D:\\Users\\C_PROGRAMMING\\ASCII.txt", "r")) == NULL) {
//		printf("Failure to open ASCII.txt");
//		exit(0);
//	}
//	for (int i = 0; i < N; i++) {
//		fscanf(fp, "%d %c", &ascii[i].code, &ascii[i].c);
//	}
//	fclose(fp);
//	for (int i = 0; i < N; i++) {
//		printf("%d\t%c\n", ascii[i].code, ascii[i].c);
//	}
//	return 0;
//}