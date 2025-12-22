#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �û��ڵ㶨��
typedef struct Node {
   char name[50];
   int level; // 1=��ͨ, 2=VIP, 3=SVIP
   struct Node* next;
} Node;

// ���нṹ��
typedef struct Queue {
   Node* front;
   Node* rear;
} Queue;

// ��ʼ������
// ������q-����
void initQueue(Queue* q) {
   // TODO����ɶ��г�ʼ�����룬��ͷ��front,��β��rear��ʾ
   q->front = NULL;
   q->rear = NULL;
}

// �����ڵ�
Node* createNode(const char* name, int level) {
   Node* newNode = NULL;
   newNode = (Node*)malloc(sizeof(Node));
   if (newNode == NULL) {
       printf("No enough memory to allocate!");
       exit(0);
   }
   strcpy(newNode->name, name);
   newNode->level = level;
   newNode->next = NULL;
   return newNode;
}

// Request��������ӣ������ȼ����룩
// ������q-���У�name-�û�����level-�ȼ�
void request(Queue* q, const char* name, int level) {
   Node* newNode = createNode(name, level);
   Node* p = NULL;
   Node* pr = NULL;
   // ����Ϊ�գ�ֱ�Ӽ���
   if (q->front == NULL) {
       // TODO����ɶ���Ϊ�յ��߼�
       q->front = newNode;
       q->rear = newNode;
       return;
   }
   // �����߼����ߵȼ����ڵ͵ȼ��û�ǰ�棬ͬ�ȼ������ں���
   // TODO���밴�ոò��ֵ�Ҫ��ȫ����
   p = q->front;
   pr = p;
   while (p != NULL && newNode->level <= p->level) {
       pr = p;
       p = p->next;
   }

   if (p == q->front) {
       newNode->next = q->rear;
       q->front = newNode;
   }
   else if (p == NULL) {
       pr->next = newNode;
       q->rear = newNode;
   }
   else {
       newNode->next = p;
       pr->next = newNode;
   }
}

// Download�������������Ԫ�أ���ɾ����Ԫ��
// ������q-����
void download(Queue* q) {
   if (q->front == NULL) {
       printf("����Ϊ�գ�û�п����ص�����\n");
       return;
   }
   Node* temp = q->front;
   printf("�����У�%s (level=%d)\n", temp->name, temp->level);
   //TODO���������ɾ������Ԫ�ص��߼�
   q->front = q->front->next;
   if (q->front == NULL) {
       q->rear = NULL;
   }
   free(temp);
}

// Remove������ɾ��ָ���û�
// ������q-���У�name-�û���
void removeUser(Queue* q, const char* name) {
   if (q->front == NULL) {
       printf("����Ϊ�գ��޷�ɾ����\n");
       return;
   }
   Node* prev = NULL;
   Node* curr = q->front;
   while (curr != NULL && strcmp(curr->name, name) != 0) {
       // TODO��������Ѱ��ָ���û�λ�õ��߼�
       prev = curr;
       curr = curr->next;
   }
   if (curr == NULL) {
       printf("δ�ҵ��û���%s\n", name);
       return;
   }
   // ɾ��ָ���û���ע�⿼�Ƕ�ͷ�Ͷ�β�����
   // TODO�������Ƹò��ִ���
   if (curr == q->front) {
       q->front = curr->next;
   }
   else if (curr == q->rear) {
       prev->next = NULL;
       q->rear = prev;
   }
   else {
       prev->next = curr->next;
   }
   free(curr);
   printf("��ɾ���û���%s\n", name);
}

// Display��������ʾ����
// ������q-����
void display(Queue* q) {
   if (q->front == NULL) {
       printf("��ǰ����Ϊ�ա�\n");
       return;
   }
   Node* curr = q->front;
   printf("��ǰ���ض��У�\n");
   while (curr != NULL) {
       printf("�û���: %-10s | level: %d\n", curr->name, curr->level);
       // TODO��������ʣ������߼�
       curr = curr->next;
   }
}

// ��������ģ���������
int main() {
   Queue q;
   initQueue(&q);

   char command[50];
   char name[50];
   int level;
   printf("=== ĳ���������ص���ϵͳ ===\n");
   printf("֧�����Request �û��� level | Download | Remove �û��� | Display | Exit\n");
   printf("���������\n");
   while (1) {
       scanf("%s", command);
       if (strcmp(command, "Request") == 0) {
           scanf("%s %d", name, &level);
           // �����û��ȼ��ж��߼�����������Ч�û��ȼ�ʱ�����������Ч���û��ȼ��������� 1����ͨ�� 2��VIP�� 3��SVIP��������Ȼ���С�
           // TODO��
           if (level != 1 && level != 2 && level != 3) {
               printf("��Ч���û��ȼ��������� 1����ͨ�� 2��VIP�� 3��SVIP����\n");
               continue;
           }
           request(&q, name, level);
           printf("�û� %s (level=%d) �Ѽ�����С�\n", name, level);

       }
       else if (strcmp(command, "Download") == 0) {
           download(&q);

       }
       else if (strcmp(command, "Remove") == 0) {
           scanf("%s", name);
           removeUser(&q, name);

       }
       else if (strcmp(command, "Display") == 0) {
           display(&q);

       }
       else if (strcmp(command, "Exit") == 0) {
           printf("�������˳���\n");
           break;
       }
       // ���ƴ����߼�����������Ч����ʱ�����������Ч������������롣����Ȼ����
       // TODO��
       else {
           printf("��Ч������������롣\n");
       }
   }

   return 0;
}