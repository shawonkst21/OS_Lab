#include<bits/stdc++.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;
void *thread_function(void *arg);
int i;
int main()
{
	pthread_t a_thread;//thread declare
	pthread_create(&a_thread,NULL,thread_function,NULL);//thread create
	pthread_join(a_thread,NULL);
	
	cout<<"inside main program:"<<endl;
	for(i=0;i<10;i++)
	  {
		cout<<"main"<<endl;
		sleep(1);
	  }
	
}
void *thread_function(void *arg)
{
	cout<<"inside the thread:"<<endl;
	for(i=0;i<4;i++)
	 {
		cout<<i<<endl;
		sleep(1);
	 }
}
