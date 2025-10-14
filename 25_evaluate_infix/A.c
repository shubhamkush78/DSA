#include <stdio.h>
#include <ctype.h>
#include <math.h>

int precedence(char op) {
    if(op == '^')
        return 3;
    else if(op == '/' || op == '*')
        return 2;
    else if(op == '+' || op == '-')
        return 1;
    else 
        return 0;
}

int main() {

    // char infix[] = "(5-2)*3";
    char infix[] = "3^(1+2)/(7-4)^2";
    int size = sizeof(infix), i=0;
    
    char opstack[size];
    int opstop = -1;

    int valstack[size];
    int valtop = -1;

    while(infix[i] != '\0') {
        char nx = infix[i++];

        if(nx == '(')
            opstack[++opstop] = nx;
        else if(isdigit(nx))
            valstack[++valtop] = nx-48;
        else if(nx == ')') {
            while(opstack[opstop] != '(') {
                int a = valstack[valtop];
                int b = valstack[--valtop];

                char op = opstack[opstop--]; 
                valstack[valtop] = op=='^'?pow(b,a):op=='/'?b/a:op=='*'?b*a:op=='+'?b+a:b-a;
            }

            opstop--;
        } else {
            while(opstop != -1 && precedence(opstack[opstop]) >= precedence(nx)) {
                int a = valstack[valtop--];
                int b = valstack[valtop];

                char op = opstack[opstop--];
                valstack[valtop] = op=='^'?pow(b,a):op=='/'?b/a:op=='*'?b*a:op=='+'?b+a:b-a;
            }

            opstack[++opstop] = nx;
        }
    }

    while(opstop != -1) {
        int a = valstack[valtop--];
        int b = valstack[valtop];

        char op = opstack[opstop--];
        valstack[valtop] = op=='^'?pow(b,a):op=='/'?b/a:op=='*'?b*a:op=='+'?b+a:b-a;
    }

    printf("Result: %d", valstack[0]);

    return 0;
}