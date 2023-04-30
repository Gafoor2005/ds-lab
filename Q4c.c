#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;

void create(){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&(ptr->data));
    if(head==NULL){
        head = ptr;
    }
    else{
        struct node *temp=head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = ptr;
    }
    ptr->next = head;
    printf("node created\n");
}
void display(){
    struct node *temp=head;
    if(temp==NULL){
        printf("no elements in list\n");
        return;
    }
    printf("the elements are:\n");
    while (temp->next!=head){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}

void beginDelete(){
    if(head == NULL){
        printf("no elements to delete\n");
        return;
    }
    if(head->next == head){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp = head->next;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = temp->next->next;
        free(head);
        head = temp->next;
    }
    printf("first node deleted\n");
}
void lastDelete(){
    if(head == NULL){
        printf("no elements to delete\n");
        return;
    }
    if (head->next == head){
        beginDelete();
    }
    else{
        struct node *temp=head;
        while (temp->next->next!=head)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = head;
        printf("last node deleted\n");
    }
}
void randomDelete(){
    if(head == NULL){
        printf("no elements to delete\n");
        return;
    }
    int n;
    printf("enter the index you want to delete: ");
    scanf("%d",&n);
    if (n < 0){
        printf("enter a valid index\n");
        return;
    }
    if(n==0){
        beginDelete();
    }
    else{
        int i=0;
        struct node *temp=head;
        for (i = 0; i < n-1; i++){
            if(temp->next==head){
                printf("enter valid index. max index is %d\n",i);
                return;
            }
            temp = temp->next;
        }
        if(temp->next==head){
            printf("enter valid index. max index is %d\n",i);
            return;
        }
        struct node *d = temp->next;
        temp->next = temp->next->next;
        free(d);
        printf("node deleted at %d index\n",n);
    }
}

void main(){
    int c;
    //clrscr();
    while (1)
    {
        printf("enter your choice 1.create 2.display 3.beginDelete 4.lastDelete 5.randomDelete 6.exit\n");
        scanf("%d",&c);
        switch (c) {
            case 1:
                create();
                break;
            
            case 2:
                display();
                break;
            
            case 3:
                beginDelete();
                break;
            
            case 4:
                lastDelete();
                break;
            
            case 5:
                randomDelete();
                break;
            
            default:
                exit(0);
        }
    }
    
}