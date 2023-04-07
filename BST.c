#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int key;
    struct Node *left,*right;
}Node;

Node* insert(Node *T, int n)
{
    if(T==NULL)
    {
        T = (Node *)malloc(sizeof(Node));
        T->key = n;
        T->left = NULL;
        T->right = NULL;
        return T;
    }
    if(n > T->key)
    {
        T->right = insert(T->right,n);
        return T;
    }
    T->left = insert(T->left,n);
    return T; 
}

Node *delete(Node *T,int n)
{
    Node *temp;
    if(T==NULL)
    {
        printf("Not Found\n");
        return NULL;
    }
    if(n > T->key)
    {
        T->right = delete(T->right,n);
        return T;
    }
    if(n < T->key)
    {
        T->left = delete(T->left,n);
        return T;
    }
    if(T->left == NULL && T->right == NULL)
    {
        free(T);
        return NULL;
    }
    if(T->left == NULL)
    {
        temp = T->right;
        free(T);
        return temp;
    }
    if(T->right == NULL)
    {
        temp = T->left;
        free(T);
        return temp;
    }
}

void display(Node *T)
{
    if(T!=NULL)
    {
        display(T->left);
        printf("%d ",T->key);
        display(T->right);
    }
}

Node *find(Node *T,int n)
{
    if(T==NULL) return NULL;
    if(n==T->key) return T;
    if(n < T->key) return (find(T->left,n));
    return(find(T->right,n));
}

int main()
{
    Node *root=NULL,*temp;
    int choice,n;
    do
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Find\n5.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:printf("Enter the number to be inserted:");
            scanf("%d",&n);
            root = insert(root,n);
            break;

            case 2:printf("Enter the number to be deleted:");
            scanf("%d",&n);
            root = delete(root,n);
            break;

            case 3:display(root);
            break;

            case 4:printf("Enter the number to be found:");
            scanf("%d",&n);
            temp = find(root,n);
            if(temp==NULL) 
            printf("Element not found\n");
            else 
            printf("Found the element with address: %p",temp);
            break;

            case 5:break;

            default: printf("Invalid choice\n");
        }
    }while(choice!=5);
    return 0;
}

