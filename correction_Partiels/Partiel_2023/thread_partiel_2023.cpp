#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <cstdlib>

std::mutex m;

// void producer(std::queue<int> &queue)
void producer(int &nb, bool &once_again)
{
    while(once_again) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        nb = rand()+1;
    }
    // for (int i = 0; i < 10; ++i)
    // {
    //     m.lock();
    //     queue.push(i);
    //     m.unlock();
    //     std::cout << "Producer: Added task " << i << std::endl;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(100));
    // }
}

// void consumer(std::queue<int> &queue)
void consumer(int &nb, bool &once_again)
{
    while(once_again){
        if (nb){
            std::cout<<"Received : "<<nb<<std::endl;
	    if (nb == 10){
	    	once_again = false;
	    }
            nb = 0;
        }
    }
    // while (!queue.empty())
    // {
    //     m.lock();
    //     int task = queue.front();
    //     queue.pop();
    //     m.unlock();
    //     std::cout << "Consumer: Processed task " << task << std::endl
    //               << std::flush;
    //     std::this_thread::sleep_for(std::chrono::milliseconds(110));
    // }
    // std::cout << "Consumer: End processing" << std::endl
    //           << std::flush;
}

int main()
{
    // std::queue<int> queue;
    // std::thread producerThread(producer, ref(queue));
    // std::thread consumerThread(consumer, ref(queue));

    int nb;
    bool once_again = true;
    std::thread producerThread(producer, std::ref(nb), std::ref(once_again));
    std::thread consumerThread(consumer, std::ref(nb), std::ref(once_again));

    int s;

    std::cin >> nb;

    producerThread.join();
    // std::this_thread::sleep_for(std::chrono::seconds(10));
    consumerThread.join();
    std::cout << std::flush;
    return 0;
}
