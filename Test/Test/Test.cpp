#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
static int length=0;

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack* stack) {
    stack->top = -1;
}

// 判断栈是否为空
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// 判断栈是否满
int isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// 入栈操作
void push(Stack* stack, int value) {
    if (isFull(stack)) {
        printf("栈是满的，元素%d无法入栈！\n", value);
        return;
    }
    ++length;
    stack->data[++(stack->top)] = value;
    printf("入栈元素%d\n", value);
}

// 出栈操作
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈是空的，无法出栈！\n");
        return -1;
    }
    --length;    
    int value = stack->data[(stack->top)--];
    printf("从栈中输出元素%d \n", value);
    return value;
}

// 查看栈顶元素
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈是空的，无法查看！\n");
        return -1;
    }
    return stack->data[stack->top];
}

// 打印栈的内容
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("栈是空的！\n");
        return;
    }
    printf("栈的内容: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(&stack);

    pop(&stack);
    printStack(&stack);

    printf("栈顶元素为 %d\n", peek(&stack));
    printf("栈内元素个数为：%d", length);
    return 0;
}















