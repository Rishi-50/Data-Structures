#include<stdio.h>
#include<conio.h>

int BinarySearch(int a[100],int n,int search)
{
	int start=0,end=n-1,mid;
	mid = (start+end)/2;
	while (start<=end)
	{
		if(a[mid]==search) return mid;
		if(a[mid]<search) end=mid-1;
		else start=mid+1;
		mid=(start+end)/2;
	}
	return n;
}

int main()
{
	int i,n,a[100],j,temp,search;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    for(i=0;i<=n-1;i++)
    {
        printf("Enter the value:");
        scanf("%d",&a[i]);
    }
    printf("Enter the value to be searched for:");
	scanf("%d",&search);
	for(i=0;i<=n-2;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("Sorted List:\n");
	for(i=0;i<=n-1;i++)
    {
        printf("%d\n",a[i]);
    }
	i=BinarySearch(a,n,search);
	if(i==n) printf("Element not found");
	else printf("Element found at index: %d",i);
	return 0;
}