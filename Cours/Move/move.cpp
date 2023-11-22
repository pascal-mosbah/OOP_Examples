#include <memory>
#include <iostream>
#include <chrono>
#include <algorithm>

struct my_count
{
    my_count()
    {
        ++count_;
    }
    static int count_;
};

int my_count::count_ = 0;

template <typename _T>
struct my_struct : my_count
{
    size_t size_;
    std::unique_ptr<_T[]> data_;
    int count_;
    int key_;


    my_struct() : size_(1000), data_(std::make_unique<_T[]>(size_)), count_(my_count::count_), key_(rand())
    {
        // std::cout << "Default constructeur  " << count_ << " size " << size_ << std::endl;
    }

    my_struct(const size_t &size) : size_(size), data_(std::make_unique<_T[]>(size_)), count_(my_count::count_), key_(rand())
    {
        // std::cout << "Constructeur " << count_ << " size " << size_ << std::endl;
    }

    const my_struct &operator=(const my_struct &other)
    {
        data_ = std::make_unique<_T[]>(other.size_);
        size_ = other.size_;
        key_ = other.key_;
        count_ = other.count_;
        std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
        return *this;
    }
    my_struct(const my_struct &other) : size_(other.size_), data_(std::make_unique<_T[]>(other.size_)), count_(my_count::count_), key_(other.key_)
    {
        // std::cout << "Copy " << count_ << " size " << size_ << std::endl;
        std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
    }
    my_struct(my_struct &&other) : size_(other.size_), data_(std::move(other.data_)), count_(my_count::count_), key_(other.key_)
    {
        // std::cout << "Move " << count_ << " size " << size_ << std::endl;
        other.data_ = nullptr;
        other.size_ = 0;
    }
};

template <typename _T>
void my_swap_copy(my_struct<_T> &first, my_struct<_T> &second)
{
    auto tmp = first;
    first = second;
    second = tmp;
}

template <typename _T>
void my_swap_move(my_struct<_T> &first, my_struct<_T> &second)
{
    auto tmp = std::move(first);
    first = std::move(second);
    second = std::move(tmp);
}

template <typename _T, typename swap_type>
void my_sort(std::unique_ptr<_T> &tab, const size_t &size, swap_type my_swap)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i + 1; j < size; j++)
        {
            if (tab[j].key_ < tab[i].key_)
            {
                my_swap(tab[j], tab[i]);
            }
        }
    }
}

/* int main()
{
    my_struct<int> s1;
    my_struct<int> s2(10);
    auto s3 = s1;
    auto s4 = std::move(s2);
    auto s5 = std::make_unique<my_struct<int>>(20);
    auto s6 = std::move(s5); // s6 = s5

    return EXIT_SUCCESS;
} */

int main()
{
    srand((unsigned)time(NULL));
    const int size = 10000;

    auto s = std::make_unique<my_struct<int>[]>(size);
    auto sp = std::make_unique<my_struct<int>[]>(size);
    std::copy(s.get(), s.get() + size, sp.get());

    auto start = std::chrono::high_resolution_clock::now();
    my_sort(s, size, my_swap_copy<int>);
    std::chrono::duration<double> elapsed =
        std::chrono::high_resolution_clock::now() - start;
    std::cout << "Temps : " << elapsed.count() << " s\n";
    start = std::chrono::high_resolution_clock::now();
    my_sort(sp, size, my_swap_move<int>);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    std::cout << "Temps : " << elapsed.count() << " s\n";
}