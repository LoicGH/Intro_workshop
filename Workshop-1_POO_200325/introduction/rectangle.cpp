#include <iostream>
using namespace std;

class Circle {
    double radius;
    public:
        Circle(double r) {radius = r;}
        double area() {return 3.14159*radius*radius;}
};
class Rectangle {
    int width, height;
    public:
        Rectangle (int,int);
        int area() {return width*height;}
};

Rectangle::Rectangle (int x, int y){
    width = x;
    height = y;
}

int main() {
    Rectangle rect (3,4);
    cout << "area : " <<rect.area();
    return 0;
};