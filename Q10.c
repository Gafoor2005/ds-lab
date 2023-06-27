#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node * newNode(int data){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
struct node * insertNode(struct node * root,int data){
    if(root == NULL)
        return newNode(data);
    if(data < root->data){
        root->left = insertNode(root->left,data);
    }
    else if(data > root->data){
        root->right = insertNode(root->right,data);
    }
    return root;
}
void search(struct node *root,int key){
    if(root != NULL){
        if(root->data == key){
            printf("%d exist in tree\n",key);
            return;
        }
        else if(key < root->data)
            search(root->left,key);
        else
            search(root->right,key);
    }
    else{
        printf("%d does not exist in this tree\n",key);
    }
}
void inorder(struct node *root){
    if(root != NULL){
        inorder(root->left);
        printf("%d > ",root->data);
        inorder(root->right);
    }
}
void preOrder(struct node *root){
    if(root != NULL){
        printf("%d > ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d > ",root->data);
    }
}
struct node * minValueNode(struct node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}
struct node* deleteNode(struct node* root,int data){
    if(root == NULL)
        return root;
    if(data < root->data)
        root->left = deleteNode(root->left,data);
    else if(data > root->data)
        root->right = deleteNode(root->right,data);
    else{
        if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right,temp->data);
    }
    return root;
}
int main(){
    struct node * root = NULL;
    int i,n,data;
    printf("enter no of nodes in BT: ");
    scanf("%d",&n);
    printf("enter elements:\n");
    for (i = 0; i < n; i++){
        scanf("%d",&data);
        root = insertNode(root,data);
    }
    printf("inorder traversal: ");
    inorder(root);
    printf("\n");
    printf("preorder traversal: ");
    preOrder(root);
    printf("\n");
    printf("postorder traversal: ");
    postOrder(root);
    printf("\n");
    printf("which element you want to search: ");
    scanf("%d",&data);
    search(root,data);
    printf("which element you want to delete: ");
    scanf("%d",&data);
    root = deleteNode(root,data);
    printf("inorder traversal after deleting: ");
    inorder(root);
    printf("\n");
    
    return 0;
}
// output:
// enter no of nodes in BT: 6
// enter elements:
// 1 20 36 4 24 11
// inorder traversal: 1 > 4 > 11 > 20 > 24 > 36 >
// preorder traversal: 1 > 20 > 4 > 11 > 36 > 24 >
// postorder traversal: 11 > 4 > 24 > 36 > 20 > 1 > 
// which element you want to search: 20
// 20 exist in tree
// which element you want to delete: 24
// inorder traversal after deleting: 1 > 4 > 11 > 20 > 36 > 