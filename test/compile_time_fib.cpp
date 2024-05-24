#include <iostream>
template<int N>
struct Fibonacci {
    static const int value = Fibonacci<N-1>::value + Fibonacci<N-2>::value;
};
template<>
struct Fibonacci<0> {
    static const int value = 0;
};
template<>
struct Fibonacci<1> {
    static const int value = 1;
};
/// //// or

// constexpr int Fibonacci(int n) {
//     if constexpr (n <= 1) {
//         return n;
//     } else {
//         return Fibonacci(n - 1) + Fibonacci(n - 2);
//     }
// }

int main() {
    std::cout << "Fibonacci<0>::value = " << Fibonacci<0>::value << std::endl;
 
}