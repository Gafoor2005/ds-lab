#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head;

void beginInsert(){
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&(ptr->data));
    if(head==NULL){
        head = ptr;
        ptr->next = head;
    }
    else{
        ptr->next = head; 
        struct node *temp=head;
        while(temp->next!=head){
            temp = temp->next;
        }
        head = ptr;
        temp->next = head;
    }
    printf("node inserted begin\n");
}

void lastInsert(){
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
    printf("node inserted last\n");
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
void randomInsert(){
    //display();
    int n;
    printf("enter the index where you want to insert: ");
    scanf("%d",&n);
    if (n < 0){
        printf("enter a valid index\n");
        return;
    }
    if(n == 0){
        beginInsert();
    }
    else{
        struct node *temp=head;
        int i=0;
        for (int i = 0; i < n-1; i++)
        {
            if(temp->next == head){
                printf("enter a valid index. max index is %d\n",i+1);
                return;
            }
            temp = temp->next;
        }
        if(temp == NULL){
            printf("enter a valid index. max index is %d\n",i);
            return;
        }
        struct node *ptr;
        ptr = (struct node *)malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d",&(ptr->data));
        ptr->next = temp->next;
        temp->next = ptr;
        printf("node inserted at %d index\n",n);
    }
}


void main(){
    int c;
    //clrscr();
    while (1)
    {
        printf("enter your choice 1.beginInsert 2.lastInsert 3.randomInsert 4.display 5.exit\n");
        scanf("%d",&c);
        switch (c) {
            case 1:
                beginInsert();
                break;
            
            case 2:
                lastInsert();
                break;
            
            case 3:
                randomInsert();
                break;
            
            case 4:
                display();
                break;
            
            default:
                exit(0);
        }
    }
    
}