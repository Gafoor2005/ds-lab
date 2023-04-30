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
void beginDelete(){
    if(head == NULL){
        printf("no elements to delete\n");
        return;
    }
    else{
        struct node *temp = head->next;
        free(head);
        head = temp;
        printf("first node deleted\n");
    }
}
void lastDelete(){
    if(head == NULL){
        printf("no elements to delete\n");
        return;
    }
    if (head->next == NULL){
        beginDelete();
    }
    else{
        struct node *temp=head;
        while (temp->next->next!=NULL)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
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
            if(temp->next==NULL){
                printf("enter valid index. max index is %d\n",i);
                return;
            }
            temp = temp->next;
        }
        if(temp->next==NULL){
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