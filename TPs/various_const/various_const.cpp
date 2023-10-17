#include <chrono>
#include <iostream>

consteval 
// constexpr
    long long unsigned
    factorial(const long long unsigned &n) {
  return n <= 1 ? 1 : (n * factorial(n - 1));
}

int main() {

  long long unsigned total;
  auto time_start = std::chrono::high_resolution_clock::now();
  for (int iter_total = 0; iter_total < 100000; ++iter_total) {
    total = 0;
    for (int iter = 0; iter < 1000; ++iter) {
    const long long unsigned n = 60;
//       long long unsigned n = 60;
      total += factorial(n);
    }
  }
  auto time_end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(time_end - time_start);

  std::cout << duration.count() << " microseconds(s) for new" << std::endl;
  std::cout << "Factorial total " << total << std::endl;
  
  return 0;
}
