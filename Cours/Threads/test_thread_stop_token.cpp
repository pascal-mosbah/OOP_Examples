#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;
int main()
{
	std::cout << std::boolalpha;
	bool stopping = false;
	std::jthread thr(
		[&stopping]
		{
			int count = 1;
			while (!stopping)
			{
				std::this_thread::sleep_for(1s);
				std::cout << "running... " << count++ << std::endl;
			}
		});
	std::cout << "is thr.joinable() ?: " << thr.joinable() << std::endl;
	int a;
	std::cin >> a;
	stopping = true;
	thr.join();
	std::cout << "is thr.joinable() ?: " << thr.joinable() << std::endl;
}
