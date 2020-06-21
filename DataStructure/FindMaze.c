#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 6

typedef struct {
    short r;
    short c;
} element;

typedef struct {
    element data[MAX_SIZE];
    int top;
} Stack;

char maze[MAX_SIZE][MAX_SIZE] = {
        {'1', '1', '1', '1', '1', '1'},
        {'e', '0', '1', '0', '1', '1'},
        {'1', '0', '0', '0', '1', '1'},
        {'1', '0', '1', '0', '1', '1'},
        {'1', '0', '1', '0', '0', 'x'},
        {'1', '1', '1', '1', '1', '1'},
};

void initialize(Stack* stack) {
    stack->top = -1;
}

bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, element data) {
    if (isFull(stack)) {
        exit(1);
    }
    stack->data[++(stack->top)] = data;
}

element pop(Stack* stack) {
    if (isEmpty(stack)) {
        exit(1);
    }
    return stack->data[(stack->top)--];
}

void pushPosition(Stack* s, int r, int c) {
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element pos = { r, c };
        push(s, pos);
    }
}

void searchMaze(char maze[MAX_SIZE][MAX_SIZE]) {
    Stack s;
    initialize(&s);
    
    element here, entry = { 1, 0 };
    here = entry;

    int r, c;
    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';

        pushPosition(&s, r - 1, c);
        pushPosition(&s, r + 1, c);
        pushPosition(&s, r, c - 1);
        pushPosition(&s, r, c + 1);

        if (isEmpty(&s)) {
            printf("실패\n");
            return;
        }
        else {
            here = pop(&s);
        }
    }
    printf("성공\n");
}

int main(void) {
    searchMaze(maze);
    return 0;
}
