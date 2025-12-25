#include <stdio.h>

// 函数原型声明(函数的具体实现需要你在文件末尾完成)
void sort_interest(int* interest, int n);

int main() {
    int n;
    scanf("%d", &n);
    int interest[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &interest[i]);
    }
    sort_interest(interest, n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            printf(" ");
        }
        printf("%d", interest[i]);
    }
    printf("\n");
    return 0;
}

// 你需要实现的函数
void sort_interest(int* interest, int n) {
    // 请在此处编写代码
    int max = 0;
    int i = 0, j = 0;
    int k = 0;
    for (i = 0; i < n; i++) {
        k = i;
        max = interest[i];
        for (j = i + 1; j < n; j++) {
            if (max < interest[j]) {
                k = j;
                max = interest[j];
            }
        }
        if (k != i) {
            int temp;
            temp = interest[k];
            interest[k] = interest[i];
            interest[i] = temp;
        }
    }
}
