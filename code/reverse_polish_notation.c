#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// 将输入转化为逆波兰表达式
typedef struct Stack {
    char *data;
    int size;
    int top;
} Stack;

Stack* init() {
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->data = (char*)malloc(sizeof(char)*100);
    s->top = 0;
    s->size = 100;
    return s;
}

void push(Stack* s, char c) {
    s->data[s->top++] = c;
}

char pop(Stack* s) {
    char op = s->data[--s->top];
    return op;
}

char top(Stack *s) {
    return s->data[s->top-1];
}

bool isempty(Stack *s) {
    return s->top == 0;
}

int main() {
    char input[100];
    printf("请输入表达式: ");
    scanf("%[^\n]s", input); // 直到遇到换行符才结束输入, scanf默认遇到空白字符表示输入结束
    Stack* s = init();  // s用于存储处理过程中的临时运算符

    for(int i=0; i<strlen(input); ++i) {
        if(input[i] == '+' || input[i] == '-') {
            if(isempty(s)) {
                push(s, input[i]);
                continue;
            }

            while(!isempty(s) && (top(s) == '+' || top(s) == '-' || top(s) == '*' || top(s) == '/')) {
                printf("%c ", pop(s));
            }
            push(s, input[i]);
        } else if(input[i] == '(' || input[i] == '*' || input[i] == '/') {
            push(s, input[i]);
        } else if(input[i] == ')') {
            while(!isempty(s) && (top(s) != '(')) {
                printf("%c ", pop(s));
            }
            pop(s);
        } else {
            if(input[i] == ' ') continue;
            printf("%c ", input[i]);
        }
    }
    while(!isempty(s)) {
        printf("%c ", pop(s));
    }
    printf("\n");
    return 0;
}
