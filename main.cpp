#include <complex.h>

#include "MyVector.h"

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
    MyVector<int> vec;
    
    vec.push_front(5);
    vec.push_front(4);
    vec.push_front(3);
    vec.push_front(2);
    vec.push_front(1);

    for (std::size_t i = 0; i < vec.size(); ++i)
        cout << vec.at(i) << " ";

    vec.erase_if([](std::size_t el){ return el >= 0 && el <= 2; });

    cout << endl;
    for (std::size_t i = 0; i < vec.size(); ++i)
        cout << vec.at(i) << " ";

    
    return 0;
}