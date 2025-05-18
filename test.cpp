#include<unistd.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
   char b[30];
   read(0,b,10);
   n=write(1,b,10);
   cout<<n<<endl;
}
