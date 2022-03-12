#include <stdio.h>
#include <ctype.h>

int top = -1;
char stack[100];

void push(char s) {
    stack[++top] = s;
}

char pop() {
    char s;
    if (top < 0)
        return -1;
    else {
        s = stack[top];
        top -= 1;
        return s;
    }
}

int precedence(char Operator) {
    switch (Operator) {
        case '(': return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
    return 0;
}

int main() {
    int i=0;
    char input_string[100], temp;
    printf("Input input_string expression --> ");
    scanf("%s", &input_string);
    printf("Postfix expression --> ");
    push('(');
    while(input_string[i] != '\0')
    {
        if(isalnum(input_string[i]))
            printf("%c", input_string[i]);
        else if(input_string[i] == '(')
            push(input_string[i]);
        else if(input_string[i] == ')')
            while((temp=pop()) != '(')
                printf("%c", temp);
        else {
            while(precedence(stack[top]) >= precedence(input_string[i]))
                printf("%c", pop());
            push(input_string[i]);
        }
        i++;
    }
    while(stack[top]!='(')
        printf("%c", pop());
    printf("\n");
    return 0;
}
