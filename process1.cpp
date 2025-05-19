#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
using namespace std;
int main(){
    pid_t q;
    cout<<"Not create any process"<<endl;
    q=fork();
     
     if(q<0){
      cout<<"failed to create process"<<endl;
      }
      
      else if(q==0){
       sleep(3);
       cout<<"my parent process pid "<<getppid()<<endl;
         cout<<"i am child:"<<getpid()<<endl;
       }
       else{
        cout<<"my process pid "<<getpid()<<endl;
        cout<<"my child process pid "<<q<<endl;
         }
       cout<<"common"<<endl;
}


