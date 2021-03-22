#include <iostream>
#include <vector>

using namespace std;


template <typename N>    ///template в STL можно использовать "int, float, double......"
bool compare (N first, N second) {
    return second > first ? true : false;
};

template <typename N>
bool positive_Numbers (N x) {
    return x > 0;
};

//all_of
//возвращает true, если все элементы диапазона удовлетворяют некоторому предикату. Иначе false
template <typename T, typename Function>
bool all_of (const T& begin, const T& end, Function func) {
    for (T iter = begin; iter != end; ++iter) {   ///using "iterator" to access values //Используй итератор для доступа к значениям
        if (!func(*iter)) {
            return false;
        }
    }
    return true;
}

//any_of
//возвращает true, если хотя бы один из элементов диапазона удовлетворяет некоторому предикату. Иначе false
template <typename T, typename Function>
bool any_of (const T& begin, const T& end, Function func) {
    for (T iter = begin; iter != end; ++iter) {
        if (func(*iter)) {
            return true;
        }
    }
    return false;
}

//none_of
//возвращает true, если все элементы диапазона не удовлетворяют некоторому предикату. Иначе false
template <typename T, typename Function>
bool none_of (const T& begin, const T& end, Function func) {
    for (T iter = begin; iter != end; ++iter) {
        if (func(*iter)) {
            return false;
        }
    }
    return true;
}

//one_of 
//возвращает true, если ровно один элемент диапазона удовлетворяет некоторому предикату. Иначе false
template <typename T, typename Function>
bool one_of (const T& begin, const T& end, Function func) {
    int count = 0;
    for (T iter = begin; iter != end; ++iter) {
        if (func(*iter)) {
            ++count;
        }
    }
    return count == 1;
}

//is_sorted 
//возвращает true, если все элементы диапазона находятся в отсортированном порядке относительно некоторого критерия
template <typename T, typename Function>
bool is_sorted (const T& begin, const T& end, Function func) {
    for (T iter = begin; iter != end; ++iter) {
        if (func(*iter, *(iter - 1))) {
           return false;
        }
    }
    return true;
}

//is_partitioned 
//возвращает true, если в диапазоне есть элемент, делящий все элементы на удовлетворяющие и не удовлетворяющие некоторому предикату. Иначе false.
template <typename T, typename Function>
bool is_partitioned (T first, T last, Function func) {
    for (; first != last; ++first) {
        if (!func(*first))
            break;
    }
    for (; first != last; ++first) {
        if (func(*first))
            return false;
    }
    return true;
}
//find_not  
//находит первый элемент, не равный заданному
template <typename T, typename Element>
Element find_not (const T& begin, const T& end, Element elem) {
    for (T iter = begin; iter != end; ++iter) {
        if (*iter != elem) {
            return *iter;
        }
    }
    return *end;
}
//find_backward  
//находит первый элемент; равный заданному; с конца
template <typename T, typename Element>
Element find_backward (const T& begin, const T& end, Element elem) {
    for (T iter = end - 1; iter != begin; --iter) {
        if (elem == *iter) {
            return *iter;
        }
    }
    return *end;

}

//is_palindrome  
//возвращает true, если заданная последовательность является палиндромом относительно некоторого условия. Иначе false.
template <typename T, typename Function>
bool is_palindrome(const T& begin, const T& end, Function function)
{
    T start, finish;
    for (start = begin, finish = end - 1;
         start != end && finish != begin;
         start++, finish--) {

        if (*start != *finish) {
            return false;
        }
    }
    return true;
}

int main () {
    vector <char> vec = {1, 2, 3, 4, 5, 6};

    cout << "all_of : " << (all_of(vec.begin(), vec.end(), positive_Numbers<int>) ? "true" : "false") << endl;
    cout << "any_of : " << (any_of(vec.begin(), vec.end(), positive_Numbers<int>) ? "true" : "false") << endl;
    cout << "none_of : " << (none_of(vec.begin(), vec.end(), positive_Numbers<int>) ? "true" : "false") << endl;
    cout << "one_of : " << (one_of(vec.begin(), vec.end(), positive_Numbers<int>) ? "true" : "false") << endl;
    cout << "is_sorted : " << (is_sorted(vec.begin(), vec.end(), compare<int>) ? "true" : "false") << endl;
    cout << "is_partitioned : " << (is_partitioned(vec.begin(), vec.end(), positive_Numbers<int>) ? "true" : "false") << endl;
    cout << "find_not : " << find_not(vec.begin(), vec.end(), 1) << endl;
    cout << "find_backward : " << find_backward(vec.begin(), vec.end(), 6) << std::endl;
    cout << "is_palindrome : " << (is_palindrome(vec.begin(), vec.end(), positive_Numbers<int>) ? "true" : "false") << endl;

    return 0;
}
