//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//
//#define length 3
//int main() {
//	char my_str[length];
//	int count;
//	FILE* fp = NULL;
//	if ((fp = fopen("D:\\Users\\C_PROGRAMMING\\tes1.txt", "r")) == NULL) {
//		printf("Failure to open text.txt!");
//		exit(0);
//	}
//	count = fread(my_str, 2 * sizeof(char), 1, fp);
//	my_str[length - 1] = '\0';
//	printf("读取到的内容为：%s", my_str);	
//	fclose(fp);
//	return 0;
//}