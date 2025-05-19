#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;
int main(){
    pid_t p1,p2;
    p1=fork();
    if(p1==0){
      cout<<"i am the first child:"<<getpid()<<endl;
      cout<<"my parent pid is :"<<getppid()<<endl;
     }
     else{
        wait(NULL);
       p2=fork();
      if(p2==0){
         cout<<"i am the second child:"<<getpid()<<endl;
         cout<<"my parent pid is:"<<getppid()<<endl;
         }
        else{
            wait(NULL);
            cout<<"i am the parent of p1 and p2 childs"<<endl;
             cout<<"my pid is: "<<getpid()<<endl;
           }
       }
}
