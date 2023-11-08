#include <chrono>
#include <execution>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>
#include <cassert>
#include <omp.h>

#include "mkl.h"

#include "dot_product.hpp"


using namespace std;



double dot_product(const vector<double> &v1, const vector<double> &v2){
    size_t n = v1.size();
    assert(n == v2.size());
    int one = 1;
    return cblas_ddot(n, &v1.front(), one, &v2.front(), one);
}


int main() {
  constexpr size_t nb_elems = 500000;
  constexpr size_t nb_iter = 10;

  typedef double T;

  vector<T> va1(nb_elems), va2(nb_elems);
  T incr = 1. / static_cast<T>(nb_elems);
  for (size_t i = 0; i < nb_elems; ++i)
    va1[i] = static_cast<T>(i) * incr;
  for (size_t i = 0; i < nb_elems; ++i)
    va2[i] = static_cast<T>(nb_elems - i) * incr;

  auto start = chrono::high_resolution_clock::now();

  T result_global = static_cast<T>(0);
  for (size_t i = 0; i < nb_iter; ++i) {
    T result = static_cast<T>(0);
    dot_product(va1.begin(), va1.end(), va2.begin(), result);
    result_global += result;
  }
  cout << "Time taken by function (dot_product): "
       << chrono::duration_cast<chrono::microseconds>(
              chrono::high_resolution_clock::now() - start)
              .count()
       << " microseconds" << endl
       << flush;

  start = chrono::high_resolution_clock::now();

  T result1_global = static_cast<T>(0);

  for (size_t i = 0; i < nb_iter; ++i) {
    T result1 =
        inner_product(va1.begin(), va1.end(), va2.begin(), static_cast<T>(0));
    result1_global += result1;
  }

  cout << "Time taken by function (inner_product): "
       << chrono::duration_cast<chrono::microseconds>(
              chrono::high_resolution_clock::now() - start)
              .count()
       << " microseconds" << endl
       << flush;

  start = chrono::high_resolution_clock::now();

  T result2_global = static_cast<T>(0);
  for (size_t i = 0; i < nb_iter; ++i) {
    T result2 = std::transform_reduce(
        std::execution::seq, va1.cbegin(), va1.cend(), va2.cbegin(), .0,
        std::plus<T>(), std::multiplies<T>()); // equivalent to inner_product
    result2_global += result2;
  }

  cout << "Time taken by function (transform_reduce): "
       << chrono::duration_cast<chrono::microseconds>(
              chrono::high_resolution_clock::now() - start)
              .count()
       << " microseconds" << endl
       << flush;

  start = chrono::high_resolution_clock::now();
  T result3_global = static_cast<T>(0);

  for (size_t i = 0; i < nb_iter; ++i) {
    T result3 = std::transform_reduce(execution::par, va1.cbegin(), va1.cend(),
                                      va2.cbegin(), .0, std::plus<T>(),
                                      std::multiplies<T>());

    result3_global += result3;
  }
  cout << "Time taken by function (transform_reduce parallel): "
       << chrono::duration_cast<chrono::microseconds>(
              chrono::high_resolution_clock::now() - start)
              .count()
       << " microseconds" << endl
       << flush;

  constexpr size_t nb_threads = 4;

  start = chrono::high_resolution_clock::now();
  T result4_global = static_cast<T>(0);
  array<thread, nb_threads> threads;
  array<T, nb_threads> results;
  for (size_t i = 0; i < nb_iter; ++i) {
    T result4 = static_cast<T>(0);
    size_t range = nb_elems / nb_threads;
    size_t lower_bound = 0, upper_bound = 0;
    for (size_t i = 0; i < nb_threads; ++i) {
      results[i] = 0;
      upper_bound = lower_bound + range;
      if (i == nb_threads - 1) {
        upper_bound = nb_elems;
      }
      threads[i] = thread(dot_product<vector<T>::iterator>,
                          va1.begin() + lower_bound, va1.begin() + upper_bound,
                          va2.begin() + lower_bound, ref(results[i]));
      lower_bound += range;
    }
    for (size_t i = 0; i < nb_threads; ++i) {
      threads[i].join();
    }
    for (size_t i = 0; i < nb_threads; ++i) {
      result4 += results[i];
    }
    result4_global += result4;
  }
  cout << "Time taken by function (threads): "
       << chrono::duration_cast<chrono::microseconds>(
              chrono::high_resolution_clock::now() - start)
              .count()
       << " microseconds" << endl
       << flush;

       start = chrono::high_resolution_clock::now();
    auto start_omp = omp_get_wtime();

    cout<<"Number of threads max (OpenMP) = "<<omp_get_max_threads()<<endl;
    T result5_global = static_cast<T>(0);
    for (size_t i = 0; i < nb_iter;++i) {
        T result5 = 0;

   #pragma omp parallel for default(none) \
        shared(va1,va2) reduction(+:result5)
        for (size_t i = 0; i < va1.size(); i++) {
            result5 += va1[i] * va2[i];
        }
        result5_global += result5;
    }

    auto end_omp = omp_get_wtime();

    cout << "Time taken by function (OpenMP): "<< end_omp - start_omp << "sec.\n";

    cout << "Time taken by function (OpenMP parallel for): "
 << chrono::duration_cast<chrono::microseconds>(chrono::high_resolution_clock::now() -
    start).count() << " microseconds" << endl << flush;

start = chrono::high_resolution_clock::now();

    T result6_global = static_cast<T>(0);
    for (size_t i = 0; i < nb_iter;++i) {

        T result6 = dot_product(va1, va2);

        result6_global += result6;
    }
    cout << "Time taken by function blas: "
        << chrono::duration_cast<chrono::microseconds>
    (chrono::high_resolution_clock::now() - start).count() << " microseconds" << endl << flush;



  return EXIT_SUCCESS;
}