#include <iostream>
int main() {
    const int k = 5;
    auto&& t = k;
    const int& x = k;
    return 0;
}
