#include<stdio.h>
#include<string.h>
#include <windows.h>  // Windows 系统需要

int main(){
    // 设置控制台输出编码为 UTF-8
    char temp[] = "hello,world!";
    char str_1[10];
    char str_2[20];
    scanf("%s", str_1);
    printf("%s", str_1);
    return 0;
}