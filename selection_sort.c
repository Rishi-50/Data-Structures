#include<stdio.h>
#include<conio.h>

void selection_sort(int a[100],int n)
{
    int i,j,min,temp;
    for(i=0;i<=n-2;i++)
    {
        min=i;
        for(j=i+1;j<=n-1;j++)
        {
            if(a[j]<a[min])
            min=j;
        }
        if(min!=i)
        {
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
        }
    }

}

int main()
{
    int i,n,a[100];
    printf("Enter the number of elements:");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        printf("Enter the value:");
        scanf("%d",&a[i]);
    }
    selection_sort(a,n);
    printf("After Sorting:\n");
    for(i=0;i<=n-1;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
} 