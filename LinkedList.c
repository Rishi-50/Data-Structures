#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};
struct Node * Start;

// Functions For INSERTION in a LL

void insertBegin(int d)
{
    struct Node *p;
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=d;
    p->next=Start;
    Start=p;
}

void insertEnd(int d)
{
    struct Node *p,*ptr;
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=d;
    ptr=Start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    p->next=NULL;
    ptr->next=p;
}

void insertAt(int value,int posi)
{
    int count=0;
    struct Node *p,*ptr;
    p=(struct Node *)malloc(sizeof(struct Node));
    p->data=value;
    ptr=Start;
    if(posi==1) insertBegin;
    else
    {
        while(count<=posi)
        {
            ptr=ptr->next;
            count++;
        }
        p->next=ptr->next;
        ptr->next=p;
    }
}

// Functions For DELETION in a LL

int deleteBegin()
{
    int x;
    struct Node *p;
    if(Start==NULL) return -1;
    p=Start;
    x=Start->data;
    Start=Start->next;
    free(p);
    return x;
}

int deleteEnd()
{
    int x;
    struct Node *p,*q;
    p=Start;
    if(Start->next==NULL)
    {
        x=deleteBegin();
        return x;
    }
    while(p->next->next!=NULL)
    {
        p=p->next;
    }
    q=p->next;
    x=q->data;
    free(q);
    return x;
}

int deleteAt(int posi)
{
    int x,i;
    struct Node *p,*q;
    p=Start;
    for (i=0; i<=posi && p!=NULL; i++)
    {
        p=p->next;
    }
    q=p->next;    
    p->next=q->next;    
    x=q->data;
    free(q);
    return x;
}

void display()
{
    struct Node *p=Start;
    while(p->next!=NULL)
    {
        printf("%d\n",p->data); 
        p=p->next;
    }

}

int main()
{
    int i,n,d,posi,choice,ch;
	struct Node *temp;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	printf("Enter the element:");
	scanf("%d",&d);
	Start=temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=d;
	temp->next=NULL;
	for(i=2;i<=n;i++)
	{
		temp->next=(struct Node*)malloc(sizeof(struct Node));
		temp=temp->next;
		printf("Enter the element:");
		scanf("%d",&temp->data);
		temp->next=NULL;
	}
	display();

	do
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Insert at\n1.Begninning\n2.End\n3.At given position\nEnter your choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 3:printf("Enter the element to be inserted and its position:");
				scanf("%d %d",&d,&posi);
				insertAt(d,posi);
				break;
				case 1:printf("Enter the element to be inserted at beginning:");
				scanf("%d",&d);
				insertBegin(d);
				break;
				case 2:printf("Enter the element to be inserted at the end:");
				scanf("%d",&d);
				insertEnd(d);
				break;
				default:printf("Invalid choice\n");
			}
			break;
			case 2:printf("1.Beginning\n2.End\n3.At given position\nEnter your choice:");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:d=deleteBegin();
				if(d==-1) printf("List is empty\n");
				else printf("Value deleted is: %d\n",d);
				break;
				case 2:d=deleteEnd();
				if(d==-1) printf("List is empty\n");
				else
				printf("Value deleted is:%d\n",d);
				break;
				case 3:printf("Enter the location:");
				scanf("%d",&posi);
				d=deleteAt(posi);
				if(d==-1) printf("Position not found\n");
				else printf("Value deleted is:%d\n",d);
				break;
				default:printf("Invalid choice\n");
			}
			break;
			case 3:display();
			break;
			case 4:break;
			default:printf("Invalid choice");
		}
	}while(choice!=4);
    return 0;
}