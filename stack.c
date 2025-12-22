#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CAPACITY 50
#define CAPACITY 10

// ջԪ�أ��洢�������ͣ�{/}/[/]�����������������ڱ�����λ��
typedef struct {
    char bracket;  // �����ַ�
    int position;  // ������JSON�ַ����е�λ�ã���0��ʼ��
} StackElem;

// ջ�ṹ�壨��̬���ݣ�����̶��������ƣ�
typedef struct {
    StackElem* data;     // ջ��������
    int top;             // ջ��ָ�루-1��ʾ��ջ��
    int capacity;        // ��ǰջ����
    int max_capacity;    // �������
} Stack;

// ջ�������ö�٣���ǿ��׳�ԣ�
typedef enum {
    STACK_OK,           // �����ɹ�
    STACK_EMPTY,        // ջ�գ���ջ/ȡջ��ʧ�ܣ�
    STACK_FULL,         // ջ����ѹջʧ�ܣ�
    STACK_MEM_ERR       // �ڴ����ʧ��
} StackResult;

// ----------------------------// ѧ����ʵ�ֵ�ջ�ӿ�// ----------------------------
// 1. ��ʼ��ջ��ָ����ʼ���������������
StackResult stackInit(Stack* stack, int init_capacity, int max_capacity) {
    // ѧ��ʵ�֣�
    // ����1�����init_capacity��max_capacity�Ϸ��ԣ�init <= max���Ҿ�>0��
    // ����2��Ϊstack->data�����ڴ棨malloc��
    // ����3����ʼ��top=-1��capacity=init_capacity��max_capacity=max_capacity
    // ����4�����ض�Ӧ�����STACK_OK/STACK_MEM_ERR��
    if (init_capacity > max_capacity || init_capacity <= 0 || max_capacity <= 0) {
        printf("No valid init_capacity & max_capacity!\n");
        return STACK_MEM_ERR;
    }
    StackElem* temp = NULL;
    temp = (StackElem*)calloc(init_capacity, sizeof(StackElem));
    if (temp == NULL) {
        printf("No enough memory to allocate!\n");
        return STACK_MEM_ERR;
    }
    stack->data = temp;
    stack->top = -1;
    stack->capacity = init_capacity;
    stack->max_capacity = max_capacity;
    return STACK_OK;
}

// 2. ѹջ�������ݴ���ջ��
StackResult stackPush(Stack* stack, char bracket, int position) {
    // ѧ��ʵ�֣�
// ����1�����ջ�Ƿ�����top+1 == capacity���������������ݣ��費����max_capacity��
// ����2������ʧ�ܷ���STACK_FULL���ɹ������capacity
// ����3��ջ��ָ��+1������bracket��position
// ����4������STACK_OK
    if (stack->top + 1 == stack->capacity) {
        if (stack->capacity >= stack->max_capacity) {
            return STACK_FULL;
        }
        StackElem* temp = NULL;
        temp = (StackElem*)realloc(stack->data, (stack->capacity + 1) * sizeof(StackElem));
        if (temp == NULL) {
            printf("No enough memory to allocate!\n");
            return STACK_FULL;
        }
        stack->data = temp;
        stack->top++;
        stack->capacity++;
        stack->data[stack->top].bracket = bracket;
        stack->data[stack->top].position = position;
    }
    else {
        stack->top++;
        stack->data[stack->top].bracket = bracket;
        stack->data[stack->top].position = position;
    }
    return STACK_OK;
}

// 3. ��ջ��ȡ��ջ��Ԫ�أ�ͨ��elem�����
StackResult stackPop(Stack* stack, StackElem* elem) {
    // ѧ��ʵ�֣�
    // ����1�����ջ�Ƿ�գ�stackIsEmpty�������򷵻�STACK_EMPTY
    // ����2����ջ��Ԫ�ظ�ֵ��elem��bracket��position��
    // ����3��ջ��ָ��-1
    // ����4������STACK_OK
    if (stackIsEmpty(stack)) {
        return STACK_EMPTY;
    }
    elem->bracket = stack->data[stack->top].bracket;
    elem->position = stack->data[stack->top].position;
    stack->top--;
    return STACK_OK;
}

// 4. �鿴ջ��
StackResult stackPeek(Stack* stack, StackElem* elem) {
    // ѧ��ʵ�֣�
    // ����1�����ջ�Ƿ�գ�stackIsEmpty�������򷵻�STACK_EMPTY
    // ����2����ջ��Ԫ�ظ�ֵ��elem��bracket��position��
    // ����3��ջ��ָ��-1
    // ����4������STACK_OK
    if (stackIsEmpty(stack)) {
        return STACK_EMPTY;
    }
    elem->bracket = stack->data[stack->top].bracket;
    elem->position = stack->data[stack->top].position;
    return STACK_OK;
}

// 5. �пգ�����1��ʾ�գ�0��ʾ�ǿգ�
int stackIsEmpty(const Stack* stack) {
    // ѧ��ʵ�֣�����stack->top == -1 ? 1 : 0
    return stack->top == -1 ? 1 : 0;
}

// 6. ����ջ���ͷ��ڴ棩
void stackDestroy(Stack* stack) {
    // ѧ��ʵ�֣��ͷ�stack->data���ڴ棬����top=-1��capacity=0
    free(stack->data);
    stack->top = -1;
    stack->capacity = 0;
}


// ��������
// �ж��Ƿ�Ϊ������
int isLeftBracket(char ch) {
    return ch == '{' || ch == '[';
}
// �ж��Ƿ�Ϊ������
int isRightBracket(char ch) {
    return ch == '}' || ch == ']';
}
// �ж������Ƿ�ƥ��
int isBracketMatch(char left, char right) {
    return (left == '{' && right == '}') || (left == '[' && right == ']');
}


// ջ�����汾ʵ��
int jsonBracketCheckBasic(const char* json_str) {
    // ѧ��ʵ�֣�
    // ����1�������߽������json_strΪNULL����ַ���������1��
    // ����2����ʼ��ջ������stackInit��
    // ����3������json_str��ÿ���ַ���
    //        - ���������ţ�{/[����ѹջ��stackPush��
    //        - ���������ţ�}/]������ջ�����ƥ�䣨isBracketMatch������ƥ���򷵻�0
    //        - �����ַ�������ĸ�����֡����ţ�������
    // ����4��������������ջΪ���򷵻�1���Ϸ��������򷵻�0�������Ŷ��ࣩ
    // ����5������ջ��stackDestroy��
    Stack stack;
    StackElem elem;
    int i = 0;
    int result = 0;
    if (json_str == NULL || json_str == "") {
        return 1;
    }
    if (stackInit(&stack, CAPACITY, MAX_CAPACITY) != STACK_OK) {
        printf("Failure to init the stack!\n");
        exit(0);
    }
    while (json_str[i] != '\0') {
        if (isLeftBracket(json_str[i])) {
            if (stackPush(&stack, json_str[i], i) != STACK_OK) {
                printf("Stack is full!\n");
                exit(0);
            }
        }
        else if (isRightBracket(json_str[i])) {
            if (stackPop(&stack, &elem) != STACK_OK) {
                return result;
            }
            if (!isBracketMatch(elem.bracket, json_str[i])) {
                return result;
            }
        }
        i++;
    }
    if (stackIsEmpty(&stack)) {
        result = 1;
    }
    stackDestroy(&stack);
    return result;
}

// ջ���װ汾ʵ��
// ѧ������ѧϰ״̬�����������ַ����ڵ����Ų�Ӧ�ò���ƥ�䣬ͬʱ����ת���ַ�
int jsonBracketCheckAdvanced(const char* json_str) {
    // ѧ��ʵ�֣�
    // ����1�������߽������json_strΪNULL����ַ���������1��
    // ����2����ʼ��ջ������stackInit��
    // ����3����ʼ��״̬��ǣ�in_string����ַ���״̬��escape���ת��״̬��
    // ����4������json_str��ÿ���ַ���
    //        - ������ַ����ڣ�in_stringΪ1����
    //             * �����ת��״̬��escapeΪ1����ȡ��ת��״̬������
    //             * �������ת���ַ�'\\'������ת��״̬
    //             * �����������'"'�Ҳ���ת��״̬���˳��ַ���״̬
    //             * �ַ����ڵ��������Ŷ�������
    //        - ��������ַ����ڣ�in_stringΪ0����
    //             * �����������'"'�������ַ���״̬
    //             * ���������ţ�{/[����ѹջ��stackPush��
    //             * ���������ţ�}/]������ջ�����ƥ�䣨isBracketMatch������ƥ���򷵻�0
    //             * �����ַ�������ĸ�����֡�ð�ŵȣ�������
    // ����5�����������󣬼��ջ�Ƿ�Ϊ���Ҳ����ַ����ڣ����߶������򷵻�1�����򷵻�0
    // ����6������ջ��stackDestroy��
    Stack stack;
    StackElem elem;
    int i = 0;
    int result = 0;
    int in_string = 0;
    int escape = 0;
    if (json_str == NULL || json_str == "") {
        return 1;
    }
    if (stackInit(&stack, CAPACITY, MAX_CAPACITY) != STACK_OK) {
        printf("Failure to init the stack!\n");
        exit(0);
    }
    while (json_str[i] != '\0') {
        if (in_string) {
            if (escape) {
                escape = 0;
                i++;
                continue;
            }
            if (json_str[i] == '\\') {
                escape = 1;
            }
            else if (json_str[i] == '"') {
                in_string = 0;
            }
        }
        else {
            if (isLeftBracket(json_str[i])) {
                if (stackPush(&stack, json_str[i], i) != STACK_OK) {
                    printf("Stack is full!\n");
                    exit(0);
                }
            }
            else if (isRightBracket(json_str[i])) {
                if (stackPop(&stack, &elem) != STACK_OK) {
                    return result;
                }
                if (!isBracketMatch(elem.bracket, json_str[i])) {
                    return result;
                }
            }
            else if (json_str[i] == '"') {
                in_string = 1;
            }
        }
        i++;
    }
    if (stackIsEmpty(&stack)) {
        result = 1;
    }
    stackDestroy(&stack);
    return result;
}

int main() {
    char str[100];
    // ����JSON�ַ���
    scanf("%s", str);
    // ջ������
    int result1 = jsonBracketCheckBasic(str);
    // ջ���װ�
    int result2 = jsonBracketCheckAdvanced(str);
    // ����JSON����ƥ������������ֻ�ܴ�������������װ����ܷ�����ȷ��
    printf("%d %d", result1, result2);
}