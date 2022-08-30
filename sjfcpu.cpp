#include<iostream>
using namespace std;
struct process{
	int pno;
	int at;
	int bt;
};
void swap(process* a, process* b)
{
	process c =*a;
	*a=*b;
	*b=c;
	return;
}
int main()
{
	float avgwt=0;
	float avgtat=0;
	int n;
	int time_elapsed=0;
	cout<<"enter the number of processes\n";
	cin>>n;
	process* processes = new process [n];
	cout<<"enter the process number, arrival and burst times\n";
	for(int i=0;i<n;i++)
	{
		cout<<"process ";
		cin>>processes[i].pno;
		cin>>processes[i].at;
		cin>>processes[i].bt;
	}
	//sorting acc to at;
	for (int i = 0; i < n-1; i++)	
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (processes[j].at > processes[j+1].at)
			{
				swap(&processes[j], &processes[j+1]);
			}
		}	
	}
	//sorting acc to bt;
	for (int i = 0; i < n-1; i++)	
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (processes[j].bt > processes[j+1].bt)
			{
				swap(&processes[j], &processes[j+1]);
			}
		}	
	}
	cout<<"the FCFS cpu scheduling algorithm will be implemented as:\n";
	for(int i=0;i<n;i++)
	{
		avgwt += time_elapsed-processes[i].at;
		cout<<"process number "<<processes[i].pno<<"\n";
		cout<<"starts at: "<<time_elapsed<<"\n";
		cout<<"ends at: "<<processes[i].bt+time_elapsed<<"\n";
		avgtat+=processes[i].bt+time_elapsed - processes[i].at;
		time_elapsed+=processes[i].bt; 
	}
	avgwt=float(avgwt)/(float)n;
	avgtat=float(avgtat)/(float)n;
	cout<<"average wait time: "<<avgwt<<"\n";
	cout<<"average turn around time: "<<avgtat<<"\n";
	delete [] processes;
	return 0;
}