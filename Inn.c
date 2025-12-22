//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#define N 20
//typedef struct stack_control {
//	char str[N];
//	int top;
//}stack;
//
//void init(stack* s); // 初始化栈顶指针
//int empty(stack* s); // 判断栈是否空，空返回 1，非空返回 0
//int push(stack* s, char e); // 将一个元素入栈，成功返回 1，失败返回 0
//int pop(stack* s, char* e); // 弹出栈顶元素，并使 e 指向被弹出的元素，成功返回 1，失败返回 0
//void Judge(stack* s,char T[], int n);
//int main() {
//	int n;
//	int i;
//	stack s;
//	char T[N];
//	init(&s);
//	scanf("%d", &n);
//	if (n > N) {
//		printf("Input wrong number！");
//		exit(0);
//	}
//	getchar();
//	for (i = 0; i < n; i++) {
//		scanf("%c", &T[i]);
//	}
//	Judge(&s, T, n);
//	return 0;
//}
//
//void init(stack* s) {
//	for (int i = 0; i < N; i++) {
//		s->str[i] = 0;
//	}
//	s->top = 0;
//}
//
//int empty(stack* s) {
//	if (s->top == 0) {
//		return 1;
//	}
//	else {
//		return 0;
//	}
//}
//
//int push(stack* s, char e) {
//	if (s->top >= N) {
//		return 0;
//	}
//	s->str[s->top] = e;
//	s->top++;
//	return 1;
//}
//
//int pop(stack* s, char* e) {
//	if (empty(s)) {
//		return 0;
//	}
//	s->top--;
//	*e = s->str[s->top];
//	return 1;
//}
//
//void Judge(stack* s, char T[], int n){
//	char c1, c2;
//	for(int i = 0; i < n; i++){
//		push(s, T[i]);
//		if (s->top >= 2) {
//			pop(s, &c2);
//			pop(s, &c1);
//			if (c1 != c2) {
//				push(s, c1);
//				push(s, c2);
//			}
//		}
//	}
//	if (empty(s)) {
//		printf("You win!\n");
//	}
//	else {
//		printf("You lose!\n");
//	}
//}