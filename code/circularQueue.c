#include<stdio.h>
#include<stdlib.h>

int queue[5];
int count = 0;
int front = 0;
int rear = 4;

void enqueue(int data){
    if(count<5){
        queue[(rear == 4)?(rear=0):(++rear)] = data;
        count++;
    }
    else{
        printf("queue overflow\n");
    }
}

void dequeue(){
    if(count == 0){
        printf("queue underflow\n");
        return;
    }
    printf("deleting %d\n",queue[front]);
    (front!=4)?(front++):(front=0);
    count--;
}

void display(){
    if(count == 0){
        printf("no elements\n");
        return;
    }
    printf("elements are : ");
    for (int i = 0; i < count; i++){
        printf("%d ",queue[( (front+i) < 5 )?(front+i):(front+i-5)]);
    }
    printf("\n");
}

int main(){
    int c;
    while (1){
        printf("enter your choice 1.enqueue 2.dequeue 3.display 4.exit\n");
        scanf("%d",&c);
        switch (c){
            case 1:
                int a;
                printf("enter data value: ");
                scanf("%d",&a);
                enqueue(a);
                break;
            
            case 2:
                dequeue();
                break;
            
            case 3:
                display();
                break;
            
            default:
                exit(0);
        }
    }
    return 0;
}