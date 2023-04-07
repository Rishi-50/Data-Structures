#include <stdio.h>
#include<stdlib.h>
#define TABLE_SIZE 10

int h[TABLE_SIZE]={NULL};

void insert()
{
    int key,index,i,flag=0,hkey;
    printf("\nEnter the value to be inserted into the hash table:");
    scanf("%d",&key);
    hkey=key%TABLE_SIZE;
    for(i=0;i<TABLE_SIZE;i++)
    {
        index=(hkey+i)%TABLE_SIZE;
        if(h[index] == NULL)
        {
            h[index]=key;
            break;
        }
    }
    if(i == TABLE_SIZE)
        printf("\nElement cannot be inserted\n");
}

void display()
{
    int i;
    printf("\nElements in the Hash table are:\n");
    for(i=0;i< TABLE_SIZE; i++)
        printf("\nAt index %d \t value =  %d",i,h[i]);

}
int main()
{
    int opt,i;
    do
    {
        printf("\nPress 1. Insert\t 2. Display \t3. Exit \n");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                insert();
                break;
            case 2:
                display();
                break;
            case 3:exit(0);
        }
    }while(opt!=3);
    return 0;
}
