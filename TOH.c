#include<stdio.h>
#include<conio.h>

void TOH(int n,char x,char y,char z)
{
    if(n>0)
    {
        TOH(n-1,x,y,z);
        printf("Disk %d moves from %c to %c\n",n,x,y);
        TOH(n-1,z,y,x);
    }
}

int main()
{
    int n;
    printf("Enter the number of rings:");
    scanf("%d",&n);
    TOH(n,'f','s','t');
    return 0;
}