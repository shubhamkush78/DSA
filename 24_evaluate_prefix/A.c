#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main() {

    char prefix[] = "/^3+12^-742";
    int size = sizeof(prefix), i;

    int stack[size];
    int top = -1;

    for(i=size-2; i>=0; i--) {
        char nx = prefix[i];
        if(isdigit(nx)) 
            stack[++top] = nx - '0';
        else {
            int a = stack[top--];
            int b = stack[top];

            stack[top] = nx=='^'?pow(a,b):nx=='/'?a/b:nx=='*'?a*b:nx=='+'?a+b:a-b;
        }
    }

    printf("Result: %d", stack[0]);

    return 0;
}