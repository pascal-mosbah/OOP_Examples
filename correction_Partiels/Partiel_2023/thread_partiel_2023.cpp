#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <cstdlib>


void producer(int &nb, bool &once_again)
{
    while(once_again) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        nb = rand()+1;
    }
}

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
}

int main()
{
    int nb;
    bool once_again = true;
    std::thread producerThread(producer, std::ref(nb), std::ref(once_again));
    std::thread consumerThread(consumer, std::ref(nb), std::ref(once_again));

    //int s;

    //std::cin >> nb;

    producerThread.join();
    consumerThread.join();
    std::cout << std::flush;
    return 0;
}
