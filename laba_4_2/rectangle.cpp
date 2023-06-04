#include <iostream>
#include "rectangle.h"

double rectangle::square(){
    return side1 * side2;
}
double rectangle::perimeter() {
    return (side1 + side2) * 2;
}

double rectangle::mass() const {
    return massObj;
}
CVector2D rectangle::position() {
    return positionXY;
}
bool rectangle::operator ==(const IPhysObject& ob) const {
    return this->mass() == ob.mass();
}
bool rectangle :: operator <(const IPhysObject& ob) const {
    return this->mass() < ob.mass();
}
void rectangle::draw() {
    std::cout << "\nsquare: " << square();
    std::cout << "\nperimeter: " << perimeter();
    std::cout << "\nmass: " << massObj;
    std::cout << "\npositionX, positionY: " << positionXY.x << ", " << positionXY.y << '\n';
}
void rectangle::initFromDialog() {
    std::cout << "side1: "; std::cin >> side1;
    std::cout << "side2: "; std::cin >> side2;
    std::cout << "mass: "; std::cin >> massObj;
    std::cout << "positionX: "; std::cin >> positionXY.x;
    std::cout << "positionY: "; std::cin >> positionXY.y;
}
const char* rectangle::classname() {
    return name;
}
unsigned int rectangle::size(){
    return sizeof (rectangle);
}
