#include<bits/stdc++.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;
void *thread_function(void *arg);
struct threadData{
    int a;
    int b;
};
int main()
{
	pthread_t a_thread;
	void *result;
	threadData* data=new threadData();
        data->a=5;
	data->b=3;
        pthread_create(&a_thread,NULL,thread_function,(void *)data);
	pthread_join(a_thread,&result);
        int *val=(int *)result;
        cout<<"inside the main process"<<endl;
	cout<<"return valude from thread"<<*val<<endl;
        delete val;
}
void *thread_function(void *arg)
{
	threadData* data= (threadData*)arg;
      
        int sum=data->a+data->b;
	cout<<"inside thread function:"<<endl;
        cout<<"the sum:"<<sum<<endl;
        int *res=new int (sum);
 	pthread_exit((void *)res);
}
