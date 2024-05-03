#include<iostream>
#include<vector>

template<typename T>
void merge(std::vector<T>& V, typename std::vector<T>::iterator l, typename std::vector<T>::iterator m,typename std::vector<T>::iterator h) {
    std::vector<T> left(l, m);
    std::vector<T> right(m, h);
    typename std::vector<T>::iterator left_iter = left.begin();
    typename std::vector<T>::iterator right_iter = right.begin();
    typename std::vector<T>::iterator result = l;

    while(left_iter != left.end() && right_iter != right.end()) {
        if(*left_iter <= * right_iter) {
            *result = *left_iter;
            ++left_iter;
        } else {
            *result = *right_iter;
            ++right_iter;
        }
        ++result;
    }
    while(left_iter != left.end()) {
        *result =  *left_iter;
        ++left_iter;
        ++result;
    }
    while(right_iter != right.end()) {
        *result =  *right_iter;
        ++right_iter;
        ++result;
    }
}
template<typename T>
void mergeSort(std::vector<T> & V, typename std::vector<T>::iterator l,typename std::vector<T>::iterator h ) {
    if(std::distance(l, h) > 1) {
        auto m = l + std::distance(l, h) / 2;
        mergeSort(V,l,m);
        mergeSort(V, m , h);
        merge(V, l , m , h);
    }
}
int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    std::cout << "Given array is \n";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    mergeSort(arr, arr.begin(), arr.end());

    std::cout << "Sorted array is \n";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
