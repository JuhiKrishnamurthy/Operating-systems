#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int queue[8];
    int head=0;
    int dist = 0;
    int sum =0;
    cout<<"enter the queue\n";
    for(int i=0;i<8;i++)
    {
        cin>>queue[i];
    }
    cout<<"enter the current position of head\n";
    cin>>head;
    for(int i=0;i<8;i++)
    {
        if(i==0)
        {
            dist = abs(head - queue[i]);
        }
        else
        {
            dist=abs(queue[i]-queue[i-1]);
        }
        sum = sum+dist;
    }
    cout<<"the FCFS sequence is :\n";
    cout<<head<<"->";
    for(int i=0;i<7;i++)
    {
        cout<<queue[i]<<"->";
    }
    cout<<queue[7]<<"\n";
    cout<<"total distance : "<<sum<<"\n";
    return 0;
}
//fcfs :just do in order given
//scan : sort, go head to end and reverse, and on way back complete tasks before head
//cscan :sort, go from head to end , then from end to begin then end to head.
//look : sort , go from head to last, then from last, reverse and on way back, complete tasks before head
//clook : sort, go from head to last , go from last to begin, go from begin to head.
