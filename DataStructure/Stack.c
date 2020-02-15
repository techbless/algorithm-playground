#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

// stack 구조체
typedef struct {
	int container[MAX];
	int top;
} stack;

// stack을 만들고 top을 -1로 초기화 한후 반환
stack getNewStack() {
	stack stack1;
	stack1.top = -1;
	return stack1;
};

// stack에 value를 push
void push(stack* sptr, int value) {
	sptr->container[++sptr->top] = value;
}

// stack에서 pop
int pop(stack* sptr) {
	return sptr->container[sptr->top--];
}

int main(void) {
	stack st1 = getNewStack();

	for (int i = 0; i < 10; i++) {
		push(&st1, i);
		printf("push : %d\n", i);
	}

	for (int i = 0; i < 10; i++)
		printf("pop : %d\n", pop(&st1));
}
