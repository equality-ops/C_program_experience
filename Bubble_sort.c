//#define _CRT_SECURE_NO_WARNINGS
////
////#include <stdio.h>
////
////#define TRUE 1
////#define FALSE 0
////
////void Bubble_sort(int arr[], int n);
////int main()
////{
////    int arr[6] = { 9, 3, 7, 1, 6, 2 };
////    int n = 6;
////    Bubble_sort(arr, n);
////    for (int i = 0; i < n; i++) {
////        printf("%d  ", arr[i]);
////    }
////    return 0;
////}
////
////void Bubble_sort(int arr[], int n) {
////    int i, j;
////    int noswap;
////    for (i = 0; i < n - 1; i++) {
////        noswap = TRUE;
////        for (j = 0; j < n - 1 - i; j++) {
////            if (arr[j + 1] < arr[j]) {
////                int temp;
////                temp = arr[j + 1];
////                arr[j + 1] = arr[j];
////                arr[j] = temp;
////                noswap = FALSE;
////            }
////        }
////        if (noswap == TRUE) return;
////    }
////}
//#include <stdio.h>
//#define R 20
//#define C 5
//struct Chair {
//    int row[R];
//    char cow[C] = { 'A','B','C','D','E' };
//    int occupation = { 0 };
//};
//int main(void) {
//    struct Chair seat;
//    int order[100], n;
//    scanf("%d", &n);
//    for (int i = 0; i < n; i++) {
//        scanf(" %d", order + i);
//        for (int j = 0; j < R; j++) {
//            if (seat.occupation[j] + order[i] <= 5) {
//                for (int k = set.occupation[j]; k < seat.occupation[j] + order[i]; k++) {
//                    printf("%d%c", seat.row[j], seat.cow[k]);
//                    if (k != seat.occupation[j] + order[i] - 1) printf("");
//                }
//                seat.occupation[j] += order[i];
//                printf("\n");
//            }
//        }
//    }
//    return 0;
//}