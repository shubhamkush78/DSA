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

void reverse(char arr[], int len) {
    int half = len/2, i, tmp;

    for(i=0;i<half;i++) {
        if(arr[i] == '(')
            arr[i] = ')';
        else if(arr[i] == ')')
            arr[i] = '(';

        if(arr[len-i-1] == '(')
            arr[len-i-1] = ')';
        else if(arr[len-i-1] == ')')
            arr[len-i-1] = '(';

        tmp = arr[i];
        arr[i] = arr[len-i-1];
        arr[len-i-1] = tmp;        
    }

    if(len%2 == 1)
        if(arr[half] == '(')
            arr[half] = ')';
        else if(arr[half] == ')')
            arr[half] = '(';
}

int main() {
    // char infix[] = "A+B*C";
    char infix[] = "A^(B+C)/(D-E)^F";
    
    int len = sizeof(infix), i;

    for(i=0;i<len;i++)
        printf("%c", infix[i]);
    printf("\n\n");
    reverse(infix, len-1);
    for(i=0;i<len;i++)
        printf("%c", infix[i]);
    
    // char postfix[len];
    // int j = 0;

    // char stack[len];
    // int top = -1;

    // int i;
    
    // for(i=0; infix[i] != '\0'; i++) {
    //     char c = infix[i];

    //     if(c == '(')
    //         stack[++top] = c; 
    //     else if(isalpha(c)) 
    //         postfix[j++] = c;
    //     else if(c == ')') {
    //         while(stack[top] != '(')
    //             postfix[j++] = stack[top--];
            
    //         --top;
    //     } else if(isoperator(c)) {
    //         while(top != -1 && precedence(stack[top]) >= precedence(c))
    //             postfix[j++] = stack[top--];
            
    //         stack[++top] = c;
    //     } 
    // }

    // while(top != -1)
    //     postfix[j++] = stack[top--];
    
    // postfix[j] = '\0';

    
    // printf("\n#################\n");

    // for(i=0;postfix[i] != '\0';i++)
    //     printf("%c", postfix[i]);

    return 0;
}