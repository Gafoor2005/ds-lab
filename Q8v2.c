#include<stdio.h>
#include<conio.h>
#include<ctype.h>

char stack[100];
int top = -1;

int precedence(char a){
    if(a == '^')
        return 3;
    else if(a == '*' || a == '/')
        return 2;
    else if(a == '+' || a == '-')
        return 1;
    else
        return 0;
}

int isOperator(char a){
    if(a == '^' || a == '*' || a == '/' || a == '+' || a == '-')
        return 1;
    else
        return 0;
}

int main(){
    char infix[100],postfix[100];
    int pTop = -1;
    // a*b-(c/d*(e+f-g*h)/i)+j
    // clrscr();
    printf("enter infix expression: ");
    scanf("%s",infix);
    for (int i = 0; infix[i] != '\0'; i++){
        if (isalpha(infix[i]) || isdigit(infix[i])){
            postfix[++pTop] = infix[i];
        }
        else if (infix[i] == '('){
            stack[++top] = infix[i];
        }
        else if ( isOperator(infix[i])){
            if(top == -1){
                stack[++top] = infix[i];
            }
            else{
                while(isOperator(stack[top]) && (precedence(stack[top]) >= precedence(infix[i]))){
                    postfix[++pTop] = stack[top--];
                }
                stack[++top] = infix[i];
            }
        }
        else if (infix[i] == ')'){
            while(stack[top] != '('){
                postfix[++pTop] = stack[top--];
            }
            top--;
        }
    }
    while(top != -1){
        postfix[++pTop] = stack[top--];
    }
    postfix[++pTop] = '\0';
    printf("%s",postfix);
    return 0;
}
// output:
// enter infix expression: x+(y*z+a*b)
// xyz*ab*++