#include <iostream>
#include "main.h"

Square::Square(float x, float y, float side, float corner){
    this->x = x;
    this->y = y;
    this->side = side;
    this->corner = corner;
}

bool Square::operator == (Square& t) const{
    return side * side == t.side * t.side;
}
bool Square::operator > (Square& t) const{
    return side * side > t.side * t.side;
}
bool Square::operator < (Square& t) const{
    return side * side < t.side * t.side;
}
bool Square::operator >= (Square& t) const{
    return side * side > t.side * t.side;
}
bool Square::operator <= (Square& t) const{
    return side * side < t.side * t.side;
}

Square Square::operator* (float t){
    side *= t;
    return *this;
}

Square Square::operator+ (const float t[2]) const{
    Square newSquare(this->x, this->y, this->side, this->corner);
    newSquare.x += t[0];
    newSquare.y += t[1];
    return newSquare;
}

void Square::getSquare() const {
    std::cout << "x: " << x << ", y: "<< y << "\n";
    std::cout << "side: " << side << ", corner: " << corner << ", square: " << side * side << "\n";
}

stack::stack(int t) {
    arr = new int[t];
    end = 0;
    size = 0;
    sizeMax = t;
}

stack* stack::operator<<(int t) {
    if (end >= sizeMax) {
        throw std::out_of_range("out of range");
    }
    arr[end] = t;
    ++end;
    ++size;
    return this;
}
void stack::operator>>(int &t) {
    if(size <= 0){
        throw std::out_of_range("stack is empty");
    }
    --end;
    --size;
    t = arr[size];
}
void stack::print() {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }
}

void checkStack(){
    std::cout << "class stack: \n";
    stack myStack(10);
    int t = 0;
    for(int i = 0; i< 10; ++i) {
        myStack << i;
    }
    myStack.print();
    std::cout << '\n';

    myStack >> t;

    myStack.print();
    std::cout << '\n';
    std::cout << t << '\n';
}

void checkSquare() {
    std::cout << "class square: \n";
    Square mySquare1(1, 1, 5, 45);
    Square mySquare2(10, 10, 5, 50);
    if (mySquare1 <= mySquare2) {
        std::cout << "mySquare1 == mySquare2\n";
    }
    mySquare2 = mySquare2 * 2;
    if (mySquare1 < mySquare2) {
        std::cout << "mySquare1 < mySquare2\n";
    }
    float cord[2];
    cord[0] = 1.5;
    cord[1] = 4.5;
    mySquare1 = mySquare2 + cord;
    mySquare1.getSquare();
}

int main() {
    checkStack();
    checkSquare();
    return 0;
}