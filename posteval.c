/*Apply stack to perform Postfix evaluation*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define n 5

int top=-1;
int stack[n];

char pop()
{	
	char t; 
	t=stack[top];
	stack[top]=-1;
	top--;
	return t;
}

int isoperator(char symb)
{
	if(symb=='+' || symb=='*' || symb=='/' || symb=='-')
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}

void push(char val)
{
	top++;
	stack[top]=val;
}

int operations(char symb,int a,int b)
{
	switch(symb)
	{
		case '/':
		{
			return a/b;
		}
		
		case '*':
		{
			return a*b;
		}
		
		case '+':
		{
			return a+b;
		}
		
		case '-':
		{
			return a-b;
		}
		
		default:
		{
			return 0;
		}
	}
}

void main()
{
	char exp[100];
	int z,w,i,g,h;
	char x,y;
	printf("\n ENTER EXPRESSION ");
	fgets(exp,sizeof(exp),stdin);
	for(i=0;exp[i]!='\0';i++)
	{
		if(isalnum(exp[i]))
		{
			push(exp[i]);
		}
		
		else 
		{
			x=pop();
			y=pop();
			g=atoi(x);
			h=atoi(y);
			z=operations(exp[i],g,h);
			push(itoa(z));
		}
	}
	w=pop();
	printf("%d",w);
}
			
			
			
