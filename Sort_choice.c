#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main() {
   int arr[10] = { 23, 5, 12, 7, 31, 19, 1, 8, 15, 4 };
   int n = 10;

   // TODO：直接插入排序
   for (int i = 1; i < n; i++) {
       int key = arr[i];
       int j;
       for (j = i; j > 0 && arr[j - 1] >= key; j--) {
           arr[j] = arr[j - 1];
       }
       arr[j] = key;
       printf("第%d趟：",i);
       for (int  h= 0; h < n; h++) {
           printf("%d ", arr[h]);
       }
       printf("\n");
   }

   printf("排序结果：");
   for (int i = 0; i < n; i++) {
       printf("%d ", arr[i]);
   }

   return 0;
}



