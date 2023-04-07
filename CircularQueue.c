#include<stdio.h>
#include<stdlib.h>

# define max 6

int queue[max],front=-1,rear=-1;

void enqueue(int d)
{
    if ((rear+1)%max==front)
    printf("Queue is Full\n");
    else
    {
        rear=(rear+1)%max;
        queue[rear]=d;
    }
}

int dequeue()
{
    int d;
    d=queue[front];
    front++;
    return d;
}

void display()
{
    int i;
	printf("Queue contains:\n");
	for(i=front; i!=rear; i=(i+1)%max)
	{
		printf("%d\n",queue[i]);
	} 
    if(front!=-1) printf("%d\n",queue[i]);
}

int main()
{
    int choice, data;
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter the number to be enqueued:");
            scanf("%d",&data);
            enqueue(data);
            break;
            case 2: data=dequeue();
            if (data!=-1)
            printf("The number that is dequeued is:%d",data);
            else ("The Queue is Empty\n");
            break;
            case 3: display();
            break;
            case 4: break;
            default: printf("Invalid Choice\n");        }
    } while(choice!=4);
    return 0;
}