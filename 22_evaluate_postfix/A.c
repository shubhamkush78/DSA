#include <stdio.h>
#include <ctype.h>
#include <math.h>

int arithmetic(int a, int b, char op) {
    if(op == '^') {
        return pow(b, a);
    } else if(op == '/') {
        return b / a;
    } else if(op == '*') {
        return b * a;
    } else if(op == '+') {
        return b + a;
    } else if(op == '-') {
        return b - a;
    }
}

int main() {
    //infix: (2+3)*4 => 20
    // char postfix[] = "23+4*";
    
    //infix : A^(B+C)/(D-E)^F
         // : 3^(1+2)/(7-4)^2 => 3
    char postfix[] = "312+^74-2^/";

    int i;

    int size = sizeof(postfix);

    int stack[size];
    int top = -1;

    for(i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if(isdigit(c))
            stack[++top] = c-48;
        else {
            int a = stack[top];
            int b = stack[--top];

            stack[top] = arithmetic(a, b, c);
        }        
    }

    printf("%d", stack[0]);

    return 0;
}