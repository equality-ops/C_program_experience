#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//// ����ԭ������(�����ľ���ʵ����Ҫ�����ļ�ĩβ���)
//void sort_interest(int* interest, int n);
//
//int main() {
//    int n;
//    scanf("%d", &n);
//    int interest[100];
//    for (int i = 0; i < n; i++) {
//        scanf("%d", &interest[i]);
//    }
//    sort_interest(interest, n);
//    for (int i = 0; i < n; i++) {
//        if (i > 0) {
//            printf(" ");
//        }
//        printf("%d", interest[i]);
//    }
//    printf("\n");
//    return 0;
//}
//
//// ����Ҫʵ�ֵĺ���
//void sort_interest(int* interest, int n) {
//    // ���ڴ˴���д����
//    int max = 0;
//    int i = 0, j = 0;
//    int k = 0;
//    for (i = 0; i < n; i++) {
//        k = i;
//        max = interest[i];
//        for (j = i + 1; j < n; j++) {
//            if (max < interest[j]) {
//                k = j;
//                max = interest[j];
//            }
//        }
//        if (k != i) {
//            int temp;
//            temp = interest[k];
//            interest[k] = interest[i];
//            interest[i] = temp;
//        }
//    }
//}

#include <stdio.h>

// ����ԭ������(�����ľ���ʵ����Ҫ�����ļ�ĩβ���)
void find_top_k_index(int* interest, int n, int k, int* top_k_index);

int main() {
   int n;
   scanf("%d", &n);
   int k;
   scanf("%d", &k);
   int interest[100];
   for (int i = 0; i < n; i++) {
       scanf("%d", &interest[i]);
   }
   int top_k_index[100];  // �䳤�ȹ̶�Ϊ 100����ʵ����ֻ�轫���ؽ��д�뵽��ǰ k ��Ԫ�ؼ���
   find_top_k_index(interest, n, k, top_k_index);
   for (int i = 0; i < k; i++) {
       if (i > 0) {
           printf(" ");
       }
       printf("%d", top_k_index[i]);
   }
   printf("\n");
   return 0;
}

// ����Ҫʵ�ֵĺ���
void find_top_k_index(int* interest, int n, int k, int* top_k_index) {
   // �뽫���ؽ��д�뵽 top_k_index ������
   // �䳤�ȹ̶�Ϊ 100����ʵ����ֻ�轫���ؽ��д�뵽��ǰ k ��Ԫ�ؼ���

   // ���ڴ˴���д����
   int max = 0;
   int i = 0, j = 0;
   int p = 0;
   int record = 0;
   for (i = 0; i < n; i++) {
       p = i;
       max = interest[i];
       for (j = i + 1; j < n; j++) {
           if (max < interest[j]) {
               p = j;
               max = interest[j];
           }
       }

       if (record < k) {
           top_k_index[record] = p;
           record++;
       }
       else {
           return;
       }

       if (p != i) {
           int temp = interest[p];
           interest[p] = interest[i];
           interest[i] = temp;
       }
   }
}

