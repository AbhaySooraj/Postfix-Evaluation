/*Apply stack to perform Postfix evaluation*/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#define n 5

int top=-1;
int stack[n];

int pop()
{	
	int t; 
	t=stack[top];
	stack[top]=-1;
	top--;
	return t;
}

void push(int val)
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
	char *ptr;
	int w,x,y,z;
	printf("\n ENTER EXPRESSION ");
	scanf("%s",exp);
	ptr=exp;
	while(*ptr != '\0')
    	{
        	if(isdigit(*ptr))
        	{
        	    w= *ptr - 48;
        	    push(w);
        	}
        	else
        	{
        	    x = pop();
        	    y = pop();
        	    z=operations(*ptr,y,x);
        	    push(z);
        	}
        	ptr++;
        }
        printf("The result is %d",pop());
}
