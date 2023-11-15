#include <iostream>
#include <thread>
#include <chrono>

int main() {

	using namespace std::chrono_literals; 
	std::cout << '\n';
	std::cout << std::boolalpha;
	std::thread thr(
			[]{ 
			std::this_thread::sleep_for(1s);
			std::cout<<"End std::thread "<<std::endl;});

	std::this_thread::sleep_for(2s);
	std::cout << "is thr.joinable() ?: " << thr.joinable() << std::endl;
	thr.join();
	std::cout << "is thr.joinable() ?: " << thr.joinable() << std::endl;
}
