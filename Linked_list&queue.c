#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct linked_list {
	int data;
	struct linked_list* next;
};

struct queue {
	struct linked_list* front;
	struct linked_list* rear;
	int size;
};

void Init_queue(struct queue* queue);
void Enqueue(struct queue* queue, int notedata);
int Dequeue(struct queue* queue, int* notedata);
struct linked_list* append_list(struct linked_list* head, int data);
struct linked_list* delete_list(struct linked_list* head, int aimed_data);
struct linked_list* delete_list_In_recursion(struct linked_list* head, int aimed_data);
int find_list(struct linked_list* head, int k);
void free_memeory(struct linked_list* head);
int main() {
	int n;
	int x; // ɾ����Ŀ��ڵ��������
	int k; // ������k���ڵ�
	int notedata; // ����ʱ�������ݵ�����
	int result; // ������k���ڵ��ֵ
	struct linked_list* head = NULL;
	struct linked_list* temp = NULL;
	struct queue* queue = NULL;
	queue = (struct queue*)calloc(1, sizeof(struct queue));
	Init_queue(queue);
	srand(time(NULL)); // �������������
	printf("����������Ҫ�����������Ԫ�ظ�����");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int data = rand() % 10 + 1;
		Enqueue(queue, data);
	}
	if (queue->front->next == NULL) {
		printf("������Ϊ�գ�");
		exit(0);
	}
	temp = queue->front->next;
	printf("��ǰ��%d��Ԫ�ص�����Ϊ��", queue->size);
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n��ȡ���׵�һ��Ԫ�أ�");
	if (Dequeue(queue, &notedata)) {
		printf("%d", notedata);
	}
	temp = queue->front->next;
	printf("���Ӻ������Ϊ��", queue->size);
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	free_memeory(queue->front);
	return 0;
}

struct linked_list* append_list(struct linked_list* head, int data) {
	struct linked_list* p = NULL;
	struct linked_list* pr = head;
	p = (struct linked_list*)calloc(1, sizeof(struct linked_list));
	if (p == NULL) {
		printf("No enough memory to allocate!");
		exit(0);
	}
	if (head == NULL) {
		head = p;
	}
	else {
		while (pr->next != NULL) {
			pr = pr->next;
		}
		pr->next = p;
	}
	p->data = data;
	p->next = NULL;
	return head;
}

// �ǵݹ鷽ʽɾ������������ֵΪx�Ľڵ�
struct linked_list* delete_list(struct linked_list* head, int aimed_data) {
	struct linked_list* p = head;
	struct linked_list* pr = p;
	while (p != NULL) {
		if (p->data == aimed_data) {
			if (p == head) {
				head = p->next;
				free(p);
				p = head;
				continue;
			}
			else {
				pr->next = p->next;
				free(p);
				p = pr->next;
				continue;
			}
		}
		pr = p;
		p = p->next;
	}
	return head;
}

// �ݹ�ɾ������������ֵΪaimed_data�Ľڵ㣬�����µ�ͷָ��
struct linked_list* delete_list_In_recursion(struct linked_list* head, int aimed_data) {
	if (head == NULL) {
		return NULL;
	}

	// �ȵݹ鴦�������ڵ�
	head->next = delete_list_In_recursion(head->next, aimed_data);

	// �ٴ�����ǰ�ڵ�
	if (head->data == aimed_data) {
		struct linked_list* temp = head->next;
		free(head);
		return temp;  // ������һ���ڵ���Ϊ�µ�ͷ
	}

	return head;  // ��ǰ�ڵ㲻��Ҫɾ��
}

// �ͷ�����ռ�е��ڴ�ռ�
void free_memeory(struct linked_list* head) {
	struct linked_list* p = head;
	struct linked_list* pr = p;
	while (p != NULL) {
		pr = p;
		p = p->next;
		free(pr);
	}
}

// ����˵����Ѱ�ҵ�����k���ڵ㲢�������������Ҳ����򷵻�-1
int find_list(struct linked_list* head, int k) {
	struct linked_list* fast = head;
	struct linked_list* slow = NULL;
	int count = 0;
	while (fast != NULL) {
		fast = fast->next;
		if (count >= k - 1) {
			if (slow == NULL) {
				slow = head;
			}
			else {
				slow = slow->next;
			}
		}
		count++;
	}
	if (slow == NULL) {
		return -1;
	}
	else {
		return slow->data;
	}
}

// ����˵������ʼ������
void Init_queue(struct queue* queue) {
	struct linked_list* p = NULL;
	p = (struct linked_list*)calloc(1, sizeof(struct linked_list));
	if (p == NULL) {
		printf("No enough memor to allocate!");
		exit(0);
	}
	p->data = 0;
	p->next = NULL;
	queue->front = p;
	queue->rear = p;
	queue->size = 0;
}

// �����
void Enqueue(struct queue* queue, int notedata) {
	struct linked_list* p = NULL;
	p = (struct linked_list*)calloc(1, sizeof(struct linked_list));
	if (p == NULL) {
		printf("No enough memor to allocate!");
		exit(0);
	}
	queue->rear->next = p;
	queue->rear = p;
	p->data = notedata;
	p->next = NULL;
	queue->size++;
}

// ������
int Dequeue(struct queue* queue, int* notedata) {
	struct linked_list* temp = NULL;
	if (queue->front == queue->rear) {
		return -1;
	}
	temp = queue->front;
	*notedata = queue->front->next->data;
	queue->front = queue->front->next;
	free(temp);
	queue->size--;
	return 1;
}