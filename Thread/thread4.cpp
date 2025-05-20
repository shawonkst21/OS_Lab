#include<bits/stdc++.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;
struct ThreadData{
   int *arr;
   int size;
};
void *thread_function(void *arg);
int main()
{
	pthread_t a_thread;
	void *result;
	ThreadData* data=new ThreadData();
        cout<<"enter the array size:"<<endl;
	int n;
	cin>>n;
	int *arr=new int[n];
        cout<<"enter element"<<endl;
	for(int i=0;i<n;i++)
	  {
		cin>>arr[i];
	  }
 	data->arr=arr;
	data->size=n;

	pthread_create(&a_thread,NULL,thread_function,(void*)data);
	pthread_join(a_thread,&result);
        int *val=(int*)result;
        cout<<"return value from thread: "<<*val<<endl;
}
void *thread_function(void*arg)
{
 	ThreadData* data=(ThreadData*)arg;
	 int *arr=data->arr;
         int size=data->size;

         int sum=0;

 	for(int i=0;i<size;i++)
	   {
		sum+=arr[i];
	   }
        int *res=new int(sum);
	pthread_exit((void *)res);
}
