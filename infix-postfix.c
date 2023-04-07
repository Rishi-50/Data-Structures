#include<stdio.h>
#include<conio.h>

char stack[50];
int ToS=-1,max=50;
int assoc(char x)
{
	if(x=='^') return 1;
	else return 2;
}
int prec(char op)
{
	if(op=='^') return 3;
	if(op=='*' || op=='/') return 2;
	return 1;
}
void push(char x)
{
	if(ToS==max-1)
	{
		printf("Overflow\n");
	}
	ToS++;
	stack[ToS]=x;
}
char pop()
{
	char x;
	if(ToS==-1)
	return -1;
	x=stack[ToS];
	ToS--;
	return x;
}
char peek()
{
	char x;
	if(ToS==-1)
	return -1;
	x=stack[ToS];
	return x;
}
int main()
{
	char infix[50],postfix[50],ch,ch1;
	int i,j=0;
	printf("Enter the expression in infix form:");
	gets(infix);
	printf("Infix expression is: %s",infix);
	for(i=0;infix[i]!=0;i++)
	{
		ch=infix[i];
		if((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')||(ch>='0' && ch<='9'))
		postfix[j++]=ch;
		else if(ch=='(') push(ch);
		else if(ch==')')
		{
			while(peek()!='(')
			{
				ch1=pop();
				postfix[j++]=ch1;
			}
			pop();
		}
		else if(peek()==-1 || peek()=='(')
		push(ch);
		else if(prec(ch)>prec(peek())) push(ch);
		else if(prec(ch)<prec(peek()))
		{
			ch1=pop();
			postfix[j++]=ch1;
			i--;
			continue;
		}
		else if(assoc(ch)==2)
		{
			ch1=pop();
			postfix[j++]=ch1;
			push(ch);
		}
		else push(ch);
	}
	while(peek()!=-1)
	{
		ch1=pop();
		postfix[j++]=ch1;
	}
	postfix[j]=0;
	printf("\nPostfix expression: %s",postfix);
	return 0;
}