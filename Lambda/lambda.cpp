#include <iostream>
#include <utility> // for std::forward

class __lambda_esim_inch {
public:
    template <typename T, typename U>
    auto operator()(T&& first, U&& second) {
        return std::forward<T>(first) + std::forward<U>(second);
    }

    template <typename T, typename U>
    void capture(T&& first, U&& second) {
        captured_first = std::forward<T>(first);
        captured_second = &std::forward<U>(second);
    }

private:
    int captured_first;
    int* captured_second;
};
int main()
{
    int x = 4;
    int z = 7;

    //the above class is almost generated for this function
    auto y = [x,&z](auto first, auto second)
    {
        return first + second;
    };
    __lambda_esim_inch l;
    l.capture(x, z);

    std::cout << "Result of lambda function: " << l(7, 4) << std::endl;


    return 0;
}