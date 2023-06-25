#include<stdio.h>
#include<conio.h>
#include<ctype.h>

int stack[100];
int top = -1;

int main(){
    char postfix[100];
    printf("enter postfix expression: ");
    scanf("%s",postfix);
    for (int i = 0; postfix[i] != '\0'; i++){
        if(isdigit(postfix[i])){
            stack[++top] = postfix[i] - 48;
        }
        else{
            int a = stack[top--];
            int b = stack[top--];
            switch (postfix[i]){
                case '+':
                    stack[++top] = b + a;
                    break;
                
                case '-':
                    stack[++top] = b - a;
                    break;
                
                case '*':
                    stack[++top] = b * a;
                    break;
                
                case '/':
                    stack[++top] = b / a;
                    break;
                
                default:
                    break;
            }
        }
    }
    printf("result is : %d\n",stack[top]);
    return 0;
}
// output:
// enter postfix expression: 123*45*++
// result is : 27