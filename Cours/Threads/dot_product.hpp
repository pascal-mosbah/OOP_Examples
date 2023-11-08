#pragma once

template <typename Iter>
void dot_product(const Iter &v1_begin, const Iter &v1_end, const Iter &v2_begin, 
	typename Iter::value_type &result) {
    Iter iter1 = v1_begin, iter2 = v2_begin;
    while (iter1 != v1_end) {
        result += *iter1 * *iter2;
        ++iter1;
        ++iter2;
    }
}
