#include <iostream>

class Shape {
public:
    Shape (float, float);
protected:
    float height;
    float width;
};

Shape::Shape(float w, float h){
    if (w < 0) w = -w;
    if (h < 0) h = -h;
    height = h; 
    width = w;
}

class Triangle: public Shape{
public:
    Triangle (float, float);
    float Area();
};

Triangle::Triangle(float w, float h): Shape::Shape(w, h){

}

float Triangle::Area(){
    return 0.5*height*width;
}

class Rectangle: public Shape {
public:
    Rectangle(float, float);
    float Area();
};

Rectangle::Rectangle(float w, float h): Shape::Shape(w, h){

}

float Rectangle::Area(){
    return height*width;
}

int main (int argc, char *argv[]) {
    Triangle A = Triangle(4, 3);
    Rectangle B = Rectangle(4, 3);
    std::cout << A.Area() << "\n" << B.Area() << "\n";
    return 0;
}
