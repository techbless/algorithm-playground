#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char data) {
    if (!isFull(stack)) {
        stack->data[++(stack->top)] = data;
    }
}

char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->data[(stack->top)--];
    }
}

int evaluate(char exp[]) {
    Stack s;
    initialize(&s);
    char ch;
    int value;
    for (int i = 0; i < strlen(exp); i++) {
        ch = exp[i];
        
        if(ch != '*' && ch != '/' && ch != '+' && ch != '-') {
            value = ch - '0';
            push(&s, value);
        }
        else {
            char op2 = pop(&s);
            char op1 = pop(&s);

            switch (ch) {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '/':
                push(&s, op1 / op2);
                break;
            }
        }
    }
    return pop(&s);
}

int main(void) {
    char exp[] = { "82/3-32*+" };
    printf("%s의 연산 결과 : %d", exp, evaluate(exp));

    return 0;
}
