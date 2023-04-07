#include<stdio.h>
#include<conio.h>
void bubble_sort(int a[100],int n)
{
	int i,j,temp;
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
}
int main()
{
	int a[100],i,n;
	printf("Enter the number of elements:");
	scanf("%d",&n);
	for(i=0;i<=n-1;i++)
	{
		printf("Enter the element:");
		scanf("%d",&a[i]);
	}
	bubble_sort(a,n);
	printf("After sorting:\n");
	for(i=0;i<=n-1;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}