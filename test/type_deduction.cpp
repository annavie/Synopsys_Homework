#include<iostream>
#include<ostream>
#include <boost/type_index.hpp>

template <typename T> 
void deduce(T t) 
{ 
 std::cout << "type of T: " << boost::typeindex::type_id_with_cvr<T>().pretty_name() << std::endl; 
 std::cout << "type of t: " << boost::typeindex::type_id_with_cvr<decltype(t)>().pretty_name() << std::endl; 
}
int main() 
{   
    int z = 15;
    int& k = z;
    deduce(42); 
    deduce(k); 
    deduce(z); 
    return 0;
}