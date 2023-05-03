#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 5
int stack[max];
int top = -1;
void display(){
    if (top == -1){
        printf("no elements in stack\n");
        return;
    }
    printf("data is :\n");
    for (int i = 0; i <= top; i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
void push(int n){
    if(top==max-1){
        printf("stack overflow\n");
        return;
    }
    stack[top+1]=n;
    top++;
}
int pop(){
    if(top==-1){
        printf("stack underflow\n");
        return 0;
    }
    printf("poped %d\n",stack[top]);
    return stack[top--];
}
void main(){
    int n,data;
    // clrscr();
    while (1){
        printf("enter your choice 1.display 2.push 3.pop 4.exit\n");
        scanf("%d",&n);
        switch (n){
            case 1:
                display();
                break;
            
            case 2:
                printf("enter data : ");
                scanf("%d",&data);
                push(data);
                break;
            
            case 3:
                pop();
                break;
            
            default:
                exit(0);
        }
    }  
}