//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//
//struct linked_list {
//	int data;
//	struct linked_list* next;
//};
//
//struct queue {
//	struct linked_list* front;
//	struct linked_list* rear;
//	int size;
//};
//
//void Init_queue(struct queue* queue);
//void Enqueue(struct queue* queue, int notedata);
//int Dequeue(struct queue* queue, int* notedata);
//struct linked_list* append_list(struct linked_list* head, int data);
//struct linked_list* delete_list(struct linked_list* head, int aimed_data);
//struct linked_list* delete_list_In_recursion(struct linked_list* head, int aimed_data);
//int find_list(struct linked_list* head, int k);
//void free_memeory(struct linked_list* head);
//int main() {
//	int n;
//	int x; // 删除的目标节点的数据域
//	int k; // 倒数第k个节点
//	int notedata; // 出队时储存数据的容器
//	int result; // 倒数第k个节点的值
//	struct linked_list* head = NULL;
//	struct linked_list* temp = NULL;
//	struct queue* queue = NULL;
//	queue = (struct queue*)calloc(1, sizeof(struct queue));
//	Init_queue(queue);
//	srand(time(NULL)); // 设置随机数种子
//	printf("请输入你想要创建的数组的元素个数：");
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++) {
//		int data = rand() % 10 + 1;
//		Enqueue(queue, data);
//	}
//	if (queue->front->next == NULL) {
//		printf("该数组为空！");
//		exit(0);
//	}
//	temp = queue->front->next;
//	printf("当前含%d个元素的数组为：", queue->size);
//	while (temp != NULL) {
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//	printf("\n获取队首的一个元素：");
//	if (Dequeue(queue, &notedata)) {
//		printf("%d", notedata);
//	}
//	temp = queue->front->next;
//	printf("出队后的数组为：", queue->size);
//	while (temp != NULL) {
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//	free_memeory(queue->front);
//	return 0;
//}
//
//struct linked_list* append_list(struct linked_list* head, int data) {
//	struct linked_list* p = NULL;
//	struct linked_list* pr = head;
//	p = (struct linked_list*)calloc(1, sizeof(struct linked_list));
//	if (p == NULL) {
//		printf("No enough memory to allocate!");
//		exit(0);
//	}
//	if (head == NULL) {
//		head = p;
//	}
//	else {
//		while (pr->next != NULL) {
//			pr = pr->next;
//		}
//		pr->next = p;
//	}
//	p->data = data;
//	p->next = NULL;
//	return head;
//}
//
//// 非递归方式删除链表中所有值为x的节点
//struct linked_list* delete_list(struct linked_list* head, int aimed_data) {
//	struct linked_list* p = head;
//	struct linked_list* pr = p;
//	while (p != NULL) {
//		if (p->data == aimed_data) {
//			if (p == head) {
//				head = p->next;
//				free(p);
//				p = head;
//				continue;
//			}
//			else {
//				pr->next = p->next;
//				free(p);
//				p = pr->next;
//				continue;
//			}
//		}
//		pr = p;
//		p = p->next;
//	}
//	return head;
//}
//
//// 递归删除链表中所有值为aimed_data的节点，返回新的头指针
//struct linked_list* delete_list_In_recursion(struct linked_list* head, int aimed_data) {
//	if (head == NULL) {
//		return NULL;
//	}
//
//	// 先递归处理后续节点
//	head->next = delete_list_In_recursion(head->next, aimed_data);
//
//	// 再处理当前节点
//	if (head->data == aimed_data) {
//		struct linked_list* temp = head->next;
//		free(head);
//		return temp;  // 返回下一个节点作为新的头
//	}
//
//	return head;  // 当前节点不需要删除
//}
//
//// 释放所有占有的内存空间
//void free_memeory(struct linked_list* head) {
//	struct linked_list* p = head;
//	struct linked_list* pr = p;
//	while (p != NULL) {
//		pr = p;
//		p = p->next;
//		free(pr);
//	}
//}
//
//// 函数说明：寻找倒数第k个节点并返回其数据域，找不到则返回-1
//int find_list(struct linked_list* head, int k) {
//	struct linked_list* fast = head;
//	struct linked_list* slow = NULL;
//	int count = 0;
//	while (fast != NULL) {
//		fast = fast->next;
//		if (count >= k - 1) {
//			if (slow == NULL) {
//				slow = head;
//			}
//			else {
//				slow = slow->next;
//			}
//		}
//		count++;
//	}
//	if (slow == NULL) {
//		return -1;
//	}
//	else {
//		return slow->data;
//	}
//}
//
//// 函数说明：初始化队列
//void Init_queue(struct queue* queue) {
//	struct linked_list* p = NULL;
//	p = (struct linked_list*)calloc(1, sizeof(struct linked_list));
//	if (p == NULL) {
//		printf("No enough memor to allocate!");
//		exit(0);
//	}
//	p->data = 0;
//	p->next = NULL;
//	queue->front = p;
//	queue->rear = p;
//	queue->size = 0;
//}
//
//// 入队列
//void Enqueue(struct queue* queue, int notedata) {
//	struct linked_list* p = NULL;
//	p = (struct linked_list*)calloc(1, sizeof(struct linked_list));
//	if (p == NULL) {
//		printf("No enough memor to allocate!");
//		exit(0);
//	}
//	queue->rear->next = p;
//	queue->rear = p;
//	p->data = notedata;
//	p->next = NULL;
//	queue->size++;
//}
//
//// 出队列
//int Dequeue(struct queue* queue, int* notedata) {
//	struct linked_list* temp = NULL;
//	if (queue->front == queue->rear) {
//		return -1;
//	}
//	temp = queue->front;
//	*notedata = queue->front->next->data;
//	queue->front = queue->front->next;
//	free(temp);
//	queue->size--;
//	return 1;
//}