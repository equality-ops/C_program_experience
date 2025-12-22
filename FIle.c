//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#define N 100
//// 以字符串形式向文件读取或写入内容
//int main() {
//	FILE* fp;
//	char msg[N];
//	if ((fp = fopen("D:\\Users\\C_PROGRAMMING\\test.txt", "")) == NULL) {
//		printf("Failure to open test.txt");
//		exit(0);
//	}
//	gets(msg);
//	fputs(msg, fp);
//	fclose(fp);
//	if ((fp = fopen("D:\\Users\\C_PROGRAMMING\\test.txt", "r")) == NULL) {
//		printf("Failure to open test.txt");
//		exit(0);
//	}
//	fgets(msg, sizeof(msg), fp);
//	if (ferror(fp)) {
//		printf("Error on file!\n");
//	}
//	printf("读出的内容为：%s", msg);
//	return 0;
//}





// 以字符形式向文件读取或写入内容

//int main() {
//	FILE* fp;
//	char ch = NULL;
//	if ((fp = fopen("D:\\Users\\C_PROGRAMMING\\test.txt", "r")) == NULL) {
//		printf("Failure to open test.txt!");
//		exit(0);
//	}
//	// 以只写的形式将键盘输入的内容写入到文件中
//	//ch = getchar();
//	//while(ch != '\n') {
//	//	fputc(ch, fp);
//	//	ch = getchar();
//	//}
//	// 以一个个字符的形式读出文件的内容并显示在屏幕上
//	ch = fgetc(fp);
//	while (!feof(fp)) {
//		putchar(ch);
//		ch = fgetc(fp);
//	}
//	fclose(fp);
//	return 0;
//}