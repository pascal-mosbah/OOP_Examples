#include <stdlib.h>

#define _SIZE_INIT_ 10
#define _SIZE_TO_ADD_ _SIZE_INIT_

struct My_array_in_C{
    int *tab;
    size_t size;
    size_t capacity;
};

void set_an_element(My_array_in_C *my_array,int elem);


class My_array_in_cpp{
    private:
    int *tab_;
    size_t capacity_;
    size_t size_;
    size_t capacity_;
    public:
    My_array_in_cpp();
    size_t get_size();
    void set_an_element(int elem);
    void get_an_element(int elem);
};