#include <iostream>
#include "bufer.h"

int main() {
    circleBuffer circle(10, 0);
    circle.resize(4);
    circle.pushBack(5);
    circle.popBack();
    circle.pushFront(8);
    circle.popFront();
    circle.insert(circle.begin(), 6);

    return 0;
}
