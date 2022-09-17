#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	int child_pid;
	int a,b,c;
	printf("enter three numbers\n");
	scanf("%d",&a);
	scanf("%d",&b);
	scanf("%d",&c);
	child_pid = fork();
	if(child_pid<0)
	{
		printf("error in fork\n");
	}
	else if(child_pid==0)
	{
		printf("entered child process\n");
		if(a>b)
		{
			if(a>c)
			{
				printf("%d is largest\n",a);
			}
			else if(c>b)
			{
				printf("%d is largest\n",c);
			}
		}
		else if(b>c)
		{
			printf("%d is largest\n",b);
		}
		else
		{
			printf("%d is largest\n",c);
		}
		printf("exiting child process\n");
	}
	else
	{
		wait(NULL);
		printf("entered parent process\n");
		// compute min of 3 numbers and assign to a variable.
		if(a<b)
		{
			if(a<c)
			{
				printf("%d is smallest\n",a);
			}
			else if(c<b)
			{
				printf("%d is smallest\n",c);
			}
		}
		else if(b<c)
		{
			printf("%d is smallest\n",b);
		}
		else
		{
			printf("%d is smallest\n",c);
		}
		// output the minimum


		exit(0);
	}
}