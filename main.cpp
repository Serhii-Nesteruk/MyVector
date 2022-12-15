#include <complex.h>

#include "MyVector.h"

#include <iostream>
#include <vector>

using namespace std;

struct Car{
    Car(){};
    explicit Car(int speed) : speed(speed) {};
    int speed = 0;
};

void func(Car car)
{
    cout << car.speed << endl;
}

int main(int argc, char* argv[])
{
    Car car;
    MyVector<Car> vec;
    vec.push_front(Car(5));
    vec.push_front(Car(15));
    vec.push_front(Car(25));
    vec.push_front(Car(35));
    vec.push_front(Car(45));
    vec.push_front(Car(55));

    for (std::size_t i = 0; i < vec.size(); ++i)
        cout << vec.at(i).speed << " ";
    cout << endl;
    
    vec.erase(1, 3);

    for (std::size_t i = 0; i < vec.size(); ++i)
        cout << vec.at(i).speed << " ";
    cout << endl;
    
    return 0;
}