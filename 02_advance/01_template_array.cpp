/**
 * Created by 史进 on 2023/1/25.
 *
 * 类模版案例：通用数组类
 *
 */
#include <iostream>
#include <string>
#include "01_template_array.hpp"

using namespace std;

int main() {
    MyArray<int> array(10);
    array.toString();
    cout << "Capacity:" << array.getCapacity() << endl;
    cout << "Size:" << array.getSize() << endl;

    for (int i = 0; i < 10; ++i) {
        array.push_back(i);
    }
    array.toString();
    cout << "Capacity:" << array.getCapacity() << endl;
    cout << "Size:" << array.getSize() << endl;

    MyArray<int> array2(20);
    for (int i = 0; i < 20; ++i) {
        array2.push_back( i*2 );
    }
    array2.toString();
    cout << "Capacity:" << array2.getCapacity() << endl;
    cout << "Size:" << array2.getSize() << endl;

    array = array2;
    array.toString();
    cout << "Capacity:" << array.getCapacity() << endl;
    cout << "Size:" << array.getSize() << endl;


    return 0;
}