#include<stdio.h>
#include<conio.h>

void insertion_sort(int a[100],int n)
{
    int i,temp,j;
    for(i=1;i<=n-1;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0 && a[j]>temp;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
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
    insertion_sort(a,n);
    printf("After Sorting:\n");
    for(i=0;i<=n-1;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
} 