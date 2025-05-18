#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
  int n,fd,fd1;
  fd=open("test.txt",O_RDONLY);
  char b[30];
  n=read(fd,b,10);
  fd1=open("target",O_CREAT|O_WRONLY,0642);
  write(fd1,b,n);
}

