#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;

void push(int n){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = NULL;
    if(head==NULL){
        head = ptr;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = ptr;
    }
}
void display(){
    struct node *temp=head;
    if(temp==NULL){
        printf("no elements in Queue\n");
        return;
    }
    printf("the elements are:\n");
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int pop(){
    if(head == NULL){
        printf("no elements to pop\n");
        return 0;
    }
    else{
        struct node *temp = head->next;
        int data = head->data;
        free(head);
        printf("poped %d\n",data);
        head = temp;
        return data;
    }
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