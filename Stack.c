#include<stdio.h>
#include<stdlib.h>
# define max 6

int stack[max];
int ToS=-1;

void push(int d)
{
    if(ToS==max-1)
    printf("Stack Overflow\n");
    else
    {
        ToS++;
        stack[ToS]=d;
    }
}

int pop()
{
    int d;
    if(ToS==-1)
    return -1;
    d=stack[ToS];
    ToS--;
    return d;
}

void display()
{
    int i;
    for(i=ToS; i>=0; i--)
    {
        printf("%d\n",stack[i]);
    }
}

int main()
{
    int choice,data;
    do
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter the data to be pushed:");
            scanf("%d",&data);
            push(data);
            break;
            case 2:data=pop();
            if(data!=-1)
            printf("The data that is poped is:%d\n",data);
            else
            printf("Stack Underflow\n");
            break;
            case 3:display();
            break;
            case 4:break;
            default:printf("Invalid choice\n");
        }
    }while(choice!=4);
    return 0;
}