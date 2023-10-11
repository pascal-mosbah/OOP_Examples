#include <cstdlib>
#include <cstring>
#include <iostream>
#include <chrono>

using namespace std;

void my_allocation(int *&ptr, const size_t &old_size, const size_t &new_size)
{
    if (ptr)
    {
        auto new_ptr = new int[new_size];
        memcpy(new_ptr, ptr, old_size * sizeof(int));
        delete[] ptr;
        ptr = new_ptr;
    }
    else
    {
        ptr = new int[new_size];
    }
}

void my_allocation_using_C(int *&ptr, const size_t &new_size)
{
    static unsigned count = 1;
    if (ptr)
    {
        auto old_ptr = ptr;
        ptr = static_cast<int *>(realloc(ptr, new_size * sizeof(int)));
        if (!ptr)
        {
            throw "Bad allocation using malloc";
        }
        if (old_ptr != ptr)
        {
            cout << "Pointer address has changed at iteration : " << count << endl;
        }
    }
    else
    {
        ptr = static_cast<int *>(malloc(new_size * sizeof(int)));
    }
    ++count;
}


int main()
{
    const size_t increment = 1 << 4;
    cout << increment << endl;
    int *tab_int = nullptr;
    int *tab_int_using_C = nullptr;
    size_t size = increment, initial_size = 0;
    auto time_start = chrono::high_resolution_clock::now();
    try
    {
        for (auto i = 0; i < 100; ++i)
        {
            my_allocation(tab_int, initial_size, size);
            initial_size = size;
            size += increment;
        }
    }
    catch (const bad_alloc &e)
    {

        cout << "Memory Allocation"
             << e.what()
             << endl;
    }

    auto time_end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    std::cout << duration.count() << " microseconds(s) for new" << endl;

    delete[] tab_int;

    size = 0;
    time_start = chrono::high_resolution_clock::now();
    for (auto i = 0; i < 100; ++i)
    {
        my_allocation_using_C(tab_int_using_C, size);
        size += increment;
    }
    time_end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(time_end - time_start);
    std::cout << duration.count() << " microseconds(s) for realloc" << endl;
    free(tab_int_using_C);
}
