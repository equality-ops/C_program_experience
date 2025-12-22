// #define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void input_array(int* n, int** array);
int compute_winner(int* array, int head, int tail, int score1, int score2, int now);

int main()
{
    int n;
    int* array = NULL;
    input_array(&n, &array);
    
    int winner = compute_winner(array, 0, n-1, 0, 0, 1);
    
    if (winner == 1)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }
    
    free(array);
    return 0;
}

void input_array(int* n, int** array) 
{
    scanf("%d", n);
    *array = (int*)malloc(*n * sizeof(int));
    for (int i = 0; i < *n; i++)
    {
        scanf("%d", (*array) + i);
    }
}

// 返回1表示玩家1获胜，0表示玩家2获胜
int compute_winner(int* array, int head, int tail, int score1, int score2, int now)
{
    // 递归终止条件：没有剩余数字
    if (head > tail)
    {
        return score1 >= score2 ? 1 : 0;
    }
    
    if (now == 1) // 玩家1的回合
    {
        // 玩家1选择左端
        int left_choice = compute_winner(array, head + 1, tail, score1 + array[head], score2, 0);
        // 玩家1选择右端
        int right_choice = compute_winner(array, head, tail - 1, score1 + array[tail], score2, 0);
        
        // 玩家1会选择让自己获胜的选择
        return left_choice || right_choice;
    }
    else // 玩家2的回合
    {
        // 玩家2选择左端
        int left_choice = compute_winner(array, head + 1, tail, score1, score2 + array[head], 1);
        // 玩家2选择右端
        int right_choice = compute_winner(array, head, tail - 1, score1, score2 + array[tail], 1);
        
        // 玩家2会选择让玩家1输的选择（即自己赢的选择）
        // 注意：这里返回的是玩家1是否能赢，所以玩家2会尽量选择让返回值为0的选择
        return left_choice && right_choice;
    }
}