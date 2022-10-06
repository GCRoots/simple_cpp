/**
 * Created by 史进 on 2022/9/20.
 *
 * 封装（encapsulution）代码示例
 *
 * C++ 是面向对象的语言，其主要特征是封装（Encapsulation）、继承（Inheritance）和多态（Polymorphism）。
 * C++ 认为，万事万物皆为对象，对象上有其属性和行为。封装，就是将具有相同性质的对象抽象为类（class），并且对类的属性（成员变量）和行为（成员函数）加以权限，以进行控制。
 *
 * 类（class）定义的语法为：
 * class 类名{
 *      访问权限:
 *          属性/行为;
 *          ......
 *  }
 *
 *  1. 封装的意义
 *      1. 将属性和行为作为整体，以此来表现事物
 *      2. 将属性和行为加以权限控制
 *
 *  2. 访问权限
 *      1. 公共权限 public
 *          类内可访问，类外可访问，子类可访问
 *      2. 保护权限 protected
 *          类内可访问，类外不可访问，子类可访问
 *      3. 私有权限 private
 *          类内可访问，类外不可访问，子类不可访问
 *
 *  3.class与struct的区别
 *  class 与 struct 的唯一区别，就在于两者的默认访问权限不同。
 *  class 的默认访问权限为 public
 *  struct 的默认访问权限为 private
 *
 *  4. 成员属性私有化
 *  将成员属性设置为私有（public），有以下两点好处：
 *      1. 可以自己控制读写权限
 *      2. 对于写权限，可以对写入数据的有效性加以检测
 *
 * 代码示例：
 * 设计实例1：立方体类设计与实现
 * 设计实例2：圆类与点类关系的设计与实现
 */
#include <iostream>
using namespace std;

//设计实例1：立方体类设计与实现
class Cube{
public:
    //获取、设置长宽高（get、set方法）
    int getLength() const {
        return length;
    }

    void setLength(int length) {
        this->length = length;
    }

    int getWidth() const {
        return width;
    }

    void setWidth(int width) {
        this->width = width;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int height) {
        this->height = height;
    }

    //获取立方体面积
    int getArea() const{
        return 2*(length*width+length*height+width*height);
    }

    //获取立方体体积
    int getVolumn() const{
        return length*width*height;
    }

    //成员函数 函数 判断两个立方体是否相等
    bool isEqualCube(Cube cube) const{
        return length==cube.getLength() &&
                width==cube.getWidth() &&
                height==cube.getHeight();
    }

private:        //成员属性私有化
    int length; //长度
    int width;  //宽度
    int height; //高度

};

//全局函数 判断两个立方体是否相等
bool isEqualCube(Cube c1,Cube c2){
    return c1.getLength()==c2.getLength() &&
            c1.getWidth()==c2.getWidth() &&
            c1.getHeight()==c2.getHeight();
}

//设计实例2：圆类与点类关系的设计与实现
//点类（Point）
class Point{
public:
    //获取、设置X、Y坐标
    int getX() const {
        return X;
    }

    void setX(int x) {
        X = x;
    }

    int getY() const {
        return Y;
    }

    void setY(int y) {
        Y = y;
    }

private:
    int X;  //X坐标
    int Y;  //Y坐标
};

//园类（Circle）
class Circle{
public:
    int getRadius() const {
        return radius;
    }

    void setRadius(int radius) {
        Circle::radius = radius;
    }

    const Point &getPoint() const {
        return center;
    }

    void setPoint(const Point &point) {
        Circle::center = point;
    }

private:
    int radius;     //半径
    Point center;   //圆心
};

//判断点和圆的关系（点在圆外、点在圆上、点在圆内）
void isInCircle(Circle &c,Point &p){
    //计算两点间距离的平方
    int distance = (c.getPoint().getX()-p.getX())*(c.getPoint().getX()-p.getX()) +
                   (c.getPoint().getY()-p.getY())*(c.getPoint().getY()-p.getY());

    //计算半径的平方
    int rr = c.getRadius()*c.getRadius();

    if (distance>rr) {
        cout<<"点在圆外"<<endl;
    } else if (distance==rr){
        cout<<"点在圆上"<<endl;
    } else {
        cout<<"点在圆内"<<endl;
    }

}


int main() {
    std::cout << "Hello, World!" << std::endl;

    cout<<""<<endl;

    //设计实例1：立方体类设计与实现
    cout<<"设计实例1：立方体类设计与实现"<<endl;
    Cube cube1{};
    cube1.setLength(10);
    cube1.setHeight(10);
    cube1.setWidth(10);

    cout<<"cube1 的面积为："<<cube1.getArea()<<endl;
    cout<<"cube1 的体积为："<<cube1.getVolumn()<<endl;

    Cube cube2{};
    cube2.setLength(10);
    cube2.setHeight(10);
    cube2.setWidth(10);

    cout<<"cube2 的面积为："<<cube2.getArea()<<endl;
    cout<<"cube2 的体积为："<<cube2.getVolumn()<<endl;

    cout<<"全局函数"<<endl;
    cout<<"cube1 与 cube2 是"<< ( isEqualCube(cube1,cube2) ? "相等的" : "不相等的" )<<endl ;
    cout<<"成员函数"<<endl;
    cout<<"cube1 与 cube2 是"<< ( cube1.isEqualCube(cube2) ? "相等的" : "不相等的" )<<endl ;

    cout<<endl;

    //设计实例2：圆类与点类关系的设计与实现
    cout<<"设计实例2：圆类与点类关系的设计与实现"<<endl;
    Circle circle{};
    circle.setRadius(10);
    Point center{};
    center.setX(20);
    center.setY(10);
    circle.setPoint(center);

    Point point{};
    point.setX(20);
    point.setY(10);

    //判断关系
    isInCircle(circle,point);


    return 0;
}








