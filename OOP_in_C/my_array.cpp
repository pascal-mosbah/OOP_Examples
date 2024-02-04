#include <stdlib.h>
#include <my_array.hpp>

My_array_in_C allocate_my_array()
{
    My_array_in_C array;
    array.size = 0;
    array.capacity = _SIZE_INIT_;
    array.tab = (int *)malloc(array.capacity * sizeof(int));
    return array;
}


My_array_in_cpp::My_array_in_cpp() : tab_(new int[_SIZE_INIT_])
{
}
