#include<iostream>
using namespace std;
void bestfit(int n, int*pi, int* p2)
{
	int*flagarr = new int[n];
	for(int i=0;i<n;i++)
	{
		flagarr[i]=0;
	}
	int*store_arr = new int[n];
	for(int i=0;i<n;i++)
	{
		store_arr[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		int temp = p1[i];
		//cout<<"temp= "<<temp<<"\n";
		for(int j=0;j<n;j++)
		{
			if(p2[j]>=temp)
			{
				store_arr[j]=p2[j]-temp;
			}
		}
		int posn = 0;
		int min = store_arr[0];
		for(int k=0;k<n;k++)
		{
			if(p2[k]<min)
			{
				min = p2[k];
				posn = k;
			}
		}

	}
	delete [] flagarr;
}
void firstfit(int n, int*p1, int*p2)
{
	int*flagarr = new int[n];
	for(int i=0;i<n;i++)
	{
		flagarr[i]=0;
	}
	for(int i=0;i<n;i++)
	{
		int temp = p1[i];
		//cout<<"temp= "<<temp<<"\n";
		for(int j=0;j<n;j++)
		{
			//cout<<"p2[j] = "<<p2[j]<<"\n";
			if(p2[j]>=temp)
			{
				//cout<<"\n"<<p2[j]<<"\n";
				if(flagarr[j]==0)
				{
					flagarr[j]++;
					cout<<"p"<<i<<": "<<p2[j]<<"\n";
					break;
				}
				else
				{
					continue;
				}
			}
			else if(j==n-1)
			{
				cout<<"p"<<i<<": wait\n";
			}
		}

	}
	delete [] flagarr;
}
int main()
{
	int np;
	int* processarr;
	int* partitionarr;
	cout<<"enter the number of processes and partitions\n";
	cin>>np;
	processarr = new int[np];
	partitionarr = new int[np];
	cout<<"enter the process array\n";
	for(int i=0;i<np;i++)
	{
		cout<<"p"<<i<<": ";
		cin>>processarr[i];
	}
	cout<<"enter the partitions\n";
	for(int i=0;i<np;i++)
	{
		cin>>partitionarr[i];
	}
	cout<<"first fit:\n";
	firstfit(np,processarr,partitionarr);
	//cout<<"best fit:\n";
	//bestfit(np,processarr,partitionarr);
	//cout<<"worst fit\n";
	//worstfit(np,processarr,partitionarr);
	delete [] processarr;
	delete [] partitionarr;
	return 0;
}