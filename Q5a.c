#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head;

void create(){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&(ptr->data));
    ptr->next = NULL;
    if(head==NULL){
        ptr->prev = NULL;
        head = ptr;
    }
    else{
        struct node *temp=head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->prev = temp;
    }
    printf("node created\n");
}
void display(){
    struct node *temp=head;
    if(temp==NULL){
        printf("no elements in list\n");
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

void main(){
    int c;
    //clrscr();
    while (1)
    {
        printf("enter your choice 1.create 2.display 3.exit\n");
        scanf("%d",&c);
        switch (c) {
            case 1:
                create();
                break;
            
            case 2:
                display();
                break;
            
            default:
                exit(0);
        }
    }
    
}