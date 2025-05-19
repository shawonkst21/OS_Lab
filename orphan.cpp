#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;
int main(){
    pid_t p=fork();
    if(p==0){
     cout<<"child process pid:"<<getpid()<<endl;
     cout<<"parent process pid:"<<getppid()<<endl;
     }
     else{
       cout<<"my pid(parent):"<<getpid()<<endl;
       cout<<"my child pid:"<<p<<endl;
      }
}
