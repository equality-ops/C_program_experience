#include <stdio.h>

// 函数原型声明(函数的具体实现需要你在文件末尾完成)
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
    int top_k_index[100];  // 其长度固定为 100，但实际上只需将返回结果写入到其前 k 个元素即可
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

// 你需要实现的函数
void find_top_k_index(int* interest, int n, int k, int* top_k_index) {
    // 请将返回结果写入到 top_k_index 数组中
    // 其长度固定为 100，但实际上只需将返回结果写入到其前 k 个元素即可

    // 请在此处编写代码
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