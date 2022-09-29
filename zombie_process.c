// A C program to demonstrate working of
// fork() and process table entries.
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

void myfunc(int Sig_num)
{
    printf("got signal%d",Sig_num);
}
 
int main()
{
    int i;
    int pid = fork();
 
    if (pid == 0)
    {
        for (i=0; i<20; i++)
            printf("I am Child\n");
    }
    else
    {
        //signal(SIGCHLD,SIG_IGN);
        signal(SIGCHLD,myfunc);
        printf("I am Parent\n");
        while(1);
    }
}