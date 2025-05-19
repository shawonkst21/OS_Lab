#include<bits/stdc++.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<sys/wait.h>
using namespace std;
int main()
{
	pid_t p,fd,n;
	char b[100];
	p=fork();
	if(p==0)
	{
		cout<<"i am the child process"<<endl;
		fd=open("Relation.txt",O_CREAT,0777);
 		close(fd);
	}
	else
	{
		wait(NULL);
		n=read(0,b,100);
		fd=open("Relation.txt",O_RDWR);
		write(fd,b,n);
	}
}
