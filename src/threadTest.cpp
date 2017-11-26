#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>

using namespace std;

bool on = true;

void threadFunction(long threadID) {
    while( on )
    {
        cout << "[thread " << threadID << "]" << endl;
        usleep(1000);
    }
}


int main(int argc, char** argv)
{
    if ( argc != 2 )
    {
        cerr << "Usage: " << argv[0] << " <number of threads>" << endl;
        return -1; 
    }

    long threadCount = atol(argv[1]);

    cout << "[main]: spawning " << threadCount << " threads..." << endl;

    for (long i = 0; i < threadCount; i++)
    {
        thread buffer(threadFunction, i);
        buffer.detach();
    }

    cout << "[main]: created threads. press return to exit.";
    string test;
    getline(cin, test);

    //on = false;

    usleep(2000);


    return 0;
}