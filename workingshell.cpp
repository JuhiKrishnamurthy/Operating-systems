#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<vector>
#include<iostream>
using namespace std;
#define MAXLIST 1024
void parseSpace(char* str,char** parsed)
{
	int i;

	for (i = 0; i < MAXLIST; i++) {
		parsed[i] = strsep(&str, " ");

		if (parsed[i] == NULL)
			break;
		if (strlen(parsed[i]) == 0)
			i--;
	}
}
// const char** split_by_space(string &str)
// {
// 	vector<string>V;
// 	istringstream iss(str);
//   	string s;
//   	while ( getline( iss, s, ' ' ) ) 
//   	{
//     	//printf( "`%s'\n", s.c_str() );
//     	V.push_back(s);
// 	}
// 	int i=0;
// 	const char** retarr = new const char*[V.size()];
// 	for(auto it = V.begin();it!=V.end();it++)
// 	{
// 		retarr[i] = it->c_str();
// 		i++;
// 	}
// 	return retarr;
// }
int main()
{
	while(1)
	{
		string cmandargs;
		char cwd[1024];
		getcwd(cwd, sizeof(cwd));
		cout<<cwd;
		cout<<"->>";
		cin>>cmandargs;
		int pid = fork();
		if(pid<0)
		{
			cout<<"error in fork() \n";
			continue;
		}
		else if(pid == 0)
		{
			//run command
			//const char**splitargs=split_by_space(cmandargs);
			char* parsed[MAXLIST];
			char ss[MAXLIST];
			strcpy(ss,cmandargs.c_str());
			parseSpace(ss,parsed);
			execvp(parsed[0],parsed);
			exit(0);
		}
		else
		{
			wait(NULL);
		}
	}
	return 0;
}