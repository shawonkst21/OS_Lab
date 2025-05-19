#include<bits/stdc++.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
using namespace std;
int main()
{
         pid_t p,p1,p2;
         p1=fork();
         if(p1==0)
            {
                cout<<"i am p1 process and my parent is p"<<getppid()<<endl;
                p2=fork();
                if(p2==0)
                   {
                      cout<<"i am the second p2 process and my parent p1"<<getppid()<<endl;

                   }
                else{
                       wait(NULL);
                    cout<<"i am the p1 process and my pid"<<getpid()<<endl;
                    }
            }
        else
            {
                 wait(NULL);
               cout<<"i am the p process and my pid "<<getpid()<<endl;

            }
}

