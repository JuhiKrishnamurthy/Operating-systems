#include<iostream>
#include<vector>
using namespace std;
struct process{
	int pno;
	int at;
	int bt;
	//int priority;

	int first_scheduled_time;
	int finish_time;

	int wait_time()
	{
		return (first_scheduled_time - at);
	}
	int turn_around_time()
	{
		return (finish_time - at);
	}
};

int main()
{
	vector<int>queue;
	int time_slice;
	int n;
	process* p_arr;
	cout<<"enter the number of processes\n";
	cin>>n;
	p_arr= new process[n];
	cout<<"enter the time slice\n";
	cin>>time_slice;
	cout<<"enter the process number, arrival time, burst time for the processes\n";
	for(int i=0;i<n;i++)
	{
		cout<<"pno: ";
		cin>>p_arr[i].pno;
		cout<<"at: ";
		cin>>p_arr[i].at;
		cout<<"bt: ";
		cin>>p_arr[i].bt;
	}
	int* rem_arr = new int[n];
	for(int i=0;i<n;i++)
	{
		rem_arr[i] = p_arr[i].bt;
	}
	int* flag_arr = new int[n];
	for(int i=0;i<n;i++)
	{
		flag_arr[i] = 0;
	}
	int flag =-1;
	int time =0;
	while(flag!=1)
	{
		flag = -1;
		bool time_updated = false;
		for(int i=0;i<n;i++)
		{
			//DEBUG
			//cout <<"i = "<<i <<" time = " <<time << " flag_arr[i] = " <<flag_arr[i] <<" p_arr[i].at = "<< p_arr[i].at <<"\n";
			//END Debug

			if( (flag_arr[i]!=1)  &&  // process had not finshed
			    (p_arr[i].at <= time) //process has already arrived 
				) 
			{
				// if(rem_arr[i]<=time_slice)
				// {
				// 	rem_arr[i]=time_slice - rem_arr[i];
				// 	queue.push_back(i);
				// 	if(rem_arr[i]==0)
				// 	{
				// 		flag_arr[i]=1;
				// 	}
				// }
				queue.push_back(i);
				//if this is the first time process is being scheduled, update
				//first_scheduled time
				if(rem_arr[i] == p_arr[i].bt)
				{
					//remaing time is same as burst time, so it is first scheduling
					p_arr[i].first_scheduled_time = time;
				}
				int run_time =(rem_arr[i] > time_slice)? time_slice:rem_arr[i];
				rem_arr[i] -= run_time;
				if (rem_arr[i] == 0)
				{
					flag_arr[i] = 1;
					//update the finish time of process
					p_arr[i].finish_time = time+run_time;
				}
				//update time also
				time += run_time;
				time_updated = true;
			}
		}
		if (time_updated == false)
		{
			//there were no processes in the system at this time, advance the time by 1
			time++;
		}
		for(int j=0;j<n;j++)
		{
			if(flag_arr[j]==0)
			{
				flag = 0;
				continue;
			}
		}
		if(flag == -1)
		{
			flag = 1;
		}
	}
	cout<<"the round robin sequence is : \n";
	for(int i = 0;i<queue.size();i++)
	{
		cout<<queue[i]<<" ";
	}
	cout<<"\n";

	float avg_wait_time = 0.0;
	float avg_turn_around_time = 0.0;
	for (int i =0; i <n; i++)
	{
		avg_wait_time += p_arr[i].wait_time();
		avg_turn_around_time += p_arr[i].turn_around_time();
	}
	avg_wait_time /= n;
	avg_turn_around_time /= n;

	cout <<"average wait time = " << avg_wait_time <<"\n";
	cout <<"average turn around time = " << avg_turn_around_time <<"\n";


	delete [] p_arr;
	delete [] rem_arr;
	delete [] flag_arr;
	return 0;
}