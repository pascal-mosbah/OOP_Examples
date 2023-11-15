#include <iostream>
#include <thread>
#include <chrono>

int main() {

	using namespace std::chrono_literals; 
	std::cout << '\n';
	std::cout << std::boolalpha;
	bool stopping = false;
	std::jthread thr(
			[&stopping]{
			while (!stopping) {
			std::this_thread::sleep_for(1s);
			std::cout << "running..." << std::endl; }
			});
	std::cout << "is thr.joinable() ?: " << thr.joinable() << std::endl;
	int a;
	std::cin >> a;
	stopping = true;
	//thr.join();
	std::cout << "is thr.joinable() ?: " << thr.joinable() << std::endl;
}
