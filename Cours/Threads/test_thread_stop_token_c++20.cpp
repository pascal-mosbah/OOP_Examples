#include <chrono>
#include <iostream>
#include <thread>

using namespace std::chrono_literals;

void function(std::stop_token stop_token, int count) {
  while (!stop_token.stop_requested()) {
    std::this_thread::sleep_for(1s);
    std::cout << "function running... " << count++ << std::endl;
  }
};

int main() {

  std::cout << '\n';
  std::cout << std::boolalpha;
  int count = 1;
  std::jthread thr([count](std::stop_token stop_token) mutable {
    while (!stop_token.stop_requested()) {
      std::this_thread::sleep_for(1s);
      std::cout << "thr running... " << count++ << std::endl;
    }
    std::cout << "running..." << std::endl;
  });
  std::cout << "is thr.joinable() ?: " << thr.joinable() << std::endl;
  std::cout << "is thr.joinable() ?: " << thr.joinable() << std::endl;

  std::stop_source s_source;
  std::jthread thr1(function, s_source.get_token(), 3);
  int a;
  std::cin >> a;
	s_source.request_stop();
}
