#include<bits/stdc++.h>
#include<unistd.h>
#include<pthread.h>
using namespace std;
int readCount = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t writeLock = PTHREAD_MUTEX_INITIALIZER;

void* reader(void* arg) {
    while (true) {
        pthread_mutex_lock(&mutex);
        readCount++;
        if (readCount == 1) pthread_mutex_lock(&writeLock);
        pthread_mutex_unlock(&mutex);

        cout << "Reader is reading\n";
        sleep(1);

        pthread_mutex_lock(&mutex);
        readCount--;
        if (readCount == 0) pthread_mutex_unlock(&writeLock);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return nullptr;
}
void* writer(void* arg) {
    while (true) {
        pthread_mutex_lock(&writeLock);

        cout << "Writer is writing\n";
        sleep(2);

        pthread_mutex_unlock(&writeLock);
        sleep(2);
    }
    return nullptr;
}
int main() {
    pthread_t r1, r2, w1;

    pthread_create(&r1, nullptr, reader, nullptr);
    pthread_create(&r2, nullptr, reader, nullptr);
    pthread_create(&w1, nullptr, writer, nullptr);

    pthread_join(r1, nullptr);
    pthread_join(r2, nullptr);
    pthread_join(w1, nullptr);

    return 0;
}
