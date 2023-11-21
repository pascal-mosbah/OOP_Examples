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
    int key_;
    size_t size_;
    std::unique_ptr<_T> data_;

    my_struct() : data_(std::make_unique<_T>(size_)), size_(100), count_(my_count::count_), key_(rand())
    {
    }

    const my_struct &operator=(const my_struct &other)
    {
        data_ = std::make_unique<_T>(other.size_);
        size_ = other.size_;
        key_ = other.key_;
        copy(other.data_.get(), other.data_.get() + size_, data_.get());
        return *this;
    }
    my_struct(const my_struct &other) : data_(std::make_unique<_T>(size_)), size_(other.size_), count_(my_count::count_)
    {
        std::cout << "Copy " << count_ << " " << size_ << std::endl;
        data_ = new int[other.size_];
        size_ = other.size_;
        copy(other.data_, other.data_ + size_, data_);
    }
    my_struct(my_struct &&other) : data_(other.data_), size_(other.size_), count_(my_count::count_)
    {
        std::cout << "Move " << count_ << " " << size_ << std::endl;
        data_ = other.data_;
        size_ = other.size_;
        other.data_ = nullptr;
        other.size_ = 0;
    }
};

template<typename _T>
void my_swap_copy(my_struct<_T> &first, my_struct<_T> &second)
{
    auto tmp = first;
    first = second;
    second = tmp;
}

template<typename _T>
void my_swap_move(my_struct<_T> &first, my_struct<_T> &second)
{
    auto tmp = std::move(first);
    first = std::move(second);
    second = std::move(tmp);
}

template <typename _T, typename swap_type>
void my_sort(my_struct<_T> *tab, const size_t &size, swap_type my_swap)
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

int main()
{
    srand((unsigned)time(NULL));
    int size = 20;
    auto s = new my_struct<int>[size];
    auto sp = new my_struct<int>[size];
    std::copy(s, s + size, sp);

    auto start = std::chrono::high_resolution_clock::now();
    my_sort(s, size, my_swap_copy);
    std::chrono::duration<double> elapsed =
        std::chrono::high_resolution_clock::now() - start;
    std::std::cout << "Temps : " << elapsed.count() << " s\n";
    start = std::chrono::high_resolution_clock::now();
    my_sort(sp, size, my_swap_move);
    elapsed = std::chrono::high_resolution_clock::now() - start;
    std::stcout << "Temps : " << elapsed.count() << " s\n";
}