#include <stdio.h>
#include <ctype.h>

int isoperator(char c) {
    int flag = 0;

    if(c == '^' || c == '/' || c == '*' || c == '+' || c == '-')
        flag = 1;

    return flag;
}   

int precedence(char operator) {
    int p = 0;

    if(operator == '^')
        p = 3;
    else if(operator == '/' || operator == '*')
        p = 2;
    else if(operator == '+' || operator == '-')
        p = 1;

    return p;
}

int main() {
    // char infix[] = "A+B*C";
    // char infix[] = "3^(1+2)/(7-4)^2";
    char infix[] = "(2+3)*4";
    
    int len = sizeof(infix);
    
    char postfix[len];
    int j = 0;

    char stack[len];
    int top = -1;

    int i;
    
    for(i=0; infix[i] != '\0'; i++) {
        char c = infix[i];

        if(c == '(')
            stack[++top] = c; 
        else if(isdigit(c)) 
            postfix[j++] = c;
        else if(c == ')') {
            while(stack[top] != '(')
                postfix[j++] = stack[top--];
            
            --top;
        } else if(isoperator(c)) {
            while(top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[j++] = stack[top--];
            
            stack[++top] = c;
        } 
    }

    while(top != -1)
        postfix[j++] = stack[top--];
    
    postfix[j] = '\0';

    
    printf("\n#################\n");

    for(i=0;postfix[i] != '\0';i++)
        printf("%c", postfix[i]);

    return 0;
}