#include<stdio.h>
#include <thread>
#include<iostream>
#include <mutex>
std::mutex mutex;
int source = 1;
void task(const char *agr)
{
    std::chrono::milliseconds dura(10);
    for(;;)
    {
        mutex.lock();
        if(source>100)
        {
            mutex.unlock();
            break;
        }
       std::cout  << agr << "  i=" << source++  << " thread ID=" << std::this_thread::get_id() << std::endl;
       mutex.unlock();

       std::this_thread::sleep_for(dura);
    }
}


int main(int argc, char *argv[])
{

    printf("hello,world!\n");

    std::thread threadOne(task, "taskOne");
    std::thread threadTwo(task, "taskTwo");

    threadOne.join();
    threadTwo.join();
}
