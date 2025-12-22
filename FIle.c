//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#define N 100
//// ���ַ�����ʽ���ļ���ȡ��д������
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
//	printf("����������Ϊ��%s", msg);
//	return 0;
//}





// ���ַ���ʽ���ļ���ȡ��д������

//int main() {
//	FILE* fp;
//	char ch = NULL;
//	if ((fp = fopen("D:\\Users\\C_PROGRAMMING\\test.txt", "r")) == NULL) {
//		printf("Failure to open test.txt!");
//		exit(0);
//	}
//	// ��ֻд����ʽ���������������д�뵽�ļ���
//	//ch = getchar();
//	//while(ch != '\n') {
//	//	fputc(ch, fp);
//	//	ch = getchar();
//	//}
//	// ��һ�����ַ�����ʽ�����ļ������ݲ���ʾ����Ļ��
//	ch = fgetc(fp);
//	while (!feof(fp)) {
//		putchar(ch);
//		ch = fgetc(fp);
//	}
//	fclose(fp);
//	return 0;
//}