#include <iostream>
#include "ellipse.h"

double ellipse::square() {
    return 3.14 * smallRadius * bigRadius;
}
double ellipse::perimeter() {
    return 4 * ((3.14 * smallRadius * bigRadius + (smallRadius - bigRadius)) / (smallRadius - bigRadius));
}
double ellipse::mass() const {
    return massObj;
}
CVector2D ellipse::position() {
    return positionXY;
}
bool ellipse::operator == (const IPhysObject& ob) const {
    return this->mass() == ob.mass();
}
bool ellipse::operator < (const IPhysObject& ob) const {
    return this->mass() < ob.mass();
}
void ellipse::draw() {
    std::cout << "\nsquare: " << square();
    std::cout << "\nperimeter: " << perimeter();
    std::cout << "\nmass: " << massObj;
    std::cout << "\npositionX, positionY: " << positionXY.x << ", " << positionXY.y << '\n';
}
void ellipse ::initFromDialog() {
    std::cout << "small radius: ";
    std::cin >> smallRadius;
    std::cout << "big radius: ";
    std::cin >> bigRadius;
    std::cout << "mass: ";
    std::cin >> massObj;
    std::cout << "position: ";
    std::cin >> positionXY.x;
    std::cout << "positionY: ";
    std::cin >> positionXY.y;
}
const char* ellipse::classname() {
    return name;
}
unsigned int ellipse::size() {
    return sizeof(ellipse);
}