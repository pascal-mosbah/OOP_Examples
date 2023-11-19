#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;
int main()
{
	std::cout << std::boolalpha;
	std::jthread thr(
		[]
		{
			std::this_thread::sleep_for(1s);
			std::cout << "End std::jthread " << std::endl;
		});

	std::this_thread::sleep_for(2s);
	std::cout << "is thr.joinable() ?: " << thr.joinable() << '\n';
}
