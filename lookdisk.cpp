#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int* queue;
    int n;
    int head=0;
    int dist = 0;
    int sum =0;
    cout<<"enter the number of entries in  the queue (last entry is the absolute ond of disk)\n";
    cin>>n;
    queue= new int[n];
    cout<<"enter the queue\n";
    for(int i=0;i<n;i++)
    {
        cin>>queue[i];
    }
    cout<<"enter the current position of head in queue\n";
    cin>>head;
    //sort the queue
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(queue[j]>queue[j+1])
            {
                int temp = queue[j];
                queue[j]=queue[j+1];
                queue[j+1]=temp;
            }
        }
    }
    for(int i=head;i<n-2;i++)
    {
        dist=abs(queue[i]-queue[i+1]);
        sum = sum+dist;
    }
    if(head!=0)
    {
        sum+=(abs(queue[n-2]-queue[head-1]));
    }
    for(int i = head-1;i>0;i--)
    {
        dist=abs(queue[i]-queue[i-1]);
        sum+=dist;
    }
    cout<<"the LOOK sequence is :\n";
    cout<<queue[head]<<"->";
    for(int i=head+1;i<n-1;i++)
    {
        cout<<queue[i]<<"->";
    }
    //cout<<queue[n-1];
    for(int i=head-1;i>0;i--)
    {
        cout<<queue[i]<<"->";
    }
    if(head!=0)
    {
        cout<<queue[0];
    } 
    cout<<"\ntotal distance : "<<sum<<"\n";
    return 0;
}
//fcfs :just do in order given
//scan : sort, go head to end and reverse, and on way back complete tasks before head
//cscan :sort, go from head to end , then from end to begin then end to head.
//look : sort , go from head to last, then from last, reverse and on way back, complete tasks before head
//clook : sort, go from head to last , go from last to begin, go from begin to head.
