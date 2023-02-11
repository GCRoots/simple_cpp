/**
 * Created by 史进 on 2023/1/30.
 *
 * queue 队列：先进先出
 *
 */
#include <iostream>
#include <string>
#include <queue>

using namespace std;

void test01(){
    // 默认构造
    queue<int> s1;

    // 入队
    s1.push(10);
    s1.push(20);
    s1.push(30);
    cout << s1.size() << endl;

    while(!s1.empty()){
        cout << s1.front() << endl;
        cout << s1.back() << endl;
        s1.pop();
    }
    cout << s1.size() << endl;

}



int main() {
    std::cout << "Hello, World!" << std::endl;
    test01();
    return 0;
}
