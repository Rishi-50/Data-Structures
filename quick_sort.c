#include<stdio.h>
#include<conio.h>

int partition(int a[],int low,int high)
{
    int v = a[low];
    int i = low+1;
    int j = high;
    int temp;
    do
    {
        while(a[i]<v)
        {
            i++;
        }
        while(a[j]>v)
        {
            j--;
        }
        if (i<j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i<j);
    
    temp = a[low];
    a[low] = a[j];
    a[j] = temp;
    return j;
}

void quicksort(int a[],int low,int high)
{
    int v;
    if (low<high)
    {
        v = partition(a,low,high);
        quicksort(a,low,v-1);
        quicksort(a,v+1,high);
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
    quicksort(a,0,n-1);
    printf("After Sorting:\n");
    for(i=0;i<=n-1;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
} 