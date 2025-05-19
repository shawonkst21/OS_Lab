#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h> // for exit()

using namespace std;

int main() {
    pid_t q;
    cout << "Not create any process" << endl;
    q = fork();

    if (q < 0) {
        cout << "Failed to create process" << endl;
        exit(1); // Exit with error
    }
    else if (q == 0) {
        // This is the child process
        cout << "My parent process PID: " << getppid() << endl;
        cout << "I am child: " << getpid() << endl;
        cout << "Common" << endl;
        exit(0); // Child exits
    }
    else {
        // This is the parent process
        cout << "My process PID: " << getpid() << endl;
        cout << "My child process PID: " << q << endl;
        cout << "Common" << endl;
        exit(0); // Parent exits
    }
}
