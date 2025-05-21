#include<bits/stdc++.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
using namespace std;
queue<int>buffer;
int max_size=5;
sem_t sem_empty,sem_full;
pthread_mutex_t sem_mutex;
void *producer(void*arg)
{
	int i=0;
	while(true)
	{
		sleep(1);
		sem_wait(&sem_empty);
		pthread_mutex_lock(&sem_mutex);
		
		buffer.push(i);
		cout<<"produced: "<<i<<endl;
		i++;

		pthread_mutex_unlock(&sem_mutex);
		sem_post(&sem_full);
	}
	return nullptr;
}
void *consumer(void*arg)
{
        
        while(true)
        {
                sleep(1);
                sem_wait(&sem_full);
                pthread_mutex_lock(&sem_mutex);

                int item=buffer.front();
		buffer.pop();
                cout<<"consumed: "<<item<<endl;
                

                pthread_mutex_unlock(&sem_mutex);
                sem_post(&sem_empty);
		sleep(2);
        }
        return nullptr;
}
int main()
{
	pthread_t t1,t2;
	sem_init(&sem_empty,0,max_size);
	sem_init(&sem_full,0,0);
	pthread_mutex_init(&sem_mutex,NULL);
	
	pthread_create(&t1,NULL,producer,NULL);
	pthread_create(&t2,NULL,consumer,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	pthread_mutex_destroy(&sem_mutex);
	sem_destroy(&sem_empty);
	sem_destroy(&sem_full);
}
